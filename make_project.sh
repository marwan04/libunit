#!/bin/bash
ROOT_DIR="."

# Directories
mkdir -p "$ROOT_DIR/framework"
mkdir -p "$ROOT_DIR/tests/dummy_tests"
mkdir -p "$ROOT_DIR/tests/real-tests"

# Framework files
touch "$ROOT_DIR/framework/libunit.h"
touch "$ROOT_DIR/framework/load_test.c"
touch "$ROOT_DIR/framework/launch_tests.c"
touch "$ROOT_DIR/framework/utils.c"


touch "$ROOT_DIR/tests/dummy_tests/01_basic_test.c"
touch "$ROOT_DIR/tests/dummy_tests/02_empty_test.c"
touch "$ROOT_DIR/tests/dummy_tests/03_null_test.c"
touch "$ROOT_DIR/tests/Makefile"

touch "$ROOT_DIR/tests/real-tests/Makefile"
touch "$ROOT_DIR/main.c"

# Makefile
touch "$ROOT_DIR/Makefile"


echo "✅ libunit project structure created successfully."

