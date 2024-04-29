target("dynamic_array")
    set_kind("static")
    set_group("Data Structures")

    -- add files
    add_files("*.cpp")
    add_headerfiles("*.h")
    add_includedirs(".", {public = true})

    add_deps("basic")
