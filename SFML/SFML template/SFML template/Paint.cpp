#pragma once
#include "Paint.h"

Paint::Paint() 
	:circle(minbrushradius)
{
}

void Paint::resize(const sf::Mouse& mouse, sf::RenderWindow& createwindow, const Toolbar& toolbar) 
{
	//TO BE DONE
}

Paint::~Paint()
{
}


void Paint::setMousePos(const sf::Mouse& mouse, sf::RenderWindow &createwindow) {
	mouseposx = mouse.getPosition(createwindow).x;
	mouseposy = mouse.getPosition(createwindow).y;
}


void Red::drawEntity(sf::RenderWindow &createwindow,const Toolbar& toolbar) {
	
	uint8_t radius = minbrushradius;
	circle.setRadius(radius);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(sf::Vector2f(mouseposx - radius , mouseposy - radius));
	if (mouseposy - radius <= toolbar.BoundaryLimit()) {
		circle.setPosition(sf::Vector2f(mouseposx - radius, toolbar.BoundaryLimit() + 2));
	}
	createwindow.draw(circle);
}

Red::~Red()
{
}


void Yellow::drawEntity(sf::RenderWindow &createwindow, const Toolbar& toolbar) {
	uint8_t radius = minbrushradius;
	circle.setRadius(radius);
	circle.setFillColor(sf::Color::Yellow);
	circle.setPosition(sf::Vector2f(mouseposx - radius, mouseposy - radius));
	if (mouseposy - radius <= toolbar.BoundaryLimit()) {
		circle.setPosition(sf::Vector2f(mouseposx - radius, toolbar.BoundaryLimit() + 2));
	}
	createwindow.draw(circle);

}

Yellow::~Yellow()
{
}

void Blue::drawEntity(sf::RenderWindow &createwindow, const Toolbar& toolbar) {
	uint8_t radius = minbrushradius;
	circle.setRadius(radius);
	circle.setFillColor(sf::Color::Blue);
	circle.setPosition(sf::Vector2f(mouseposx - radius, mouseposy - radius));
	if (mouseposy - radius <= toolbar.BoundaryLimit()) {
		circle.setPosition(sf::Vector2f(mouseposx - radius, toolbar.BoundaryLimit() + 2));
	}
	createwindow.draw(circle);

}

Blue::~Blue()
{
}



void Black::drawEntity(sf::RenderWindow &createwindow, const Toolbar& toolbar) {
	uint8_t radius = minbrushradius;
	circle.setRadius(radius);
	circle.setFillColor(sf::Color::Black);
	circle.setPosition(sf::Vector2f(mouseposx - radius, mouseposy - radius));
	if (mouseposy - radius <= toolbar.BoundaryLimit()) {
		circle.setPosition(sf::Vector2f(mouseposx - radius, toolbar.BoundaryLimit() + 2));
	}
	createwindow.draw(circle);
}

Black::~Black()
{
}

void Magenta::drawEntity(sf::RenderWindow &createwindow, const Toolbar& toolbar) {
	uint8_t radius = minbrushradius;
	circle.setRadius(radius);
	circle.setFillColor(sf::Color::Magenta);
	circle.setPosition(sf::Vector2f(mouseposx - radius, mouseposy - radius));
	if (mouseposy - radius <= toolbar.BoundaryLimit()) {
		circle.setPosition(sf::Vector2f(mouseposx - radius, toolbar.BoundaryLimit() + 2));
	}
	createwindow.draw(circle);
}

Magenta::~Magenta()
{
}


void Cyan::drawEntity(sf::RenderWindow &createwindow, const Toolbar& toolbar) {
	uint8_t radius = minbrushradius;
	circle.setRadius(radius);
	circle.setFillColor(sf::Color::Cyan);
	circle.setPosition(sf::Vector2f(mouseposx - radius, mouseposy - radius));
	if (mouseposy - radius <= toolbar.BoundaryLimit()) {
		circle.setPosition(sf::Vector2f(mouseposx - radius, toolbar.BoundaryLimit() + 2));
	}
	createwindow.draw(circle);
}

Cyan::~Cyan()
{
}


void Green::drawEntity(sf::RenderWindow &createwindow, const Toolbar& toolbar) {
	uint8_t radius = minbrushradius;
	circle.setRadius(radius);
	circle.setFillColor(sf::Color::Green);
	circle.setPosition(sf::Vector2f(mouseposx - radius, mouseposy - radius));
	if (mouseposy - radius <= toolbar.BoundaryLimit()) {
		circle.setPosition(sf::Vector2f(mouseposx - radius, toolbar.BoundaryLimit() + 2));
	}
	createwindow.draw(circle);
}

Green::~Green()
{
}


void White::drawEntity(sf::RenderWindow &createwindow, const Toolbar& toolbar) {
	uint8_t radius = minbrushradius;
	circle.setRadius(radius);
	circle.setFillColor(sf::Color::White);
	circle.setPosition(sf::Vector2f(mouseposx - radius, mouseposy - radius));
	if (mouseposy - radius <= toolbar.BoundaryLimit()) {
		circle.setPosition(sf::Vector2f(mouseposx - radius, toolbar.BoundaryLimit() + 2));
	}
	createwindow.draw(circle);

}

White::~White()
{
}
