load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def download_SadaLogger():
    http_archive(
        name = "SadaLogger",
        url = "https://github.com/Sadaananth/SadaLogger/releases/download/v0.0.1/SadaLogger-linux-x86_64-release.zip",
        build_file = "//third_party/SadaLogger:SadaLogger.BUILD",
    )
