target("others")
    set_kind("headeronly")
    set_group("Data Structures")

    add_headerfiles("*.h")
    add_includedirs(".", {public = true})
