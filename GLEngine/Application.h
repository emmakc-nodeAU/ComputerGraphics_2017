/////////////////////////////////////////////////////////////
//	Name: Emma Cameron
//	Date: 15 February 2017
//	Project: Computer Graphics
/////////////////////////////////////////////////////////////

#pragma once

#include <glm/fwd.hpp>
#include <glm/mat4x4.hpp>
#include <string>

struct GLFWwindow;

class Application
{
public:

	// !Generate default constructor
	Application() = delete;
	// Constructors
	Application(std::string windowTitle, int width, int height);
	// Deconstructor - Base class, others will derive from this .: virtual
	virtual ~Application();

	// FUNCTIONS
	// 1. RUN Application
	bool run();
	// 2. CHECK OpenGL Version
	void printOpenGLVersion();

protected:

	// FUNCTIONS
	// 3. SETUP
	virtual bool setup() = 0;
	// 4. SHUTDOWN
	virtual void shutdown() = 0;
	// 5. UPDATE
	virtual bool update() = 0;
	// 6. DRAW / RENDER
	virtual void render() = 0;

	// CAMERA: Tranforms
	glm::mat4 m_viewMatrix;
	glm::mat4 m_projectionMatrix;

	// GET ()
	int getWindowWidth() const { return m_windowWidth; }
	int getWindowHeight() const { return m_windowHeight; }

private:

	// FUNCTIONS
	// 7. CREATE: WINDOW
	bool createWindow();
	// 8. DESTROY: WINDOW
	void destroyWindow();
	// 9. CREATE: OPENGL
	bool setupOpenGL();

	// WINDOW member variables
	std::string m_windowName;
	int			m_windowWidth;
	int			m_windowHeight;

	GLFWwindow* m_window;
};
