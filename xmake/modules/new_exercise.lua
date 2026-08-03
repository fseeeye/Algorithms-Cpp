import("core.base.option")

local _allowedRoots = {"algorithms", "reviews", "data_structures"}
local _domains = {
    algorithm = {namespace = "Algorithm", prefix = "algo"},
    data_structure = {namespace = "DataStructure", prefix = "ds"}
}

function _require_option(name, preserveWhitespace)
    local value = option.get(name)
    if not value or string.trim(value) == "" then
        raise("--%s is required", name)
    end
    return preserveWhitespace and value or string.trim(value)
end

function _normalize_slug(rawSlug)
    if rawSlug:find("[/\\]") or rawSlug:find("%.%.") then
        raise("unsafe slug '%s': path separators and '..' are not allowed", rawSlug)
    end
    if rawSlug:find("[^A-Za-z0-9 _%-]") then
        raise("unsafe slug '%s': use letters, digits, spaces, '-' or '_'", rawSlug)
    end

    local slug = rawSlug:gsub("(%u+)(%u%l)", "%1_%2")
    slug = slug:gsub("(%l)(%u)", "%1_%2")
    slug = slug:gsub("(%d)(%u)", "%1_%2")
    slug = slug:gsub("[ _%-]+", "_"):lower()
    slug = slug:gsub("^_+", ""):gsub("_+$", "")
    if slug == "" then
        raise("--slug must contain at least one letter or digit")
    end
    return slug
end

function _pascal_case(slug)
    local identity = slug:gsub("^%l", string.upper)
    return identity:gsub("_(%l)", string.upper)
end

function _relative_root(projectDir, rawRoot)
    local absoluteRoot = path.absolute(rawRoot, projectDir)
    local relativeRoot = path.relative(absoluteRoot, projectDir):gsub("\\", "/")
    local comparableRoot = relativeRoot:lower()

    for _, allowedRoot in ipairs(_allowedRoots) do
        if comparableRoot == allowedRoot or comparableRoot:sub(1, #allowedRoot + 1) == allowedRoot .. "/" then
            if not os.isdir(absoluteRoot) then
                raise("--root does not exist or is not a directory: %s", relativeRoot)
            end
            return absoluteRoot, relativeRoot
        end
    end

    raise("--root must be inside algorithms, reviews or data_structures: %s", rawRoot)
end

function _check_collision(projectDir, directoryName, problemId)
    for _, allowedRoot in ipairs(_allowedRoots) do
        local rootDir = path.join(projectDir, allowedRoot)
        for _, directory in ipairs(os.dirs(path.join(rootDir, "**"))) do
            local existingName = path.basename(directory):lower()
            if existingName == directoryName:lower() then
                raise("Exercise target already exists: %s", directoryName)
            end
            if problemId and (existingName == problemId or existingName:sub(1, #problemId + 1) == problemId .. "_") then
                raise("Problem ID already exists: %s", problemId:upper())
            end
        end
    end
end

function _header_template(namespaceName)
    return string.format([[#pragma once

namespace %s
{

	// Keep the interface native to the Exercise. Examples:
	// class Solution { public: ReturnType Method(Arguments...); };
	// class LRUCache { public: explicit LRUCache(int capacity); /* ... */ };
	// ReturnType FunctionName(Arguments...);

} // namespace %s
]], namespaceName, namespaceName)
end

function _source_template(namespaceName, slug)
    return string.format([[#include "%s.h"

namespace %s
{

	// Implement the public interface declared in %s.h.

} // namespace %s
]], slug, namespaceName, slug, namespaceName)
end

function _test_template(namespaceName, displayName, tags, slug)
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
]], slug, namespaceName, displayName, tags, namespaceName)
end

function main()
    local kind = _require_option("kind"):lower()
    local domain = _require_option("domain"):lower()
    local rawRoot = _require_option("root")
    local rawSlug = _require_option("slug", true)

    if kind ~= "problem" and kind ~= "template" then
        raise("--kind must be problem or template")
    end
    local domainInfo = _domains[domain]
    if not domainInfo then
        raise("--domain must be algorithm or data_structure")
    end

    local slug = _normalize_slug(rawSlug)
    local projectDir = os.projectdir()
    local rootDir, relativeRoot = _relative_root(projectDir, rawRoot)
    local exercise = {}

    if kind == "problem" then
        local id = _require_option("id")
        if not id:match("^[A-Z]+[0-9]+$") then
            raise("--id must be a compact uppercase Problem ID such as LC215, HJ02 or LCOF45")
        end
        exercise.problemId = id:lower()
        exercise.directoryName = exercise.problemId .. "_" .. slug
        exercise.namespaceName = "AlgoCpp::Problem::" .. domainInfo.namespace .. "::" .. id
        exercise.displayName = id .. " " .. slug:gsub("_", " ")
        exercise.tags = string.format("[problem][%s][%s]", domain, exercise.problemId)
    else
        if option.get("id") then
            raise("--id is only valid for Problem Exercises")
        end
        local identity = _pascal_case(slug)
        exercise.directoryName = domainInfo.prefix .. "_" .. slug
        exercise.namespaceName = "AlgoCpp::Template::" .. domainInfo.namespace .. "::" .. identity
        exercise.displayName = identity
        exercise.tags = string.format("[template][%s][%s]", domain, slug)
    end

    _check_collision(projectDir, exercise.directoryName, exercise.problemId)
    local exerciseDir = path.join(rootDir, exercise.directoryName)
    if os.exists(exerciseDir) then
        raise("destination already exists: %s", path.join(relativeRoot, exercise.directoryName))
    end

    os.mkdir(exerciseDir)
    io.writefile(path.join(exerciseDir, slug .. ".h"), _header_template(exercise.namespaceName))
    io.writefile(path.join(exerciseDir, slug .. ".cpp"), _source_template(exercise.namespaceName, slug))
    io.writefile(path.join(exerciseDir, slug .. "_test.cpp"),
        _test_template(exercise.namespaceName, exercise.displayName, exercise.tags, slug))

    if slug ~= rawSlug then
        cprint("${yellow}normalized slug:${clear} %s -> %s", rawSlug, slug)
    end
    cprint("${green}created Exercise:${clear} %s", path.join(relativeRoot, exercise.directoryName))
    cprint("${dim}target:${clear} %s", exercise.directoryName)
    cprint("${dim}namespace:${clear} %s", exercise.namespaceName)
end
