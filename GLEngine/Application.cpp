/////////////////////////////////////////////////////////////
//	Name: Emma Cameron
//	Date: 15 February 2017
//	Project: Computer Graphics
/////////////////////////////////////////////////////////////

#include "Application.h"
#include "Gizmos.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>

using glm::vec3;
using glm::vec4;
using glm::mat4;
using aie::Gizmos;


Application::Application()
{
}

Application::~Application()
{
}

// FUNCTION Definitions
bool Application::startup()
{
	// Gizmos primatives
	Gizmos::create(10000, 10000, 10000, 10000);
	
	// Camera transforms
	

	return false;
}

void Application::shutdown()
{
	Gizmos::destroy();
}

void Application::update(float deltaTime)
{

}

void Application::draw()
{
	// Setup Canvas

	// Setup Camera
	

} 
