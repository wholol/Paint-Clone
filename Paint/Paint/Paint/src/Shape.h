#pragma once
#include <SFML/Graphics.hpp>
#include "Toolbar.h"
#include "Entity.h"
#include <iostream>
struct Shape : public Entity {
	
	struct location {		//location variables
		int posx;
		int posy;

		void setLoc(const sf::Mouse& mousepos, sf::RenderWindow& createwindow) {		//set location 
			this->posx = mousepos.getPosition(createwindow).x;
			this->posy = mousepos.getPosition(createwindow).y;
		}
	};

	struct node {			//node variables
		location loc;		//location
	};

	std::vector<node> storenodes;			//store node characteristics for a shape
	std::vector<sf::CircleShape> circlepoints;	//stores the nodes for circles
	int maxnodes;								//set the max number of nodes.
	static constexpr uint8_t pointradius = 4;	//node radius

	void makenode(const sf::Mouse& mousepos, sf::RenderWindow& createwindow);
	virtual void setMousePos(const sf::Mouse& mouse, sf::RenderWindow &createwindow);		
	virtual void clampMousePos();
	void resize(const sf::Mouse& mouse, sf::RenderWindow& createwindow) override;	

	~Shape();
};

struct line : public Shape {
	line();
	void drawEntity(sf::RenderWindow& createwindow) override;
	~line();
};

struct cube : public Shape {
	cube();
	void drawEntity(sf::RenderWindow& createwindow) override;
	~cube();
};

struct circle : public Shape {

	circle();
	void drawEntity(sf::RenderWindow& createwindow) override;
	void setMousePos(const sf::Mouse& mouse, sf::RenderWindow &createwindow) override;
	~circle();
};

struct spline : public Shape {
	bool drawsecondline = false;
	spline();
	void drawEntity(sf::RenderWindow& createwindow) override;
	void setMousePos(const sf::Mouse& mouse, sf::RenderWindow &createwindow) override;
	~spline();
};

