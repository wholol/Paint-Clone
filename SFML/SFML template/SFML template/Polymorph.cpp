#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "PolyMorph.h"
#include <iostream>

void Shape::makenode(const sf::Mouse& mousepos, sf::RenderWindow& createwindow) {		//get the pointer of the node
		node newnode;
		newnode.loc.setLoc(mousepos, createwindow);			//set the location of the newnode		
		if (storenodes.size() < maxnodes) {
			storenodes.emplace_back(newnode);
		}
}

void Shape::resizeShapes(const sf::Mouse& mouse, sf::RenderWindow& createwindow, const Toolbar& toolbar) {
	for (int i = 0; i < storenodes.size(); ++i) {	//for each node

		if (sqrt(pow(storenodes[i].loc.posx - mouse.getPosition(createwindow).x, 2) + pow(storenodes[i].loc.posy - mouse.getPosition(createwindow).y, 2)) < 30.0f) {
			circlepoints[i].setFillColor(sf::Color::Cyan);
			storenodes[i].loc.posx = mouse.getPosition(createwindow).x;
			storenodes[i].loc.posy = mouse.getPosition(createwindow).y;

		/*	if (typeid(*this).name() == "struct circle") {
				std::cout << "resize circle" << std::endl;
				float radius = sqrt(pow(storenodes[1].loc.posx - storenodes[0].loc.posx, 2.0f) + pow(storenodes[1].loc.posy - storenodes[0].loc.posy, 2.0f));
				if (storenodes[0].loc.posy - toolbar.BoundaryLimit() <= radius + 2) {			//check is radius exceeds the boundary
					float center2mouseradius = sqrt(pow(mouse.getPosition(createwindow).x - storenodes[0].loc.posx, 2.0f) + pow(mouse.getPosition(createwindow).y - storenodes[0].loc.posy, 2.0f));
					if (center2mouseradius < radius) {			//if the mouse position is lesser than the radius position
						this->storenodes[1].loc.posy = mouse.getPosition(createwindow).y;
						this->storenodes[1].loc.posx = mouse.getPosition(createwindow).x;
					}
				}
			}  */

			if (storenodes[i].loc.posy <= toolbar.BoundaryLimit()) {
				storenodes[i].loc.posy = toolbar.BoundaryLimit();
			}
		}
	
		else {
			circlepoints[i].setFillColor(sf::Color::Red);
		}
	}
}

void Shape::setMousePos(const sf::Mouse & mouse, sf::RenderWindow & createwindow, Shape & shape, const Toolbar & toolbar)
{
	if (shape.storenodes[1].loc.posy >= toolbar.BoundaryLimit()) {
		shape.storenodes[1].loc.posx = mouse.getPosition(createwindow).x;
		shape.storenodes[1].loc.posy = mouse.getPosition(createwindow).y;
	}

	if (shape.storenodes[1].loc.posy <= toolbar.BoundaryLimit()) {
		shape.storenodes[1].loc.posx = mouse.getPosition(createwindow).x;
		shape.storenodes[1].loc.posy = toolbar.BoundaryLimit();
	}
}

	
line::line() : Shape()		//constructor
{
	maxnodes = 2;				//lt the maximum umber of nodes be two.
	storenodes.reserve(maxnodes);	//prevent reallocation
}


void line::drawshape(sf::RenderWindow& createwindow, const Toolbar& toolbar){

	for (int i = 0; i < maxnodes; ++i) {		//construct node points
		circlepoints.emplace_back(pointradius);
		circlepoints[i].setFillColor(sf::Color::Red);
	}

	sf::Vertex line[] = {
	sf::Vertex(sf::Vector2f(storenodes[0].loc.posx  , storenodes[0].loc.posy) , sf::Color::Blue),
	sf::Vertex(sf::Vector2f(storenodes[1].loc.posx  , storenodes[1].loc.posy) , sf::Color::Blue)
	};

	for (int i = 0; i < maxnodes; ++i) {
		circlepoints[i].setPosition(sf::Vector2f(storenodes[i].loc.posx - pointradius, storenodes[i].loc.posy - pointradius));
		if (storenodes[i].loc.posy - pointradius <= toolbar.BoundaryLimit()) {
			circlepoints[i].setPosition(sf::Vector2f(storenodes[i].loc.posx - pointradius, toolbar.BoundaryLimit() + 2 - pointradius));
		}
		createwindow.draw(circlepoints[i]);
	}

	createwindow.draw(line, 2, sf::Lines);
}


cube::cube() : Shape() {
	maxnodes = 2;
	storenodes.reserve(maxnodes);		//prevent reallocation.
	for (int i = 0; i < maxnodes; ++i) {		//construct node points
		circlepoints.emplace_back(pointradius);
		circlepoints[i].setFillColor(sf::Color::Red);
	}
}


void cube::drawshape(sf::RenderWindow& createwindow, const Toolbar& toolbar)  {

	for (int i = 0; i < maxnodes; ++i) {
		circlepoints[i].setPosition(sf::Vector2f(storenodes[i].loc.posx - pointradius, storenodes[i].loc.posy - pointradius));
		createwindow.draw(circlepoints[i]);
	}

		sf::Vertex horizontal_line_1[] =
		{
			sf::Vertex(sf::Vector2f(storenodes[0].loc.posx  , storenodes[0].loc.posy), sf::Color::Blue),
			sf::Vertex(sf::Vector2f(storenodes[1].loc.posx , storenodes[0].loc.posy), sf::Color::Blue)
		};

		sf::Vertex horizontal_line_2[] =
		{
			sf::Vertex(sf::Vector2f(storenodes[0].loc.posx  , storenodes[0].loc.posy), sf::Color::Blue),
			sf::Vertex(sf::Vector2f(storenodes[0].loc.posx , storenodes[1].loc.posy), sf::Color::Blue)
		};

		sf::Vertex vertical_line_1[] =
		{
			sf::Vertex(sf::Vector2f(storenodes[1].loc.posx  , storenodes[0].loc.posy), sf::Color::Blue),
			sf::Vertex(sf::Vector2f(storenodes[1].loc.posx , storenodes[1].loc.posy), sf::Color::Blue)
		};

		sf::Vertex vertical_line_2[] =
		{
			sf::Vertex(sf::Vector2f(storenodes[0].loc.posx  , storenodes[1].loc.posy), sf::Color::Blue),
			sf::Vertex(sf::Vector2f(storenodes[1].loc.posx , storenodes[1].loc.posy), sf::Color::Blue)
		};
	
		createwindow.draw(horizontal_line_1, 2, sf::Lines);
		createwindow.draw(vertical_line_1, 2, sf::Lines);
		createwindow.draw(horizontal_line_2, 2, sf::Lines);
		createwindow.draw(vertical_line_2, 2, sf::Lines);
}

circle::circle() : Shape() {
	maxnodes = 2;
	storenodes.reserve(maxnodes);
}


void circle::drawshape(sf::RenderWindow& createwindow, const Toolbar& toolbar) {
	
	for (int i = 0; i < maxnodes; ++i) {
		circlepoints.emplace_back(pointradius);
		circlepoints[i].setFillColor(sf::Color::Red);
	}
		
	sf::VertexArray points(sf::LinesStrip, 720);
		
		for (int i = 0; i < maxnodes; ++i) {
			circlepoints[i].setPosition(sf::Vector2f(storenodes[i].loc.posx - pointradius, storenodes[i].loc.posy - pointradius));
			createwindow.draw(circlepoints[i]);
		}
		
		float radius = sqrt(pow(storenodes[1].loc.posx - storenodes[0].loc.posx, 2.0f) + pow(storenodes[1].loc.posy - storenodes[0].loc.posy, 2.0f));	//get the radius

		for (int i = 0; i < 720; ++i) {
			points[i].color = sf::Color::Blue;
			points[i].position = {  sf::Vector2f(storenodes[0].loc.posx + radius*cos((i/2) * (3.14159 / 180)),storenodes[0].loc.posy + radius*sin((i/2) * (3.14159 / 180))) };
		}
		
		sf::Vertex complete_circle[] = { points[0].position , points[719].position };		//join last and first point
		complete_circle->color = sf::Color::Blue;

		createwindow.draw(complete_circle, 2, sf::Lines);
		createwindow.draw(points);
}

void circle::setMousePos(const sf::Mouse & mouse, sf::RenderWindow & createwindow, Shape & shape, const Toolbar & toolbar)
{
	float radius = sqrt(pow(storenodes[1].loc.posx - storenodes[0].loc.posx, 2.0f) + pow(storenodes[1].loc.posy - storenodes[0].loc.posy, 2.0f));	//get the radius
	
	if (storenodes[0].loc.posy - toolbar.BoundaryLimit() <= radius + 2) {			//check is radius exceeds the boundary
		float center2mouseradius = sqrt(pow(mouse.getPosition(createwindow).x - storenodes[0].loc.posx, 2.0f) + pow(mouse.getPosition(createwindow).y - storenodes[0].loc.posy, 2.0f));
		if (center2mouseradius < radius) {			//if the mouse position is lesser than the radius position
			shape.storenodes[1].loc.posy = mouse.getPosition(createwindow).y;
			shape.storenodes[1].loc.posx = mouse.getPosition(createwindow).x;
		}
	}
	
	if (storenodes[0].loc.posy - toolbar.BoundaryLimit() >= radius + 2){
		shape.storenodes[1].loc.posx = mouse.getPosition(createwindow).x;
		shape.storenodes[1].loc.posy = mouse.getPosition(createwindow).y;
	}
	
}

spline::spline():Shape() {
	maxnodes = 3;
	storenodes.reserve(maxnodes);
	
}

void spline::drawshape(sf::RenderWindow& createwindow, const Toolbar& toolbar)  {

	for (int i = 0; i < maxnodes; ++i) {
		circlepoints.emplace_back(pointradius);
		circlepoints[i].setFillColor(sf::Color::Red);
	}
	
	for (int i = 0; i < maxnodes; ++i) {
			circlepoints[i].setPosition(sf::Vector2f(storenodes[i].loc.posx - pointradius, storenodes[i].loc.posy - pointradius));
			createwindow.draw(circlepoints[i]);
	}

		sf::VertexArray splinepoints(sf::LinesStrip);		//initialize 720 points
			
		for (float i = 0; i < 1; i+=0.01f) {
			float a = (1 - i) * (1 - i);
			float c = i * i;
			float b = 2 * (1 - i)* i;

			splinepoints.append(sf::Vector2f{ a * (storenodes[0].loc.posx) + b * (storenodes[1].loc.posx) + c * (storenodes[2].loc.posx) ,
				a * (storenodes[0].loc.posy) + b * (storenodes[1].loc.posy) + c * (storenodes[2].loc.posy)
				});
		}

		for (int i = 0; i < 100; ++i) {
			splinepoints[i].color = sf::Color::Blue;
		}

		createwindow.draw(splinepoints);
}

void spline::setMousePos(const sf::Mouse& mouse, sf::RenderWindow& createwindow, Shape& shape, const Toolbar& toolbar)
{

	if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) {
		drawsecondline = true;
	}

	if (drawsecondline) {
		shape.storenodes[2].loc.posx = mouse.getPosition(createwindow).x;		//move the newest node around
		shape.storenodes[2].loc.posy = mouse.getPosition(createwindow).y;		//move the newest node around
	}

	else {		//if second node is not put onto the screen yet
		if (shape.storenodes[1].loc.posy >= toolbar.BoundaryLimit()) {
			shape.storenodes[1].loc.posx = mouse.getPosition(createwindow).x;
			shape.storenodes[1].loc.posy = mouse.getPosition(createwindow).y;
		}

		if (shape.storenodes[1].loc.posy <= toolbar.BoundaryLimit()) {
			shape.storenodes[1].loc.posy = toolbar.BoundaryLimit();
		}
	}

	if (shape.storenodes[2].loc.posy >= toolbar.BoundaryLimit()) {
		shape.storenodes[2].loc.posx = mouse.getPosition(createwindow).x;
		shape.storenodes[2].loc.posy = mouse.getPosition(createwindow).y;
	}

	if (shape.storenodes[2].loc.posy <= toolbar.BoundaryLimit()) {
		shape.storenodes[2].loc.posy = toolbar.BoundaryLimit();
	}

}
