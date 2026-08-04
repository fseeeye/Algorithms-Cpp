import("core.base.option")
import("exercise_catalog", {rootdir = os.scriptdir()})

function main()
    local changed = exercise_catalog.update_index(os.projectdir(), option.get("check"))
    if changed then
        cprint("${green}updated Exercise Index:${clear} README.md")
    else
        cprint("${green}Exercise Index is up to date${clear}")
    end
end
