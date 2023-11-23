load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

filegroup(
    name = "SadaLoggerLib",
    srcs = [
        "build/libSadaLogger.so",
    ],
)

cc_library(
    name = "SadaLogger",
    srcs = [
        "build/libSadaLogger.so",
    ],
    hdrs = [
        "src/Logger.hpp",
    ],
)
