-- define target
target("nodes")
    set_kind("headeronly")
    set_group("Data Structures")

    add_headerfiles("ListNode.h", "TreeNode.h", )

    -- the generation of cmake/pkgconfig import files during the installation phase.
    -- add_rules("utils.install.cmake_importfiles")
    -- add_rules("utils.install.pkgconfig_importfiles")
