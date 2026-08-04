import("core.base.option")
import("exercise_catalog", {rootdir = os.scriptdir()})

local function _required_option(name, preserveWhitespace)
    local value = option.get(name)
    if not value or string.trim(value) == "" then
        raise("--%s is required", name)
    end
    return preserveWhitespace and value or string.trim(value)
end

local function _optional_option(name)
    local value = option.get(name)
    return value and string.trim(value) or ""
end

local function _cpp_string(value)
    return value:gsub("\\", "\\\\"):gsub('"', '\\"'):gsub("\r", "\\r"):gsub("\n", "\\n")
end

local function _header_template(namespaceName, url)
    local reference = url ~= "" and string.format("// refs : %s\n", url) or ""
    return string.format([[%s#pragma once

namespace %s
{

	// Keep the interface native to the Exercise. Examples:
	// class Solution { public: ReturnType Method(Arguments...); };
	// class LRUCache { public: explicit LRUCache(int capacity); /* ... */ };
	// ReturnType FunctionName(Arguments...);

} // namespace %s
]], reference, namespaceName, namespaceName)
end

local function _source_template(namespaceName, slug)
    return string.format([[#include "%s.h"

namespace %s
{

	// Implement the public interface declared in %s.h.

} // namespace %s
]], slug, namespaceName, slug, namespaceName)
end

local function _test_template(namespaceName, displayName, tags, slug)
    return string.format([[#include "%s.h"

#include <catch2/catch_test_macros.hpp>

namespace %s
{

	TEST_CASE("%s", "%s")
	{
		// Arrange inputs and invoke the Exercise's native public interface here.
		FAIL("Replace scaffold example with real assertions");
	}

} // namespace %s
]], slug, namespaceName, _cpp_string(displayName), tags, namespaceName)
end

function main()
    local kind = _required_option("kind"):lower()
    local rawRoot = _required_option("root")
    local rawSlug = _required_option("slug", true)
    if kind ~= "problem" and kind ~= "template" then
        raise("--kind must be problem or template")
    end

    local projectDir = os.projectdir()
    local rootDir, relativeRoot, _, domain = exercise_catalog.resolve_root(projectDir, rawRoot)
    local slug = exercise_catalog.normalize_slug(rawSlug)
    local difficulty = exercise_catalog.normalize_difficulty(option.get("difficulty"))
    local tip = _optional_option("tip")
    local url = exercise_catalog.validate_url(option.get("url"))
    local name = _optional_option("name")
    if name == "" then
        name = exercise_catalog.humanize(slug)
    end

    local exercise = {kind = kind, difficulty = difficulty, name = name, tip = tip, url = url}
    if kind == "problem" then
        exercise.id = exercise_catalog.normalize_problem_id(_required_option("id"))
        exercise.identity = exercise.id
        exercise.directoryName = exercise.id:lower() .. "_" .. slug
    else
        if option.get("id") then
            raise("--id is only valid for Problem Exercises")
        end
        exercise.identity = exercise_catalog.pascal_case(slug)
        exercise.id = domain.metadataPrefix .. "." .. exercise.identity
        exercise.directoryName = domain.targetPrefix .. "_" .. slug
    end
    exercise.namespaceName = string.format("AlgoCpp::%s::%s::%s",
        kind == "problem" and "Problem" or "Template", domain.namespace, exercise.identity)

    local relativeParent = relativeRoot:match("^[^/]+/(.+)$") or ""
    local tags = {kind, domain.tag}
    if relativeParent ~= "" then
        for category in relativeParent:gmatch("[^/]+") do
            table.insert(tags, category)
        end
    end
    if kind == "problem" then
        table.insert(tags, exercise.id:lower())
    else
        table.insert(tags, slug)
    end
    exercise.tags = "[" .. table.concat(tags, "][") .. "]"

    exercise_catalog.scan(projectDir)
    exercise_catalog.index_contents(projectDir)
    exercise_catalog.check_new_collision(projectDir, exercise.directoryName, exercise.id)

    local exerciseDir = path.join(rootDir, exercise.directoryName)
    if os.exists(exerciseDir) then
        raise("destination already exists: %s", path.join(relativeRoot, exercise.directoryName))
    end

    local readmePath = path.join(projectDir, "README.md")
    local originalReadme = assert(io.readfile(readmePath))
    local ok, errors = try {
        function ()
            os.mkdir(exerciseDir)
            io.writefile(path.join(exerciseDir, slug .. ".h"), _header_template(exercise.namespaceName, url))
            io.writefile(path.join(exerciseDir, slug .. ".cpp"), _source_template(exercise.namespaceName, slug))
            io.writefile(path.join(exerciseDir, slug .. "_test.cpp"),
                _test_template(exercise.namespaceName, exercise.id .. " " .. name, exercise.tags, slug))
            io.writefile(path.join(exerciseDir, "exercise.json"), exercise_catalog.metadata_json(exercise))
            exercise_catalog.update_index(projectDir, false)
            return true
        end,
        catch {
            function (caught)
                return false, caught
            end
        }
    }
    if not ok then
        os.tryrm(exerciseDir)
        io.writefile(readmePath, originalReadme)
        raise("cannot create Exercise transactionally: %s", errors)
    end

    if slug ~= rawSlug then
        cprint("${yellow}normalized slug:${clear} %s -> %s", rawSlug, slug)
    end
    local rawId = option.get("id")
    if kind == "problem" and rawId ~= exercise.id then
        cprint("${yellow}normalized id:${clear} %s -> %s", rawId, exercise.id)
    end
    local rawDifficulty = option.get("difficulty")
    if rawDifficulty and string.trim(rawDifficulty) ~= difficulty then
        cprint("${yellow}normalized difficulty:${clear} %s -> %s", rawDifficulty, difficulty)
    end
    cprint("${green}created Exercise:${clear} %s", path.join(relativeRoot, exercise.directoryName))
    cprint("${dim}target:${clear} %s", exercise.directoryName)
    cprint("${dim}namespace:${clear} %s", exercise.namespaceName)
end
