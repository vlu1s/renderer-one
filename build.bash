#!/usr/bin/env bash
# AUTHOR(S): Luis Valencia, Guennadi Maximov

<<<<<<< Updated upstream
g++ -pedantic-errors -Werror -Wall -Weffc++ -Wextra -Wsign-conversion -std=c++20 src/window.cpp -o bin/window -lglfw
||||||| Stash base
g++ -pedantic-errors -Werror -Wall -Weffc++ -Wextra -Wsign-conversion -std=c++20 src/window.cpp -o bin/window
=======
CC=gcc
CXX=g++
STD=c++20
CFLAGS=(
    -pedantic
    -pedantic-errors
    -Wall
    -Werror
    -Wextra
    -Weffc++
    -Wsign-conversion
    "-std=$STD"

)
LIBFLAGS=(
    -Llib
    -lglfw3
)
DEBUG_FLAGS=(
    -g
    -g3
    -ggdb
)
LDFLAGS=(
    -fPIC
)
OPTIM_FLAGS=(
    -O2
)

# TODO: Function to decide whether to compile an object or a library.

$CXX $CFLAGS $LIBFLAGS $INCLUDEFLAGS -o bin/window
>>>>>>> Stashed changes
