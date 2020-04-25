#include "Text.h"
#include <iostream>


Text::Text(sf::Event& event) 
	:event(event) {}

void Text::drawEntity(sf::RenderWindow& createwindow, const Toolbar& toolbar)
{
	if (!font.loadFromFile("Bebas-Regular.ttf")) {
		std::cout << "failed to load font file" << std::endl;
	}
	text->setPosition(sf::Vector2f(700, 500));
	std::cout << " text entity running !" << std::endl;
	text->setFont(font);
	text->setCharacterSize(34); // in pixels, not points!
	text->setFillColor(sf::Color::Red);
	std::string put;
	if (event.type == sf::Event::TextEntered){
		if (event.text.unicode < 128) {
			std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
			textstring.push_back(static_cast<char>(event.text.unicode));
		}
	}
	text->setString(textstring);
	std::cout << textstring << std::endl;
	createwindow.draw(*text);


}
