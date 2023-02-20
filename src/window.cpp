#include "../include/window.hpp"
#include <stdio.h>
#include <stdlib.h>

/* Callback function to process input events */
internal void key_callback(
	GLFWwindow* window,
	int key,
	int scancode,
	int action,
	int mods)
{
	printf("Input event: key = %d, scancode = %d, action = %d, mods = %d\n",
		key, scancode, action, mods);
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

int main()
{
	/** Initialize window **/
	GLFWwindow* window;
	/* Initialize glfw library */
	if(!glfwInit())
	{
		// TODO(luis): loggging 
		return -1;
	}
	/* Not an OpenGL window */
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	/* Create a windowed mode window */
	window = glfwCreateWindow(WIDTH, HEIGHT, "Renderer One", NULL, NULL);
	if(!window)
	{
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
