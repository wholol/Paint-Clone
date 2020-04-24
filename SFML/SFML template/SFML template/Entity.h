#pragma once
#include <SFML\Graphics.hpp>
#include "Toolbar.h"

struct Entity {		//base struct for shape and paint. botth shape and paint inherits from entity.
	virtual void drawEntity(sf::RenderWindow& createwindow, const Toolbar& toolbar) = 0;	
};