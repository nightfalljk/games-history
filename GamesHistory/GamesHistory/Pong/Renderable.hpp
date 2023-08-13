#pragma once

#include "Renderer.hpp"

class Renderable
{
public:
	virtual void Draw(Renderer* renderer) {};
};