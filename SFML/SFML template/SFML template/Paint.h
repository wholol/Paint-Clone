#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Toolbar.h"


struct Paint {

	Paint();
	static constexpr uint8_t minbrushradius = 25;		//maximum radius of the brush.
	static constexpr uint8_t maxbrushradius = 50;	//minimum radius of the brush.
	int mouseposx, mouseposy, circlesize;
	
	sf::CircleShape circle;		//create circle object for the paint.
	void ChangeBrushSize();
	virtual void drawpaint(sf::RenderWindow& createwindow,const Toolbar& toolbar) = 0;
	virtual void setMousePos(const sf::Mouse& mouse, sf::RenderWindow &createwindow);
};

struct Red :public Paint {	
	void drawpaint(sf::RenderWindow &createwindow, const Toolbar& toolbar) override;
};

struct Yellow : public Paint {
	void drawpaint(sf::RenderWindow &createwindow, const Toolbar& toolbar) override;
	
};

struct Blue :public Paint {
	void drawpaint(sf::RenderWindow &createwindow, const Toolbar& toolbar) override;

};

struct Black :public Paint {
	void drawpaint(sf::RenderWindow &createwindow, const Toolbar& toolbar) override;

};

struct Magenta :public Paint {
	void drawpaint(sf::RenderWindow &createwindow, const Toolbar& toolbar) override;

};

struct Cyan :public Paint {
	void drawpaint(sf::RenderWindow &createwindow, const Toolbar& toolbar) override;

};

struct Green :public Paint {
	void drawpaint(sf::RenderWindow &createwindow, const Toolbar& toolbar) override;

};

struct White :public Paint {
	void drawpaint(sf::RenderWindow &createwindow, const Toolbar& toolbar) override;

};