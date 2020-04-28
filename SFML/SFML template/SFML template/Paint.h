#pragma once
#include <SFML\Graphics.hpp>
#include <unordered_map>
#include "Toolbar.h"
#include "Entity.h"

class Paint : public Entity {

public:
	Paint();
	virtual void setMousePos(const sf::Mouse& mouse, sf::RenderWindow &createwindow);
	void drawEntity(sf::RenderWindow &createwindow, const Toolbar& toolbar) override;
	void resize(const sf::Mouse& mouse, sf::RenderWindow& createwindow, const Toolbar& toolbar) override;	//inhrtied from entity : resize brush
	void setColour(draw d);
	~Paint();

private:


	static constexpr uint8_t minbrushradius = 25;		//maximum radius of the brush.
	static constexpr uint8_t maxbrushradius = 50;	//minimum radius of the brush.
	int mouseposx, mouseposy, circlesize;
	sf::CircleShape circle;		//create circle object for the paint.
	std::unordered_map<draw, sf::Color> colourmap;		//stores a map for th colours.
	sf::Color circleColor;		//circle colour
};
