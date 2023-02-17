#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

const uint32_t WIDTH = 1280;
const uint32_t HEIGHT = 720;

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
