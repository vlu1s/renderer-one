#!/usr/bin/env bash
# AUTHOR(S): Luis Valencia, Guennadi Maximov
# LICENSE: MIT

# TODO: Short and long options parsing.
# S_OPTS=""

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
INCLUDEFLAGS=(
    -Iinclude
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

"$CXX" "${CFLAGS[*]}" "${LIBFLAGS[*]}" "${INCLUDEFLAGS[*]}" -o bin/window
