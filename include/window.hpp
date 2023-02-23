#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "logging.hpp" /**< Logging utilities */

GLFWwindow *WINDOW = NULL;

static natural WIDTH = 1280;
static natural HEIGHT = 720;

/**
 * @brief Callback function to process input events
 * @see `GLFWwindow`
 *
 * @param window TODO: (Jeff) parameter
 * @param key TODO: (Jeff) parameter
 * @param scancode TODO: (Jeff) parameter
 * @param action TODO: (Jeff) parameter
 * @param mods TODO: (Jeff) parameter
 */
internal void key_callback(
    GLFWwindow *window,
    const int key,
    const int scancode,
    const int action,
    const int mods
);


static inline bool vk_works(void);
static void vulkan_init(void);

#endif /**! WINDOW_HPP */
