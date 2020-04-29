#include "Paint.h"
#include <iostream>

Paint::Paint(Paint* prev)
{
	if (prev) {
		radius = prev->getPaintColour();
	}
	else {
		radius = minbrushradius;
	}

	/*insert to unordered map*/
	colourmap.insert(std::make_pair(draw::redpaint, sf::Color::Red));
	colourmap.insert(std::make_pair(draw::blackpaint, sf::Color::Black));
	colourmap.insert(std::make_pair(draw::greenpaint, sf::Color::Green));
	colourmap.insert(std::make_pair(draw::cyanpaint, sf::Color::Cyan));
	colourmap.insert(std::make_pair(draw::bluepaint, sf::Color::Blue));
	colourmap.insert(std::make_pair(draw::magentapaint, sf::Color::Magenta));
	colourmap.insert(std::make_pair(draw::yellowpaint, sf::Color::Yellow));
	colourmap.insert(std::make_pair(draw::whitepaint, sf::Color::White));
}

void Paint::resize(const sf::Mouse& mouse, sf::RenderWindow& createwindow) //resize the paint. Performs bound checks
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

		if (radius >= maxbrushradius) {
			radius = maxbrushradius;
		}
		else {
			radius++;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		radius--;

		if (radius <= minbrushradius) {
			radius = minbrushradius;
		}
		else{
			radius--;
		}
	}

	circle.setRadius(radius);
	circle.setPosition(sf::Vector2f(mouseposx - radius, mouseposy - radius));
}

void Paint::clampMousePos()
{
	if (mouseposy - radius <= Limit) {
		mouseposy = (Limit + 2) + radius;			//+ radius to compensate for - radius in the setPosition for circle.
	}
}

void Paint::setPaintColour(draw d)
{
	auto findcolor = colourmap.find(d);
	if (findcolor != colourmap.end()) {
		circleColor = findcolor->second;
	}
	else {
		circleColor = sf::Color::Black;
	}

	circle.setFillColor(circleColor);
}

void Paint::setMousePos(const sf::Mouse& mouse, sf::RenderWindow &createwindow) {
	mouseposx = mouse.getPosition(createwindow).x;
	mouseposy = mouse.getPosition(createwindow).y;
}

void Paint::drawEntity(sf::RenderWindow & createwindow)
{
	createwindow.draw(circle);
}

Paint::~Paint()
{}

int Paint::getPaintColour() const
{
	return radius;
	
}
