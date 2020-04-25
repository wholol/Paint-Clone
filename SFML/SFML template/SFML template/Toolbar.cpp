#include "Toolbar.h"


Toolbar::Toolbar(int screenwidth, int screenheight) :
	PaintTileWidth(screenwidth / 8),
	PaintTileHeight(PaintTileWidth / 2),
	drawrect(sf::Vector2f(PaintTileWidth, PaintTileHeight))
{
	shapetext.loadFromFile("shapetoolbar.png");
	shapesprite.setTexture(shapetext);
	misctext.loadFromFile("misctoolbar.png");
	miscsprite.setTexture(misctext);

	colormap.insert({ std::make_pair(4, 0), sf::Color::Red } );
	colormap.insert({ std::make_pair(4, 1), sf::Color::Yellow});
	colormap.insert({ std::make_pair(5, 0), sf::Color::Blue });
	colormap.insert({ std::make_pair(5, 1), sf::Color::Black });
	colormap.insert({ std::make_pair(6, 0), sf::Color::Magenta });
	colormap.insert({ std::make_pair(6, 1), sf::Color::Cyan });
	colormap.insert({ std::make_pair(7, 0), sf::Color::Green });
	colormap.insert({ std::make_pair(7, 1), sf::Color::White });	
}

void Toolbar::DrawMenuBar(sf::RenderWindow& createwindow) {


	createwindow.draw(shapesprite);

	miscsprite.setPosition(sf::Vector2f(0.0f, PaintTileHeight)); // absolute position
	createwindow.draw(miscsprite);

	/*draw boundary line*/
	sf::Vertex boundary_line[] =
	{
		sf::Vertex(sf::Vector2f(0.0f  , BoundaryLimit()), sf::Color::Blue),
		sf::Vertex(sf::Vector2f(PaintTileWidth * 8 , BoundaryLimit()), sf::Color::Blue)
	};

	createwindow.draw(boundary_line, 100 , sf::Lines);

	/*draw colour boxes*/
	for (int i = 4; i < 8; ++i) {		
		for (int j = 0; j < 2;  ++j) {
			drawrect.setOutlineColor(sf::Color::Black);
			drawrect.setPosition(i * PaintTileWidth, j * PaintTileHeight);
			drawrect.setOutlineThickness(-2);

			auto f = colormap.find(std::make_pair(i, j));

			if (f != colormap.end()) {
				drawrect.setFillColor(f->second);		//color of rectangle
			}
			else {
				continue;
			}
			createwindow.draw(drawrect);
		}
	}
}


draw Toolbar::ChooseFeature(const sf::Mouse& mouse, sf::RenderWindow& createwindow) {

	//choose the feature to be used

	//shapes features
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (mouse.getPosition(createwindow).x >= 0 && mouse.getPosition(createwindow).x <= PaintTileWidth && mouse.getPosition(createwindow).y >= 0 && mouse.getPosition(createwindow).y <= PaintTileHeight) {
			return draw::line;
		}

		if (mouse.getPosition(createwindow).x >= PaintTileWidth && mouse.getPosition(createwindow).x <= PaintTileWidth * 2 && mouse.getPosition(createwindow).y >= 0 && mouse.getPosition(createwindow).y <= PaintTileHeight) {
			return draw::cube;
		}

		if (mouse.getPosition(createwindow).x >= PaintTileWidth * 2 && mouse.getPosition(createwindow).x <= PaintTileWidth * 3 && mouse.getPosition(createwindow).y >= 0 && mouse.getPosition(createwindow).y <= PaintTileHeight) {
			return draw::spline;
		}

		if (mouse.getPosition(createwindow).x >= PaintTileWidth * 3 && mouse.getPosition(createwindow).x <= PaintTileWidth * 4 && mouse.getPosition(createwindow).y >= 0 && mouse.getPosition(createwindow).y <= PaintTileHeight) {
			return draw::circle;
		}

		//color features

		if (mouse.getPosition(createwindow).x >= PaintTileWidth * 4 && mouse.getPosition(createwindow).x <= PaintTileWidth * 5 && mouse.getPosition(createwindow).y >= 0 && mouse.getPosition(createwindow).y <= PaintTileHeight) {
			return draw::redpaint;
		}

		if (mouse.getPosition(createwindow).x >= PaintTileWidth * 4 && mouse.getPosition(createwindow).x <= PaintTileWidth * 5 && mouse.getPosition(createwindow).y >= PaintTileHeight && mouse.getPosition(createwindow).y <= PaintTileHeight * 2) {
			return draw::yellowpaint;
		}

		if (mouse.getPosition(createwindow).x >= PaintTileWidth * 5 && mouse.getPosition(createwindow).x <= PaintTileWidth * 6 && mouse.getPosition(createwindow).y >= 0 && mouse.getPosition(createwindow).y <= PaintTileHeight) {
			return draw::bluepaint;
		}

		if (mouse.getPosition(createwindow).x >= PaintTileWidth * 5 && mouse.getPosition(createwindow).x <= PaintTileWidth * 6 && mouse.getPosition(createwindow).y >= PaintTileHeight && mouse.getPosition(createwindow).y <= PaintTileHeight * 2) {
			return draw::blackpaint;
		}

		if (mouse.getPosition(createwindow).x >= PaintTileWidth * 6 && mouse.getPosition(createwindow).x <= PaintTileWidth * 7 && mouse.getPosition(createwindow).y >= 0 && mouse.getPosition(createwindow).y <= PaintTileHeight) {
			return draw::magentapaint;
		}

		if (mouse.getPosition(createwindow).x >= PaintTileWidth * 6 && mouse.getPosition(createwindow).x <= PaintTileWidth * 7 && mouse.getPosition(createwindow).y >= PaintTileHeight && mouse.getPosition(createwindow).y <= PaintTileHeight * 2) {
			return draw::cyanpaint;
		}

		if (mouse.getPosition(createwindow).x >= PaintTileWidth * 7 && mouse.getPosition(createwindow).x <= PaintTileWidth * 8 && mouse.getPosition(createwindow).y >= 0 && mouse.getPosition(createwindow).y <= PaintTileHeight) {
			return draw::greenpaint;
		}

		if (mouse.getPosition(createwindow).x >= PaintTileWidth * 7 && mouse.getPosition(createwindow).x <= PaintTileWidth * 8 && mouse.getPosition(createwindow).y >= PaintTileHeight && mouse.getPosition(createwindow).y <= PaintTileHeight * 2) {
			return draw::whitepaint;
		}


		//misc features

		if (mouse.getPosition(createwindow).x >= PaintTileWidth && mouse.getPosition(createwindow).x <= PaintTileWidth * 2 && mouse.getPosition(createwindow).y >= PaintTileHeight && mouse.getPosition(createwindow).y <= PaintTileHeight * 2) {
			return draw::clear;
		}
	}
	else {
		return draw::nothing;
	}
}

int Toolbar::BoundaryLimit() const
{
	return PaintTileHeight * 2.5;
}
