#pragma once
#include "Paint.h"

Paint::Paint() 
	:circle(minbrushradius)
{

}

void Paint::ChangeBrushSize()
	
{
	

}


void Paint::setMousePos(const sf::Mouse& mouse, sf::RenderWindow &createwindow) {
	mouseposx = mouse.getPosition(createwindow).x;
	mouseposy = mouse.getPosition(createwindow).y;
}


void Red::drawpaint(sf::RenderWindow &createwindow,const Toolbar& toolbar) {
	
	uint8_t radius = minbrushradius;
	circle.setRadius(radius);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(sf::Vector2f(mouseposx - radius , mouseposy - radius));
	if (mouseposy - radius <= toolbar.BoundaryLimit()) {
		circle.setPosition(sf::Vector2f(mouseposx - radius, toolbar.BoundaryLimit() + 2));
	}
	createwindow.draw(circle);
}


void Yellow::drawpaint(sf::RenderWindow &createwindow, const Toolbar& toolbar) {
	uint8_t radius = minbrushradius;
	circle.setRadius(radius);
	circle.setFillColor(sf::Color::Yellow);
	circle.setPosition(sf::Vector2f(mouseposx - radius, mouseposy - radius));
	if (mouseposy - radius <= toolbar.BoundaryLimit()) {
		circle.setPosition(sf::Vector2f(mouseposx - radius, toolbar.BoundaryLimit() + 2));
	}
	createwindow.draw(circle);

}


void Blue::drawpaint(sf::RenderWindow &createwindow, const Toolbar& toolbar) {
	uint8_t radius = minbrushradius;
	circle.setRadius(radius);
	circle.setFillColor(sf::Color::Blue);
	circle.setPosition(sf::Vector2f(mouseposx - radius, mouseposy - radius));
	if (mouseposy - radius <= toolbar.BoundaryLimit()) {
		circle.setPosition(sf::Vector2f(mouseposx - radius, toolbar.BoundaryLimit() + 2));
	}
	createwindow.draw(circle);

}



void Black::drawpaint(sf::RenderWindow &createwindow, const Toolbar& toolbar) {
	uint8_t radius = minbrushradius;
	circle.setRadius(radius);
	circle.setFillColor(sf::Color::Black);
	circle.setPosition(sf::Vector2f(mouseposx - radius, mouseposy - radius));
	if (mouseposy - radius <= toolbar.BoundaryLimit()) {
		circle.setPosition(sf::Vector2f(mouseposx - radius, toolbar.BoundaryLimit() + 2));
	}
	createwindow.draw(circle);
}


void Magenta::drawpaint(sf::RenderWindow &createwindow, const Toolbar& toolbar) {
	uint8_t radius = minbrushradius;
	circle.setRadius(radius);
	circle.setFillColor(sf::Color::Magenta);
	circle.setPosition(sf::Vector2f(mouseposx - radius, mouseposy - radius));
	if (mouseposy - radius <= toolbar.BoundaryLimit()) {
		circle.setPosition(sf::Vector2f(mouseposx - radius, toolbar.BoundaryLimit() + 2));
	}
	createwindow.draw(circle);
}



void Cyan::drawpaint(sf::RenderWindow &createwindow, const Toolbar& toolbar) {
	uint8_t radius = minbrushradius;
	circle.setRadius(radius);
	circle.setFillColor(sf::Color::Cyan);
	circle.setPosition(sf::Vector2f(mouseposx - radius, mouseposy - radius));
	if (mouseposy - radius <= toolbar.BoundaryLimit()) {
		circle.setPosition(sf::Vector2f(mouseposx - radius, toolbar.BoundaryLimit() + 2));
	}
	createwindow.draw(circle);
}


void Green::drawpaint(sf::RenderWindow &createwindow, const Toolbar& toolbar) {
	uint8_t radius = minbrushradius;
	circle.setRadius(radius);
	circle.setFillColor(sf::Color::Green);
	circle.setPosition(sf::Vector2f(mouseposx - radius, mouseposy - radius));
	if (mouseposy - radius <= toolbar.BoundaryLimit()) {
		circle.setPosition(sf::Vector2f(mouseposx - radius, toolbar.BoundaryLimit() + 2));
	}
	createwindow.draw(circle);
}



void White::drawpaint(sf::RenderWindow &createwindow, const Toolbar& toolbar) {
	uint8_t radius = minbrushradius;
	circle.setRadius(radius);
	circle.setFillColor(sf::Color::White);
	circle.setPosition(sf::Vector2f(mouseposx - radius, mouseposy - radius));
	if (mouseposy - radius <= toolbar.BoundaryLimit()) {
		circle.setPosition(sf::Vector2f(mouseposx - radius, toolbar.BoundaryLimit() + 2));
	}
	createwindow.draw(circle);

}