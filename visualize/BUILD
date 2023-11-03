load("@rules_cc//cc:defs.bzl", "cc_library")

cc_binary(
    name = "Vengai-gui",
    srcs = [
        "main.cpp",
    ],
    visibility = ["//visibility:public"],
    linkopts = [
        "-lsfml-graphics",
        "-lsfml-window",
        "-lsfml-system",
    ],
    deps = [
        "//src:Vengai",
    ]
)
