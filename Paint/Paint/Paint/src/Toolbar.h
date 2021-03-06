#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include <map>

//this class draws the menu and choosing the features
enum class draw {
	nothing,
	line,
	cube,
	rect,
	spline,
	circle,
	redpaint,
	yellowpaint,
	bluepaint,
	blackpaint,
	magentapaint,
	cyanpaint,
	greenpaint,
	whitepaint,
	clear,
	text,
	airbrush,
	paint
};

class Toolbar {

public:

	Toolbar(int screenwidth, int screenheight);
	void DrawMenuBar(sf::RenderWindow& createwindow);
	draw ChooseFeature(const sf::Mouse& mouse , sf::RenderWindow& createwindow);		//chooses the feature based on the mouse input
	int BoundaryLimit() const;		//boundary for the items to draw

private:

	std::map<std::pair<int, int>, sf::Color> colormap;		//stores the color map based on x and y coordinates.
	int PaintTileWidth;	
	int PaintTileHeight;
	sf::Sprite shapesprite;
	sf::Texture shapetext;
	sf::Sprite miscsprite;
	sf::Texture misctext;
	sf::RectangleShape drawrect;
	

};