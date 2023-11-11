load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "Node",
    srcs = [
        "Node.cpp",
    ],
    hdrs = [
        "Node.hpp",
    ],
    data = [
        "//resources:Assets",
    ],
    linkopts = [
        "-lsfml-graphics",
        "-lsfml-window",
        "-lsfml-system",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "Layer",
    srcs = [
        "Layer.cpp",
    ],
    hdrs = [
        "Layer.hpp",
    ],
    linkopts = [
        "-lsfml-graphics",
        "-lsfml-window",
        "-lsfml-system",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":Node",
    ],
)

cc_library(
    name = "LinearRegression",
    srcs = [
        "LinearRegression.cpp",
    ],
    hdrs = [
        "LinearRegression.hpp",
    ],
    linkopts = [
        "-lsfml-graphics",
        "-lsfml-window",
        "-lsfml-system",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":Layer",
        "//src:Vengai",
    ],
)

cc_library(
    name = "Menu",
    srcs = ["Menu.cpp"],
    hdrs = [
        "Menu.hpp",
    ],
    linkopts = [
        "-lsfml-graphics",
        "-lsfml-window",
        "-lsfml-system",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":LinearRegression",
    ],
)

cc_library(
    name = "Application",
    srcs = ["Application.cpp"],
    hdrs = [
        "Application.hpp",
    ],
    linkopts = [
        "-lsfml-graphics",
        "-lsfml-window",
        "-lsfml-system",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":LinearRegression",
        ":Menu",
    ],
)

cc_binary(
    name = "Vengai-gui",
    srcs = [
        "main.cpp",
    ],
    linkopts = [
        "-lsfml-graphics",
        "-lsfml-window",
        "-lsfml-system",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":Application",
    ],
)
