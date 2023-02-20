#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <GLFW/glfw3.h>
#define GLFW_INCLUDE_VULKAN

#include "types.hpp"  // Custom macros and/or typedefs.

// TODO(luis): Should these be global?
static natural WIDTH = 1280;
static natural HEIGHT = 720;

/* Callback function to process input events */
internal void key_callback(
    GLFWwindow *window,
    const int key,
    const int scancode,
    const int action,
    const int mods
);

#endif // WINDOW_HPP
