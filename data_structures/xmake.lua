add_requires("spdlog 1.14")

includes("array")

target("test_structures")
    set_kind("binary")
    set_group("Data Structures")

    -- add files
    add_files("test_structures.cpp")

    -- add deps
    add_deps("array")
    add_packages("spdlog")