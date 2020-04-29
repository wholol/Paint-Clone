#pragma once
#include <SFML\Graphics.hpp>
#include "Toolbar.h"

//base class for all entities which include shape, text, paint and airbrush.
class Entity {	
public:
	virtual void drawEntity(sf::RenderWindow& createwindow) = 0;		//draw entity to screen
	virtual void resize(const sf::Mouse& mouse, sf::RenderWindow& createwindow) = 0;	//resize the entity (text size, shape size, airbrush size and paintbrush size).
	virtual void setLimit(const Toolbar& toolbar) {			//set the limit for drawing.
		Limit = toolbar.BoundaryLimit();		
	}

	virtual ~Entity()	{};		//virtual destructor to prevent memory leaks.
protected:
	int mouseposx;			
	int mouseposy;
	int Limit;

};