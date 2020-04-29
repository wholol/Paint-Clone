#pragma once
#include <SFML\Graphics.hpp>
#include <unordered_map>
#include "Toolbar.h"
#include "Entity.h"

class Paint : public Entity {

public:
	Paint(Paint* prev);
	void setMousePos(const sf::Mouse& mouse, sf::RenderWindow &createwindow);
	void drawEntity(sf::RenderWindow &createwindow) override;
	void resize(const sf::Mouse& mouse, sf::RenderWindow& createwindow) override;	
	void clampMousePos();																		//prevents textbox going off the boundary
	void setPaintColour(draw d);
	~Paint();

private:
	static constexpr uint8_t minbrushradius = 25;		//maximum radius of the brush.
	static constexpr uint8_t maxbrushradius = 50;		//minimum radius of the brush.
	uint8_t radius;										//current radius			
	sf::CircleShape circle;								//create circle object for the paint.
	std::unordered_map<draw, sf::Color> colourmap;		//stores a map for th colours.
	sf::Color circleColor;								//circle (paint) colour
	int getPaintColour() const;
};
