load("@rules_cc//cc:defs.bzl", "cc_library","cc_binary")

cc_library(
    name = "Node",
    srcs = [
        "Node.cpp",
    ],
    hdrs = [
        "Node.hpp",
    ],
    visibility = ["//visibility:public"],
    linkopts = [
        "-lsfml-graphics",
        "-lsfml-window",
        "-lsfml-system",
    ],
)

cc_library(
    name = "Layer",
    srcs = [
        "Layer.cpp",
    ],
    hdrs = [
        "Layer.hpp",
    ],
    visibility = ["//visibility:public"],
    linkopts = [
        "-lsfml-graphics",
        "-lsfml-window",
        "-lsfml-system",
    ],
    deps = [
        ":Node",
    ]
)

cc_library(
    name = "LinearRegression",
    srcs = [
        "LinearRegression.cpp",
    ],
    hdrs = [
        "LinearRegression.hpp",
    ],
    visibility = ["//visibility:public"],
    linkopts = [
        "-lsfml-graphics",
        "-lsfml-window",
        "-lsfml-system",
    ],
    deps = [
        "//src:Vengai",
        ":Layer",
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
