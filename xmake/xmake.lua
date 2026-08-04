local projectDir = path.directory(os.scriptdir())
local exerciseRoots = {
    {directory = "algorithms", group = "Algorithms"},
    {directory = "data_structures", group = "DataStructures"},
    {directory = "reviews", group = "Reviews"}
}
local exerciseDirectories = {}
local targetDirectories = {}

for _, root in ipairs(exerciseRoots) do
    local rootDir = path.join(projectDir, root.directory)
    for _, pattern in ipairs({"*.h", "*.cpp"}) do
        for _, sourceFile in ipairs(os.files(path.join(rootDir, "**", pattern))) do
            local metadataFile = path.join(path.directory(sourceFile), "exercise.json")
            if not os.isfile(metadataFile) then
                raise("%s: C++ Exercise material requires colocated exercise.json",
                    path.relative(sourceFile, projectDir))
            end
        end
    end
    for _, metadataFile in ipairs(os.files(path.join(rootDir, "**", "exercise.json"))) do
        local exerciseDir = path.directory(metadataFile)
        if #os.files(path.join(exerciseDir, "*_test.cpp")) == 0 then
            raise("%s: Exercise metadata requires at least one colocated *_test.cpp",
                path.relative(metadataFile, projectDir))
        end
    end
    for _, testFile in ipairs(os.files(path.join(rootDir, "**", "*_test.cpp"))) do
        local exerciseDir = path.directory(testFile)
        local metadataFile = path.join(exerciseDir, "exercise.json")
        if not os.isfile(metadataFile) then
            raise("%s: Exercise Test requires colocated exercise.json", path.relative(testFile, projectDir))
        end
        local category = path.relative(path.directory(exerciseDir), rootDir):gsub("\\", "/")
        if category == "." then
            category = ""
        end
        exerciseDirectories[exerciseDir] = {category = category, group = root.group}
    end
end

for exerciseDir, info in pairs(exerciseDirectories) do
    local targetName = path.basename(exerciseDir)
    if targetDirectories[targetName] then
        raise("duplicate Exercise target '%s': %s and %s",
            targetName, targetDirectories[targetName], exerciseDir)
    end
    targetDirectories[targetName] = exerciseDir

    target(targetName)
        set_kind("binary")
        set_default(false)
        local group = info.group
        if info.category ~= "" then
            group = group .. "/" .. info.category
        end
        set_group(group)
        add_files(path.join(exerciseDir, "*.cpp"))
        add_headerfiles(path.join(exerciseDir, "*.h"))
        add_extrafiles(path.join(exerciseDir, "exercise.json"))
        add_filegroups("", {
            rootdir = exerciseDir,
            files = {"*.cpp", "*.h", "exercise.json"},
            mode = "plain"
        })
        add_includedirs(exerciseDir)
        add_deps("basic")
        add_packages("catch2", {components = {"main", "lib"}})
        add_tests("default")
end

task("new")
    set_category("plugin")
    set_menu {
        _common_options = true,
        usage = "xmake new --kind=<problem|template> --root=<path> [--id=<ID>] --slug=<name> [metadata options]",
        description = "Create an Exercise scaffold and update its index",
        options = {
            {"h", "help", "k", nil, "Print this help message and exit"},
            {nil, "kind", "kv", nil, "Exercise kind: problem or template"},
            {nil, "root", "kv", nil, "Existing category directory under an Exercise root"},
            {nil, "id", "kv", nil, "Compact Problem ID, for example LC215, HJ02 or CF123A"},
            {nil, "slug", "kv", nil, "Exercise subject; safely normalized to lower snake_case"},
            {nil, "name", "kv", nil, "Display name; defaults to a humanized slug"},
            {nil, "difficulty", "kv", nil, "Optional difficulty: Easy, Medium or Hard"},
            {nil, "tip", "kv", nil, "Optional short indexing tip"},
            {nil, "url", "kv", nil, "Optional absolute reference URL"}
        }
    }
    on_run("modules.new_exercise")

task("index")
    set_category("plugin")
    set_menu {
        _common_options = true,
        usage = "xmake index [--check]",
        description = "Regenerate or verify the README Exercise Index",
        options = {
            {"h", "help", "k", nil, "Print this help message and exit"},
            {nil, "check", "k", nil, "Fail instead of writing when the index is stale"}
        }
    }
    on_run("modules.index_exercises")
