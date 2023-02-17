#!/usr/bin/env bash
# AUTHOR(S): Luis Valencia, Guennadi Maximov

g++ -pedantic-errors -Werror -Wall -Weffc++ -Wextra -Wsign-conversion -std=c++20 src/window.cpp -o bin/window -lglfw
