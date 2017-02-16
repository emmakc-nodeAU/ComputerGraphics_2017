/////////////////////////////////////////////////////////////
//	Name: Emma Cameron
//	Date: 15 February 2017
//	Project: Computer Graphics
/////////////////////////////////////////////////////////////

#pragma once
#include "Application.h"
#include <glm/fwd.hpp>
#include <glm/mat4x4.hpp>


class Application
{
public:
	// Constructors
	Application();
	virtual ~Application();

	// FUNCTIONS
	// 1. START
	virtual bool startup();
	// 2. END
	virtual void shutdown();
	// 3. UPDATE
	virtual void update(float deltaTime);
	// 4. DRAW / RENDER
	virtual void draw();

protected:
	// CAMERA: Tranforms
	glm::mat4 m_viewMatrix;
	glm::mat4 m_projectionMatrix;

private:

};
