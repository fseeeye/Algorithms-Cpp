local _validatedProjects = {}

function main(_)
    local projectDir = os.projectdir()
    if not _validatedProjects[projectDir] then
        import("exercise_catalog")
        exercise_catalog.scan(projectDir)
        _validatedProjects[projectDir] = true
    end
end
