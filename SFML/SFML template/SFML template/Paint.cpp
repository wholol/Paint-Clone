#include "Paint.h"
#include <iostream>

Paint::Paint()
	:circle(minbrushradius)				//construct brushradius
{
	/*insert to unordered map*/
	colourmap.insert(std::make_pair(draw::redpaint, sf::Color::Red));
	colourmap.insert(std::make_pair(draw::blackpaint, sf::Color::Black));
	colourmap.insert(std::make_pair(draw::greenpaint, sf::Color::Green));
	colourmap.insert(std::make_pair(draw::cyanpaint, sf::Color::Cyan));
	colourmap.insert(std::make_pair(draw::bluepaint, sf::Color::Red));
	colourmap.insert(std::make_pair(draw::magentapaint, sf::Color::Magenta));
	colourmap.insert(std::make_pair(draw::yellowpaint, sf::Color::Yellow));
	colourmap.insert(std::make_pair(draw::whitepaint, sf::Color::White));

	
}

void Paint::resize(const sf::Mouse& mouse, sf::RenderWindow& createwindow, const Toolbar& toolbar) //resize the paint. Performs bound checks
{
	uint8_t radius = minbrushradius;
	circle.setRadius(radius);
	circle.setPosition(sf::Vector2f(mouseposx - radius, mouseposy - radius));
	if (mouseposy - radius <= toolbar.BoundaryLimit()) {
		circle.setPosition(sf::Vector2f(mouseposx - radius, toolbar.BoundaryLimit() + 2));
	}
}

void Paint::setColour(draw d)
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

sf::Color Paint::getColour() const
{
	return circleColor;
}

void Paint::setMousePos(const sf::Mouse& mouse, sf::RenderWindow &createwindow) {
	mouseposx = mouse.getPosition(createwindow).x;
	mouseposy = mouse.getPosition(createwindow).y;
}

void Paint::drawEntity(sf::RenderWindow & createwindow, const Toolbar& toolbar)
{
	createwindow.draw(circle);
}

Paint::~Paint()
{}
