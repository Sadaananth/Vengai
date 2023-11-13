# Vengai
My machine learning library

## Run
To run the gui application enter the command
``` sh
bazel run //visualize:Vengai-gui
```

To format bazel files, enter the following command
``` sh
bazel run //:buildifier
```

To run clang-tidy, enter the following command
``` sh
bazel build //... --config clang-tidy
```
