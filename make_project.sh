#!/bin/bash
ROOT_DIR="."

# Directories
mkdir -p "$ROOT_DIR/framework"
mkdir -p "$ROOT_DIR/tests/ft_strlen"
mkdir -p "$ROOT_DIR/tests/ft_atoi"
mkdir -p "$ROOT_DIR/build"
mkdir -p "$ROOT_DIR/lib"

# Framework files
touch "$ROOT_DIR/framework/libunit.h"
touch "$ROOT_DIR/framework/load_test.c"
touch "$ROOT_DIR/framework/launch_tests.c"
touch "$ROOT_DIR/framework/utils.c"

# Test files for ft_strlen
touch "$ROOT_DIR/tests/ft_strlen/00_launcher.c"
touch "$ROOT_DIR/tests/ft_strlen/01_basic_test.c"
touch "$ROOT_DIR/tests/ft_strlen/02_empty_test.c"

# Test files for ft_atoi
touch "$ROOT_DIR/tests/ft_atoi/00_launcher.c"
touch "$ROOT_DIR/tests/ft_atoi/01_basic_test.c"
touch "$ROOT_DIR/tests/ft_atoi/02_negative_test.c"

# Main test runner
touch "$ROOT_DIR/main.c"

# Makefile
touch "$ROOT_DIR/Makefile"


echo "✅ libunit project structure created successfully."

