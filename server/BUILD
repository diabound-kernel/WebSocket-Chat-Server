load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "lib-boost",
    srcs = glob(["*/*.cpp"]),
    hdrs = glob(["*/*.hpp"]),
    deps = [
        "@boost//:asio",
        "@boost//:beast",
    ],
    visibility = [
        "//app:__pkg__",
        "//test:__pkg__",
    ],
)

cc_binary(
    name = "server",
    srcs = [
        "main.cpp",
        "http_session.hpp",
        "listener.hpp",
        "shared_state.hpp",
        "web_socket_session.hpp",
        "fail.hpp",
    ],
    deps = [
        "lib-boost",
    ],
)