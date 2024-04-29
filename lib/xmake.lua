-- define target
target("basic")
    set_kind("static")

    add_files("common.cpp")
    add_headerfiles("common.h")
    add_includedirs(".", {public = true})

    -- the generation of cmake/pkgconfig import files during the installation phase.
    -- add_rules("utils.install.cmake_importfiles")
    -- add_rules("utils.install.pkgconfig_importfiles")
