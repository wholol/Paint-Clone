#pragma once
#include <SFML\Graphics.hpp>
#include "Toolbar.h"
#include "Entity.h"

struct Paint : public Entity {

	Paint();
	static constexpr uint8_t minbrushradius = 25;		//maximum radius of the brush.
	static constexpr uint8_t maxbrushradius = 50;	//minimum radius of the brush.
	int mouseposx, mouseposy, circlesize;
	sf::CircleShape circle;		//create circle object for the paint.

	virtual void setMousePos(const sf::Mouse& mouse, sf::RenderWindow &createwindow);
	void resize(const sf::Mouse& mouse, sf::RenderWindow& createwindow, const Toolbar& toolbar) override;	//inhrtied from entity : resize brush
	~Paint();
};

struct Red :public Paint {	
	void drawEntity(sf::RenderWindow &createwindow, const Toolbar& toolbar) override;
	~Red();
};

struct Yellow : public Paint {
	void drawEntity(sf::RenderWindow &createwindow, const Toolbar& toolbar) override;
	~Yellow();
};

struct Blue :public Paint {
	void drawEntity(sf::RenderWindow &createwindow, const Toolbar& toolbar) override;
	~Blue();
};

struct Black :public Paint {
	void drawEntity(sf::RenderWindow &createwindow, const Toolbar& toolbar) override;
	~Black();
};

struct Magenta :public Paint {
	void drawEntity(sf::RenderWindow &createwindow, const Toolbar& toolbar) override;
	~Magenta();
};

struct Cyan :public Paint {
	void drawEntity(sf::RenderWindow &createwindow, const Toolbar& toolbar) override;
	~Cyan();
};

struct Green :public Paint {
	void drawEntity(sf::RenderWindow &createwindow, const Toolbar& toolbar) override;
	~Green();
};

struct White :public Paint {
	void drawEntity(sf::RenderWindow &createwindow, const Toolbar& toolbar) override;
	~White();
};