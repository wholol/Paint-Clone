#pragma once
#include <SFML\Graphics.hpp>
#include "Toolbar.h"

//base class for all entities which include shape, text, paint and airbrush.
struct Entity {		
	virtual void drawEntity(sf::RenderWindow& createwindow, const Toolbar& toolbar) = 0;		//draw entity to screen
	virtual void resize(const sf::Mouse& mouse, sf::RenderWindow& createwindow, const Toolbar& toolbar) = 0;	//resize the entity (text size, shape size, airbrush size and paintbrush size).
	virtual ~Entity()	{};		//virtual destructor to prevent memory leaks.
};