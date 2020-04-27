#include "AirBrush.h"

AirBrush::AirBrush()
	:points(sf::Points, AirBrushMaxDimension * AirBrushMaxDimension),
	rng(std::random_device() ()),
	xpos(0 , AirBrushMaxDimension),
	ypos(0, AirBrushMaxDimension),
	AirBrushCurrentDimension(AirBrushMinDimension)		//initialize current dimenison to the mallest dimension
{}

void AirBrush::drawEntity(sf::RenderWindow& createwindow, const Toolbar& toolbar)
{
	createwindow.draw(points);
}

void AirBrush::resize(const sf::Mouse& mouse, sf::RenderWindow& createwindow, const Toolbar& toolbar)		//resize brush size
{
	if (toolbar.BoundaryLimit()) {
		mouseposx = mouse.getPosition(createwindow).x;
		mouseposy = toolbar.BoundaryLimit();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		AirBrushCurrentDimension++;
		if (AirBrushCurrentDimension >= AirBrushMaxDimension) {
			AirBrushCurrentDimension = AirBrushMaxDimension;
		}
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		AirBrushCurrentDimension--;
		if (AirBrushCurrentDimension >= AirBrushMinDimension) {
			AirBrushCurrentDimension = AirBrushMinDimension;
		}
	}
}

void AirBrush::setMousePos(sf::RenderWindow& createwindow, const sf::Mouse& mouse)
{
	mouseposx = mouse.getPosition(createwindow).x;
	mouseposy = mouse.getPosition(createwindow).y;
}

void AirBrush::generatePoints(sf::RenderWindow& createwindow, const sf::Mouse& mouse)
{
	posxpixel = xpos(rng);
	while (posxpixel > AirBrushCurrentDimension) {
		posxpixel = xpos(rng);
	}

	posypixel = ypos(rng);
	while (posypixel > AirBrushCurrentDimension) {
		posypixel = ypos(rng);
	}

	points[posxpixel * AirBrushCurrentDimension + posypixel].position = sf::Vector2f(posxpixel, posypixel);
	points[posxpixel * AirBrushCurrentDimension + posypixel].color = sf::Color::Red;
	createwindow.draw(points);
}

AirBrush::~AirBrush()
{
}
