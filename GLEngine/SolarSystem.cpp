/////////////////////////////////////////////////////////////
//	Name: Emma Cameron
//	Date: 15 February 2017
//	Project: Computer Graphics
/////////////////////////////////////////////////////////////

#pragma once
#include "SolarSystem.h"
#include <glm/fwd.hpp>
#include <glm/mat4x4.hpp>
#include <Gizmos.h>

// VARIABLES
//glm::mat4 sunTransform(1);
//glm::mat4 planetTransform(1);

// CONSTRUCTORS
SolarSystem::SolarSystem() : Application("Solar System R Us", 1280, 720)
{

}

SolarSystem::~SolarSystem()
{
}

///////////////////////// FUNCTIONS //////////////////////////////////
// SETUP
bool SolarSystem::setup()
{
	aie::Gizmos::create(64000, 64000, 0, 0);

	// NO IDEA?
	m_projection = glm::perspective(
		glm::pi<float>() * 0.25f,
		(float)getWindowWidth() / getWindowHeight(),
		0.1f, 1000.0f);

	// CAMERA SETUP
	m_view = glm::lookAt(glm::vec3(10, 10, 10),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 1, 0));

	return true;
}

// SHUTDOWN
void SolarSystem::shutdown()
{
	aie::Gizmos::destroy();
}

bool SolarSystem::update()
{
	return true;
}

// RENDER
void SolarSystem::render()
{
	aie::Gizmos::clear();

	// PROJECTION VIEW
	aie::Gizmos::draw(m_projection * m_view);
}

// Definitions
//void setupSolarSystem()
//{
//	planetTransform[3] = glm::vec4(4, 0, 0, 1);
//}

/* SolarSystem is a base template for any application to run. */


