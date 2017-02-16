#include <gl_core_4_4.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <Gizmos.h>
#define GLM_SWIZZLE
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "SolarSystem.h"
#include "Application.h"

// TO DO: Create SolarSystem class
// ID Matrix 4 x 4 Column Major
// [1] [0] [0] [0] = X
// [0] [1] [0] [0] = Y (Up)
// [0] [0] [1] [0] = Z
// [0] [0] [0] [1] = Position

// SUN
glm::mat4 sunTransform(1);
// PLANET
glm::mat4 planetTransform(1);

void application()
{

}

// SET SOLAR SYSTEM - GLOBAL/LOCAL POS
void setupSolarSystem()
{
	planetTransform[3] = glm::vec4(4, 0, 0, 1);
}

// SOLAR SYSTEM - DRAW
void renderSolarSystem()
{
	// LOCAL POSITION - SUN
	glm::mat4 rot = glm::rotate(0.01f, glm::vec3(0, 1, 0));
	sunTransform = sunTransform * rot;

	// LOCAL POSITION - PLANET
	aie::Gizmos::addSphere(sunTransform[3].xyz(),
		2.0f, 32, 32, glm::vec4(0.7f,0.7f, 0, 1), (&sunTransform));

	// ROTATION PLANET - Planet Spin | Rotate local
	rot = glm::rotate(0.005f, glm::vec3(0, 1, 0));
	planetTransform = rot * planetTransform;

	// ROTATION PLANET - Orbit SUN | Rotate global
	aie::Gizmos::addSphere(planetTransform[3].xyz(),
		0.5f, 32, 32, glm::vec4(0.0f, 0.5f, 0.0, 1), (&planetTransform));
}

int main()
{
	// initialise glfw
	if (glfwInit() == false)
		return -1;

	// Create a Window
	GLFWwindow* window = glfwCreateWindow(1280, 720, "Emma's Game Engine", nullptr, nullptr);

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

	// ??
	aie::Gizmos::create(64000, 64000, 64000, 64000);

	// COLOR BUFFER:
	glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	//float rColor = 0.0f;

	// MATH
	// Calculates Matrix at position 10,10,10 in relation to Camera
	glm::mat4 view = glm::lookAt(
		glm::vec3(10, 10, 10),	// Our position
		glm::vec3(0, 0, 0),		// Z = facing
		glm::vec3(0, 1, 0));	// Y = up

	// Projection matrix: Depth/ field of view take relative to camera to being on the screen
	glm::mat4 projection = glm::perspective(
		glm::pi<float>() * 0.25f,
		1280.0f / 720, 0.1f, 1000.0f);

	////////////////////////////////////////////////////////////////
	//	SOLAR SYSTEM
	//
	////////////////////////////////////////////////////////////////
	setupSolarSystem();

	// MAIN GAME LOOP:
	// Setup While Loop before window closes
	while (glfwWindowShouldClose(window) == false)
	{
		//glClearColor(rColor, 0.0f, 0.0f, 1.0f);
		//rColor += 0.001f;
		
		// Call GL Clear x2 buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



		// Clear Gizmos / any rendering data
		aie::Gizmos::clear();

		// Call Render Solar System
		renderSolarSystem();

		// Draws 3 lines X, Y, Z axis - -sees direction our world is. Pass in ID matrix
		aie::Gizmos::addTransform(glm::mat4(1), 3.0f);
		glm::vec4 white(1);
		glm::vec4 black(0, 0, 0, 1);

		for (int i = 0; i < 21; ++i)
		{
			aie::Gizmos::addLine(
				glm::vec3(-10 + i, 0, 10),
				glm::vec3(-10 + i, 0, -10),
				i == 10 ? white : black);

			aie::Gizmos::addLine(
				glm::vec3(10, 0, -10 + i),
				glm::vec3(-10, 0, -10 + i),
				i == 10 ? white : black);
		}


		aie::Gizmos::draw(projection * view);
		// Dbl Buffer: Shows back buffer on screen, and prepares another buffer to write
		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	// Destroy AIE 
	aie::Gizmos::destroy();
	// Shut window down
	glfwDestroyWindow(window);

	// Terminating: Program with OpenGL enabled
	glfwTerminate();
	return 0;
}