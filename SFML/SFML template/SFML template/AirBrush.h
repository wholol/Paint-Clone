#pragma once
#include "Toolbar.h"
#include "Entity.h"
#include <random>
class AirBrush: public Entity {

public:
	AirBrush();			//construct vertex array of points.
	void drawEntity(sf::RenderWindow& createwindow, const Toolbar& toolbar) override;
	void resize(const sf::Mouse& mouse, sf::RenderWindow& createwindow, const Toolbar& toolbar) override;
	void setMousePos(sf::RenderWindow& createwindow, const sf::Mouse& mouse);
	void generatePoints(sf::RenderWindow& createwindow, const sf::Mouse& mouse);
	~AirBrush();

private:
	sf::VertexArray points;
	int mouseposx;
	int mouseposy;			
	int posxpixel;
	int posypixel;
	static constexpr uint8_t AirBrushMinDimension = 25;			//25 x 25  (minimum dimensions)
	static constexpr uint8_t AirBrushMaxDimension = 75;			//25 x 25 (maximum dimensions)
	int AirBrushCurrentDimension;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xpos;
	std::uniform_int_distribution<int> ypos;


};