#include <gl_core_4_4.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <Gizmos.h>
#define GLM_SWIZZLE
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "SolarSystem.h"
#include "Application.h"

int main()
{

	/////////////// NEW APPLICATION - Specify new Project  ///////////////////////////////
	SolarSystem* app = new SolarSystem();
	//Application app2 = new RenderGeometry("Render Geometry", 1280, 720);
	//switch(

	////////////// RUN APPLICATION ////////////////////////////////////
	app->run();
	//app2-> run();
	delete app;

}

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
//
void application()
{

}

//// UNIQUE PER APPLICATION:
//// SET SOLAR SYSTEM - GLOBAL/LOCAL POS
void setupSolarSystem()
{
	planetTransform[3] = glm::vec4(4, 0, 0, 1);
}

//// SOLAR SYSTEM - DRAW
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

