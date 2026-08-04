-- define target
target("basic")
    set_kind("headeronly")
    set_group("Basic")

    add_headerfiles("common.h")
    add_headerfiles("bits/stdc++.h")
    add_headerfiles("structures/*.h")
    add_includedirs(".", {public = true})
    add_includedirs("./bits", {public = true})
    add_includedirs("./structures", {public = true})

    -- the generation of cmake/pkgconfig import files during the installation phase.
    -- add_rules("utils.install.cmake_importfiles")
    -- add_rules("utils.install.pkgconfig_importfiles")
