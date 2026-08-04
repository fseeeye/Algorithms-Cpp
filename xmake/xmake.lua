local projectDir = path.directory(os.scriptdir())
local exerciseRoots = {
    {directory = "algorithms", group = "Algorithms"},
    {directory = "data_structures", group = "Data Structures"},
    {directory = "reviews", group = "Reviews"}
}

local exerciseDirectories = {}
local targetDirectories = {}

for _, root in ipairs(exerciseRoots) do
    local rootDir = path.join(projectDir, root.directory)
    for _, testFile in ipairs(os.files(path.join(rootDir, "**", "*_test.cpp"))) do
        local exerciseDir = path.directory(testFile)
        exerciseDirectories[exerciseDir] = root.group
    end
end

for exerciseDir, group in pairs(exerciseDirectories) do
    local targetName = path.basename(exerciseDir)
    if targetDirectories[targetName] then
        raise("duplicate Exercise target '%s': %s and %s",
            targetName, targetDirectories[targetName], exerciseDir)
    end
    targetDirectories[targetName] = exerciseDir

    target(targetName)
        set_kind("binary")
        set_default(false)
        set_group(group)
        add_files(path.join(exerciseDir, "*.cpp"))
        add_headerfiles(path.join(exerciseDir, "*.h"))
        add_includedirs(exerciseDir)
        add_deps("basic")
        add_packages("catch2", {components = {"main", "lib"}})
        add_tests("default")
end

task("new")
    set_category("plugin")
    -- Xmake's common --root is a boolean flag. This task owns --root=<path>,
    -- so it supplies its own compact option set instead of merging common options.
    set_menu {
        _common_options = true,
        usage = "xmake new --kind=<problem|template> --domain=<algorithm|data_structure> --root=<path> [--id=<ID>] --slug=<name>",
        description = "Create an Exercise scaffold",
        options = {
            {"h", "help", "k", nil, "Print this help message and exit"},
            {nil, "kind", "kv", nil, "Exercise kind: problem or template"},
            {nil, "domain", "kv", nil, "Exercise domain: algorithm or data_structure"},
            {nil, "root", "kv", nil, "Existing category directory under an Exercise root"},
            {nil, "id", "kv", nil, "Compact Problem ID, for example LC215 or HJ02"},
            {nil, "slug", "kv", nil, "Exercise subject; safely normalized to lower snake_case"}
        }
    }
    on_run("modules.new_exercise")
