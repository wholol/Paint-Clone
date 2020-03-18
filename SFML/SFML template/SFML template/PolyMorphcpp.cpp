#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>


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
	Shape* parent;		//pointer to the parent node, i.e. this pointer
};


struct Shape {		

	std::vector<node> storenodes;			//store node characteristics for a shape
	std::vector<sf::CircleShape> circlepoints;	//stores the nodes for circles

	int maxnodes;							//set the max number of nodes.
	static constexpr int pointradius = 4;	//node radius
	

	void makenode( const sf::Mouse& mousepos,sf::RenderWindow& createwindow) {		//get the pointer of the node
		node newnode;
		newnode.loc.setLoc(mousepos, createwindow);			//set the location of the newnode		
		newnode.parent = this;					//let the parent be the current instance
		if (storenodes.size() < maxnodes) {
			storenodes.emplace_back(newnode);
		}
	}

	void resizeShapes(const sf::Mouse& mouse,sf::RenderWindow& createwindow) {	
		for (int i = 0; i < storenodes.size(); ++i) {	//for each node
			
			if (sqrt(pow(storenodes[i].loc.posx - mouse.getPosition(createwindow).x, 2) + pow(storenodes[i].loc.posy - mouse.getPosition(createwindow).y, 2)) < 30.0f ) {
				circlepoints[i].setFillColor(sf::Color::Cyan);
				storenodes[i].loc.posx = mouse.getPosition(createwindow).x;
				storenodes[i].loc.posy = mouse.getPosition(createwindow).y;
			}

			else {
				circlepoints[i].setFillColor(sf::Color::Red);
				
			}
		}
	}

	virtual void drawshape(sf::RenderWindow& createwindow) = 0;		//indicate that there are different draw shape fucntions

};

struct line : public Shape {		//draw line
	
	
	line()		//constructor
	{
		maxnodes = 2;				//lt the maximum umber of nodes be two.
		storenodes.reserve(maxnodes);	//prevent reallocation
		for (int i = 0; i < maxnodes; ++i) {		//construct node points
			circlepoints.emplace_back(pointradius);
			circlepoints[i].setFillColor(sf::Color::Red);
		}
	};
	
	void drawshape(sf::RenderWindow& createwindow) override {
		sf::Vertex line[] = {sf::Vector2f(storenodes[0].loc.posx  , storenodes[0].loc.posy) ,
		sf::Vector2f(storenodes[1].loc.posx , storenodes[1].loc.posy)
		};

		for (int i = 0; i < maxnodes; ++i) {			
			circlepoints[i].setPosition(sf::Vector2f(storenodes[i].loc.posx - pointradius, storenodes[i].loc.posy - pointradius));
			createwindow.draw(circlepoints[i]);
		}
		createwindow.draw(line, 2, sf::Lines);	
	}

};

struct cube : public Shape {		//draw rectanle or cube

	cube(){
		maxnodes = 2;
		storenodes.reserve(maxnodes);		//prevent reallocation.
		for (int i = 0; i < maxnodes; ++i) {
			circlepoints.emplace_back(pointradius);
			circlepoints[i].setFillColor(sf::Color::Red);
		}
	};
	
	void drawshape(sf::RenderWindow& createwindow) override {

		for (int i = 0; i < maxnodes; ++i) {
			circlepoints[i].setPosition(sf::Vector2f(storenodes[i].loc.posx - pointradius, storenodes[i].loc.posy - pointradius));
			createwindow.draw(circlepoints[i]);
		}

		//draw lines
		sf::Vertex horizontal_line_1[] = { sf::Vector2f(storenodes[0].loc.posx  , storenodes[0].loc.posy) ,
		sf::Vector2f(storenodes[1].loc.posx , storenodes[0].loc.posy)
		};

		sf::Vertex horizontal_line_2[] = { sf::Vector2f(storenodes[0].loc.posx  , storenodes[0].loc.posy) ,
		sf::Vector2f(storenodes[0].loc.posx , storenodes[1].loc.posy)
		};

		sf::Vertex vertical_line_1[] = { sf::Vector2f(storenodes[1].loc.posx  , storenodes[0].loc.posy) ,
		sf::Vector2f(storenodes[1].loc.posx , storenodes[1].loc.posy)
		};

		sf::Vertex vertical_line_2[] = { sf::Vector2f(storenodes[0].loc.posx  , storenodes[1].loc.posy) ,
		sf::Vector2f(storenodes[1].loc.posx , storenodes[1].loc.posy)
		};

		createwindow.draw(horizontal_line_1, 2, sf::Lines);
		createwindow.draw(vertical_line_1, 2, sf::Lines);
		createwindow.draw(horizontal_line_2, 2, sf::Lines);
		createwindow.draw(vertical_line_2, 2, sf::Lines);
	}

};


struct circle : public Shape {
	circle()
	{
		maxnodes = 2;
		storenodes.reserve(maxnodes);
		for (int i = 0; i < maxnodes; ++i) {
			circlepoints.emplace_back(pointradius);
			circlepoints[i].setFillColor(sf::Color::Red);
		}
	};

	void drawshape(sf::RenderWindow& createwindow) override {
		
		sf::VertexArray points(sf::LinesStrip, 720);
		
		for (int i = 0; i < maxnodes; ++i) {
			circlepoints[i].setPosition(sf::Vector2f(storenodes[i].loc.posx - pointradius, storenodes[i].loc.posy - pointradius));
			createwindow.draw(circlepoints[i]);
		}
		
		float radius = sqrt(pow(storenodes[1].loc.posx - storenodes[0].loc.posx, 2.0f) + pow(storenodes[1].loc.posy - storenodes[0].loc.posy, 2.0f));	//get the radius

		for (int i = 0; i < 720; ++i) {
			points[i].position = {  sf::Vector2f(storenodes[0].loc.posx + radius*cos((i/2) * (3.14159 / 180)),storenodes[0].loc.posy + radius*sin((i/2) * (3.14159 / 180))) };
		}

		sf::Vertex complete_circle[] = { points[0].position , points[719].position };		//join last and first point

		createwindow.draw(complete_circle, 2, sf::Lines);
		createwindow.draw(points);
		
	}

};



struct spline : public Shape {
	
	int pointCounter = 1;		//count the number of points.
	spline() {
		maxnodes = 3;
		storenodes.reserve(maxnodes);
		for (int i = 0; i < maxnodes; ++i) {
			circlepoints.emplace_back(pointradius);
			circlepoints[i].setFillColor(sf::Color::Red);
		}
	}
		
		void drawshape(sf::RenderWindow& createwindow) override {

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

			sf::Vertex line_1[] = { sf::Vector2f(storenodes[0].loc.posx  , storenodes[0].loc.posy) ,
			sf::Vector2f(storenodes[1].loc.posx , storenodes[1].loc.posy)
			};
			
			sf::Vertex line_2[] = { sf::Vector2f(storenodes[1].loc.posx  , storenodes[1].loc.posy) ,
			sf::Vector2f(storenodes[2].loc.posx , storenodes[2].loc.posy)
			};

			createwindow.draw(splinepoints);
			//createwindow.draw(line_1, 2, sf::Lines);
			//createwindow.draw(line_2, 2, sf::Lines);
		}
};