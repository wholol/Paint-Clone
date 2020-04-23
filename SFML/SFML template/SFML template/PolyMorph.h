#pragma once
#include <SFML/Graphics.hpp>
#include "Toolbar.h"

struct Shape;

struct location {		//location variables
	float posx;
	float posy;

	void setLoc(const sf::Mouse& mousepos, sf::RenderWindow& createwindow) {		//set location 
		this->posx = mousepos.getPosition(createwindow).x;
		this->posy = mousepos.getPosition(createwindow).y;
	}
};

struct node {			//node variables
	location loc;		//location
};

struct Shape {
	public:
	std::vector<node> storenodes;			//store node characteristics for a shape
	std::vector<sf::CircleShape> circlepoints;	//stores the nodes for circles

	int maxnodes;							//set the max number of nodes.
	static constexpr uint8_t pointradius = 4;	//node radius

	void makenode(const sf::Mouse& mousepos, sf::RenderWindow& createwindow);
	void resizeShapes(const sf::Mouse& mouse, sf::RenderWindow& createwindow);
	virtual void drawshape(sf::RenderWindow& createwindow,const Toolbar& toolbar) = 0;		//indicate that there are different draw shape fucntions
};

struct line : public Shape {

	line();
	void drawshape(sf::RenderWindow& createwindow, const Toolbar& toolbar) override;
};

struct cube : public Shape {
	cube();
	virtual void drawshape(sf::RenderWindow& createwindow, const Toolbar& toolbar)  override;
};

struct circle : public Shape {

	circle();
	virtual void drawshape(sf::RenderWindow& createwindow, const Toolbar& toolbar)  override;

};

struct spline : public Shape {
	spline();
	virtual void drawshape(sf::RenderWindow& createwindow, const Toolbar& toolbar)  override;
};