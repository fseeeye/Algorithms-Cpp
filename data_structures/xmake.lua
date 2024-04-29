includes("dynamic_array")

target("nodes")
    set_kind("headeronly")
    set_group("Data Structures")

    add_headerfiles("list_node.h", "tree_node.h")
    add_includedirs(".", {public = true})

target("test_structures")
    set_kind("binary")
    set_group("Data Structures")

    -- add files
    add_files("main.cpp")

    -- add deps
    add_deps("nodes", "dynamic_array")