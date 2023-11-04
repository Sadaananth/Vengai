load("@rules_cc//cc:defs.bzl", "cc_library","cc_binary")

cc_library(
    name = "LinearRegression",
    srcs = [
        "LinearRegression.cpp",
    ],
    hdrs = [
        "LinearRegression.hpp",
        "Node.hpp",
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
        ":LinearRegression",
    ]
)
