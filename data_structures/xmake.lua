includes("others", "array")

target("test_structures")
    set_kind("binary")
    set_group("Data Structures")

    -- add files
    add_files("test_structures.cpp")

    -- add deps
    add_deps("others", "array")