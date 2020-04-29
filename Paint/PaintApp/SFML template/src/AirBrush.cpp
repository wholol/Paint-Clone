#include "AirBrush.h"
#include <iostream>
AirBrush::AirBrush(AirBrush* prev)
	:points(sf::Points, AirBrushMaxDimension * AirBrushMaxDimension),
	rng(std::random_device() ()),
	xpos(0 , AirBrushMaxDimension),
	ypos(0, AirBrushMaxDimension)
{
	if (prev) {
		AirBrushCurrentDimension = prev->getAirBrushDimension();		//initialize current dimenison to the mallest dimension
	}
	else {
		AirBrushCurrentDimension = AirBrushMinDimension;
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

void AirBrush::drawEntity(sf::RenderWindow& createwindow)
{
	createwindow.draw(points);
}

void AirBrush::resize(const sf::Mouse& mouse, sf::RenderWindow& createwindow)		//resize brush size
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (AirBrushCurrentDimension >= AirBrushMaxDimension) {
			AirBrushCurrentDimension = AirBrushMaxDimension - 5;		//prvent array overflow
		}
		else {
			AirBrushCurrentDimension++;
		}
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (AirBrushCurrentDimension <= AirBrushMinDimension) {
			AirBrushCurrentDimension = AirBrushMinDimension;
		}
		else {
			AirBrushCurrentDimension--;
		}
	}
}

void AirBrush::setMousePos(sf::RenderWindow& createwindow, const sf::Mouse& mouse)
{
	mouseposx = mouse.getPosition(createwindow).x;
	mouseposy = mouse.getPosition(createwindow).y;
}

void AirBrush::clampMousePos()
{
	if (mouseposy <= Limit) {
		mouseposy = Limit;
	}
}

void AirBrush::generatePoints(sf::RenderWindow& createwindow, const sf::Mouse& mouse)		//generate points to paint on the canvas
{
	posxpixel_1 = xpos(rng);
	while (posxpixel_1 >= AirBrushCurrentDimension){
		posxpixel_1 = xpos(rng);
	}

	posypixel_1 = ypos(rng);			//generates pixels within brush size
	while (posypixel_1 >= AirBrushCurrentDimension ) {
		posypixel_1 = ypos(rng);
	}

	points[posxpixel_1 * AirBrushMaxDimension + posypixel_1].position = sf::Vector2f(mouseposx + posxpixel_1, mouseposy + posypixel_1);
	points[posxpixel_1 * AirBrushMaxDimension + posypixel_1].color = AirBrushColour;

	posxpixel_2 = xpos(rng);
	while (posxpixel_2 >= AirBrushCurrentDimension) {
		posxpixel_2 = xpos(rng);
	}

	posypixel_2 = ypos(rng);			//generates pixels within brush size
	while (posypixel_2 >= AirBrushCurrentDimension) {
		posypixel_2 = ypos(rng);
	}

	points[posxpixel_2 * AirBrushMaxDimension + posypixel_2].position = sf::Vector2f(mouseposx + posxpixel_2, mouseposy + posypixel_2);
	points[posxpixel_2 * AirBrushMaxDimension + posypixel_2].color = AirBrushColour;

	posxpixel_3 = xpos(rng);
	while (posxpixel_3 >= AirBrushCurrentDimension) {
		posxpixel_3 = xpos(rng);
	}

	posypixel_3 = ypos(rng);			//generates pixels within brush size
	while (posypixel_3 >= AirBrushCurrentDimension) {
		posypixel_3 = ypos(rng);
	}

	points[posxpixel_3 * AirBrushMaxDimension + posypixel_3].position = sf::Vector2f(mouseposx + posxpixel_3, mouseposy + posypixel_3);
	points[posxpixel_3 * AirBrushMaxDimension + posypixel_3].color = AirBrushColour;

	posxpixel_4 = xpos(rng);
	while (posxpixel_4 > AirBrushCurrentDimension) {
		posxpixel_4 = xpos(rng);
	}

	posypixel_4 = ypos(rng);			//generates pixels within brush size
	while (posypixel_4 > AirBrushCurrentDimension) {
		posypixel_4 = ypos(rng);
	}

	points[posxpixel_4 * AirBrushMaxDimension + posypixel_4].position = sf::Vector2f(mouseposx + posxpixel_4, mouseposy + posypixel_4);
	points[posxpixel_4 * AirBrushMaxDimension + posypixel_4].color = AirBrushColour;
	createwindow.draw(points);
}

void AirBrush::setAirBrushColour(draw d)
{
	auto findcolor = colourmap.find(d);
	if (findcolor != colourmap.end()) {
		AirBrushColour = findcolor->second;
	}
	else {
		AirBrushColour = sf::Color::Black;
	}
}

int AirBrush::getAirBrushDimension() const
{
	return AirBrushCurrentDimension;
}

AirBrush::~AirBrush()
{
}
