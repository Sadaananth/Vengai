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
    data = [
        "//resources:Assets",
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

cc_library(
    name = "Menu",
    srcs = [ "Menu.cpp" ],
    hdrs = [
        "Menu.hpp",
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

cc_library(
    name = "Application",
    srcs = [ "Application.cpp" ],
    hdrs = [
        "Application.hpp",
    ],
    visibility = ["//visibility:public"],
    linkopts = [
        "-lsfml-graphics",
        "-lsfml-window",
        "-lsfml-system",
    ],
    deps = [
        ":LinearRegression",
        ":Menu",
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
        ":Application",
    ]
)
