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
	if (mouse.getPosition(createwindow).y <= toolbar.BoundaryLimit()) {
		mouseposx = mouse.getPosition(createwindow).x;
		mouseposy = toolbar.BoundaryLimit();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		
		if (AirBrushCurrentDimension >= AirBrushMaxDimension) {
			AirBrushCurrentDimension = AirBrushMaxDimension - 1;		//prvent array overflow
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

void AirBrush::generatePoints(sf::RenderWindow& createwindow, const sf::Mouse& mouse)
{
	posxpixel_1 = xpos(rng);
	while (posxpixel_1 > AirBrushCurrentDimension){
		posxpixel_1 = xpos(rng);
	}

	posypixel_1 = ypos(rng);			//generates pixels within brush size
	while (posypixel_1 > AirBrushCurrentDimension ) {
		posypixel_1 = ypos(rng);
	}

	points[posxpixel_1 * AirBrushCurrentDimension + posypixel_1].position = sf::Vector2f(mouseposx + posxpixel_1, mouseposy + posypixel_1);
	points[posxpixel_1 * AirBrushCurrentDimension + posypixel_1].color = sf::Color::Red;

	posxpixel_2 = xpos(rng);
	while (posxpixel_2 > AirBrushCurrentDimension) {
		posxpixel_2 = xpos(rng);
	}

	posypixel_2 = ypos(rng);			//generates pixels within brush size
	while (posypixel_2 > AirBrushCurrentDimension) {
		posypixel_2 = ypos(rng);
	}

	points[posxpixel_2 * AirBrushCurrentDimension + posypixel_2].position = sf::Vector2f(mouseposx + posxpixel_2, mouseposy + posypixel_2);
	points[posxpixel_2 * AirBrushCurrentDimension + posypixel_2].color = sf::Color::Red;

	posxpixel_3 = xpos(rng);
	while (posxpixel_3 > AirBrushCurrentDimension) {
		posxpixel_3 = xpos(rng);
	}

	posypixel_3 = ypos(rng);			//generates pixels within brush size
	while (posypixel_3 > AirBrushCurrentDimension) {
		posypixel_3 = ypos(rng);
	}

	points[posxpixel_3 * AirBrushCurrentDimension + posypixel_3].position = sf::Vector2f(mouseposx + posxpixel_3, mouseposy + posypixel_3);
	points[posxpixel_3 * AirBrushCurrentDimension + posypixel_3].color = sf::Color::Red;
	createwindow.draw(points);
}

AirBrush::~AirBrush()
{
}
