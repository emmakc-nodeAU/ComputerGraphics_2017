/////////////////////////////////////////////////////////////
//	Name: Emma Cameron
//	Date: 15 February 2017
//	Project: Computer Graphics
/////////////////////////////////////////////////////////////

#pragma once
#include "Application.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/mat4x4.hpp>


class SolarSystem : public Application
{
public:
	// Constructors
	SolarSystem();
	virtual ~SolarSystem();

	// OVERRIDE VIRTUAL BASE APPLICATION FUNCTIONS
	// FUNCTIONS
	// SETUP
	bool setup() override;
	// SHUTDOWN
	void shutdown() override;
	// UPDATE
	bool update() override;
	// DRAW / RENDER
	void render() override;
protected:


private:
	glm::mat4 m_projection;
	glm::mat4 m_view;
};
