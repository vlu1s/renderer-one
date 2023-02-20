#include "../include/window.hpp"
#include "../include/logging.hpp"
#include <cstdio>
#include <cstdlib>

/* Global window pointer */
static GLFWwindow *WINDOW;

/*
 * @brief [TODO:description]
 *
 * @param window [TODO:parameter]
 * @param key [TODO:parameter]
 * @param scancode [TODO:parameter]
 * @param action [TODO:parameter]
 * @param mods [TODO:parameter]
 */
internal void key_callback(
	GLFWwindow* window,
	const int key,              /* Signed?[ ] Variable?[ ] */
	const int scancode,         /* Signed?[ ] Variable?[ ] */
	const int action,           /* Signed?[ ] Variable?[ ] */
	const int mods              /* Signed?[ ] Variable?[ ] */
)
{
	printf("Input event: key = %d, scancode = %d, action = %d, mods = %d\n",
		key, scancode, action, mods);
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}



int main(void)
{


	/* Initialize glfw library. Exit with error if unsuccessful. */
	if(!glfwInit())
	{
		// TODO(luis): logging
		return -1;
	}

    /* Create a hint for the following window to be created. */
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	/* Create a windowed mode window */
	WINDOW = glfwCreateWindow(WIDTH, HEIGHT, "Renderer One", NULL, NULL);

	if(!WINDOW)  // WARNING: (Jeff) Suggesting one-liner ==> `if ((WINDOW = glfwCreateWindow(...)))`
	{
        /* If window cannot be created, exit. */
		// TODO(luis): logging
		glfwTerminate();
		return -1;
	}

	/* Set the key callback function to the window */
	glfwSetKeyCallback(window, key_callback);

	/** TODO(luis): Initialize Vulkan? **/

	/** Main Loop **/
	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}

	/** Window cleanup **/
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
