/////////////////////////////////////////////////////////////
//	Name: Emma Cameron
//	Date: 15 February 2017
//	Project: Computer Graphics
/////////////////////////////////////////////////////////////

#include "Application.h"
#include "Gizmos.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <gl_core_4_4.h>
#include <GLFW\glfw3.h>
#include <iostream>

using glm::vec3;
using glm::vec4;
using glm::mat4;
using aie::Gizmos;


Application::Application(std::string windowTitle, int width, int height)
	: m_windowName(windowTitle)
	, m_windowWidth(width)
	, m_windowHeight(height)
{
}

Application::~Application()
{
}

// FUNCTIONS
	// FUNCTION 1: RUN
bool Application::run()
{
	bool successful = createWindow();
	if (!successful) return false;

	successful = setupOpenGL();
	if (!successful)
	{
		destroyWindow();
		return false;
	}

	// OPTIONAL USER SETUP
	// FUNCTION 3: SETUP
	successful = setup();
	if (!successful)
	{
		destroyWindow();
		return false;
	}

	/////////////////////////////////////////////

	while (glfwWindowShouldClose(m_window) == false)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// FUNCTION 5: UPDATE
		update();
		// FUNCTION 6: RENDER
		render();

		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}

	//////////////////////////////////////////////////////////////
	// FUNCTION 4: SHUTDOWN
	shutdown();
	// FUNCTION 8: DESTROY
	destroyWindow();
	return true;

	////////////////////////////////////////////////////////////
}

////////////////// CHECK OPENGL VERSION /////////////////////////
// FUNCTION: 2 CHECK OpenGL Version
void Application::printOpenGLVersion()
{

	// HELPER (): Check Version of OpenGL (We want 4.3, 2017)  (REUSE)
	int major = ogl_GetMajorVersion();
	int minor = ogl_GetMinorVersion();
	std::cout << "GL Version is " << major << ", " << minor << std::endl;
}

//// FUNCTION Definitions
//bool Application::setup()
//{
//	// Gizmos primatives
//	Gizmos::create(10000, 10000, 10000, 10000);
//	
//	// Camera transforms
//	
//
//	return false;
//}
//
//void Application::shutdown()
//{
//	Gizmos::destroy();
//}
//
//bool Application::update()
//{
//	return true;
//}
//
//// FUNCTION 6. DRAW / RENDER
//void Application::render()
//{
//	// Setup Canvas
//
//	// Setup Camera
//	
//
//}

//////////////////////// CREATE: WINDOW /////////////////////////////////////
// FUNCTION: 7 CREATE: WINDOW
bool Application::createWindow()
{

	// WINDOW: Setup initialise glfw
	if (glfwInit() == false)
		return false;

	// Create a Window (reusable)
	m_window =
		glfwCreateWindow(m_windowWidth, m_windowHeight,
			m_windowName.c_str(), nullptr, nullptr);

	// Call function: Render space: All work to be placed inside window: to avoid crash
	glfwMakeContextCurrent(m_window);
	
	return true;
}
//////////////////////// DESTROY: WINDOW ///////////////////////////////
// FUNCTION: 8 DESTROY: WINDOW
void Application::destroyWindow()
{
	// Shut window down
	if (m_window != nullptr) glfwDestroyWindow(m_window);

	// Terminating: Program with OpenGL enabled
	glfwTerminate();
}

//////////////////////// CREATE: OPENGL /////////////////////////////////

// FUNCTION 9. CREATE: OPENGL
bool Application::setupOpenGL()
{
	// HELPER () : Setup OpenGL If fails to load (REUSE)
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		return false;
		// IF FAILS
		//glfwDestroyWindow(window);
		//glfwTerminate();
		//return -;2
	}
	return true;
}
