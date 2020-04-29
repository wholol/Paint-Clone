#pragma once
#include "Toolbar.h"
#include "Entity.h"
#include <random>
#include <unordered_map>

class AirBrush: public Entity {

public:

	AirBrush(AirBrush* prev);			//construct vertex array of points.
	void drawEntity(sf::RenderWindow& createwindow) override;
	void resize(const sf::Mouse& mouse, sf::RenderWindow& createwindow) override;
	void setMousePos(sf::RenderWindow& createwindow, const sf::Mouse& mouse);
	void clampMousePos();
	void generatePoints(sf::RenderWindow& createwindow, const sf::Mouse& mouse);
	void setAirBrushColour(draw d);
	~AirBrush();

private:
	sf::VertexArray points;			//points for vertexarray

	/*rng pixels*/
	int posxpixel_1;
	int posypixel_1;
	int posxpixel_2;
	int posypixel_2;
	int posxpixel_3;
	int posypixel_3;
	int posxpixel_4;
	int posypixel_4;

	static constexpr uint8_t AirBrushMinDimension = 25;			//25 x 25  (minimum dimensions)
	static constexpr uint8_t AirBrushMaxDimension = 75;			//25 x 25 (maximum dimensions)
	int AirBrushCurrentDimension;
	std::unordered_map<draw, sf::Color> colourmap;				//hashmap to choose colour
	std::mt19937 rng;
	std::uniform_int_distribution<int> xpos;
	std::uniform_int_distribution<int> ypos;
	sf::Color AirBrushColour;						//color for the airbrush
	int getAirBrushDimension() const;
};