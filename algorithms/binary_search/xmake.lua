-- define target
target("binary_search")
    set_kind("binary")
    set_group("Algorithms")

    -- add files
    add_files("main.cpp")
    add_files("*/*.cpp|*/*_test.cpp")
    add_headerfiles("*/*.h")
    add_filegroups("Public", {rootdir = "./", files = "**/*.h"})
    add_filegroups("Private", {rootdir = "./", files = "**/*.cpp"})

    -- add include search directories
    add_includedirs("template_binary_search")

    -- set optimization: none, faster, fastest, smallest
    set_optimize("none")
