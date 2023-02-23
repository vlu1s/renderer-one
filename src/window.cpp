#include <logging.hpp>
#include <window.hpp>

/** Global window pointer */


/* void window_create(const char *title); */

/**
 * @brief TODO: (Jeff) description
 */
void vulkan_init(void)
{
    /**< TODO: (Jeff) Build this function. */
    return;
}

void render(void) {
    int w, h;

    /* glfwGetFramebufferSize(WINDOW, &WIDTH, &HEIGHT); */
}



/**
 * @brief Print error messages to stderr, but without exiting
 *
 * @param `const char *msg` Message output
 * @param `const int error` Error signal
 */
void error_callback(int error, const char *msg)
{
    std::fprintf(stderr, "[%d]: %s\n", error, msg);
}

/*
 * @brief TODO: description
 *
 * @param window TODO: parameter
 * @param key TODO: parameter
 * @param scancode TODO: parameter
 * @param action TODO: parameter
 * @param mods TODO: parameter
 */
internal void key_callback(GLFWwindow* window,
                           const int key,
                           const int scancode,
                           const int action,
                           const int mods)
{
    std::printf("Input event: key = %d, scancode = %d, action = %d, mods = %d\n",
                key, scancode, action, mods);
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}


int main(void)
{
    /**< Initialize glfw library. Exit with error if unsuccessful. */
    if(!glfwInit())
    {
        /**<  TODO: (luis) logging */
        return -1;
    }

    glfwSetErrorCallback(error_callback);
    /**< Tell the window not to initialize an OpenGL environment. */
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    /**
     * Create a windowed mode window
     * If window cannot be created, exit
     */
    if(!(WINDOW = glfwCreateWindow(WIDTH, HEIGHT, "RENDERER ONE", NULL, NULL)))
    {
        /**< TODO: (luis) logging */
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(WINDOW);

    /**< Set the key callback function to the window */
    glfwSetKeyCallback(WINDOW, key_callback);

    /**< TODO: (luis) Initialize Vulkan? */
    vulkan_init();

    /**< Main Loop */
    while(!glfwWindowShouldClose(WINDOW))
    {
        glfwPollEvents();

        render();
    }

    /**< Window cleanup */
    glfwDestroyWindow(WINDOW);

    /**< Terminate GLFW */
    glfwTerminate();

    return 0;
}
