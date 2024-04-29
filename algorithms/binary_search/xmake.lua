-- define target
target("binary_search")
    set_kind("binary")
    set_group("Algorithms")

    -- add files
    add_files("main.cpp")
    add_files("template/*.cpp")
    add_headerfiles("template/*.h")
    add_filegroups("Header Files", {rootdir = "./", files = "**/*.h"})
    add_filegroups("Source Files", {rootdir = "./", files = "**/*.cpp"})

    -- add include search directories
    add_includedirs("template")

    -- set optimization: none, faster, fastest, smallest
    set_optimize("none")