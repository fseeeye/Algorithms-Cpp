-- -- define target
-- target("01_init_dx11")
--     set_kind("binary")
--     set_group("Foundation")

--     -- add files
--     add_files("src/00_init_dx11/*.cpp")
--     add_headerfiles("src/00_init_dx11/*.h")
--     add_filegroups("Header Files", {rootdir = "src/00_init_dx11", files = "/*.h"})
--     add_filegroups("Source Files", {rootdir = "src/00_init_dx11", files = "/*.cpp"})

--     -- add include search directories
--     add_includedirs("src/00_init_dx11/")

--     -- add Windows SDK links
--     add_rules("win.sdk.application")
--     add_syslinks("d3d11", "dxguid.lib")

--     -- set optimization: none, faster, fastest, smallest
--     set_optimize("none")