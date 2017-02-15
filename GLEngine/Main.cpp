#include <gl_core_4_4.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
	// initialise glfw
	if (glfwInit() == false)
		return -1;

	// Create a Window
	GLFWwindow* window = glfwCreateWindow(1280, 720, "My First game engine", nullptr, nullptr);

	// Call function: Render space: All work to be placed inside window: to avoid crash
	glfwMakeContextCurrent(window);


	// HELPER () : If fails to load
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		// IF FAILS
		glfwDestroyWindow(window);
		glfwTerminate();
		return -2;
	}

	// HELPER (): Check Version of OpenGL (We want 4.3, 2017)
	int major = ogl_GetMajorVersion();
	int minor = ogl_GetMinorVersion();
	std::cout << "GL Version is " << major << ", " << minor << std::endl;


	// Setup While Loop before window closes
	while (glfwWindowShouldClose(window) == false)
	{
		// Dbl Buffer: Shows back buffer on screen, and prepares another buffer to write
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Shut window down
	glfwDestroyWindow(window);

	// Terminating: Program with OpenGL enabled
	glfwTerminate();
	return 0;
}