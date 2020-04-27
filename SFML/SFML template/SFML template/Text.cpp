#include "Text.h"
#include <iostream>
#include <thread>


Text::Text(sf::Event& event) 
	:event(event) {
	if (!font.loadFromFile("Bebas-Regular.ttf")) {
		std::cout << "failed to load font file" << std::endl;
	}
	textsize = textMinSize;
	text.setCharacterSize(textsize); // in pixels, not points!
}

void Text::drawEntity(sf::RenderWindow& createwindow, const Toolbar& toolbar)
{
	createwindow.draw(text);
}

void Text::resize(const sf::Mouse& mouse, sf::RenderWindow& createwindow, const Toolbar& toolbar)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (textsize >= textMaxSize) {
			textsize = textMaxSize;
		}
		else {
			textsize++;
		}
		text.setCharacterSize(textsize); // in pixels, not points!
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (textsize <= textMinSize) {
			textsize = textMinSize;
		}
		else {
			textsize--;
		}
	}
	text.setCharacterSize(textsize); // in pixels, not points!
}

void Text::setMousePos(sf::RenderWindow& createwindow,const sf::Mouse& mouse)
{
	mouseposx = mouse.getPosition(createwindow).x;
	mouseposy = mouse.getPosition(createwindow).y;
}

void Text::addtoString(sf::RenderWindow& createwindow, const Toolbar& toolbar)
{
	text.setPosition(sf::Vector2f(mouseposx, mouseposy));
	if (mouseposy <= toolbar.BoundaryLimit()) {
		text.setPosition(sf::Vector2f(mouseposx, toolbar.BoundaryLimit() + 2));
	}

	/* the circle shape provides a visual of the cursor and textbox */
	sf::CircleShape cursorcircle;
	cursorcircle.setFillColor(sf::Color::Red);
	cursorcircle.setRadius(4);
	cursorcircle.setPosition(mouseposx, mouseposy);
	createwindow.draw(cursorcircle);

	text.setFont(font);
	text.setFillColor(sf::Color::Black);

	if (event.type == sf::Event::TextEntered) {

		if (event.text.unicode < 128 && event.text.unicode != 8) {		//8 is for backspace.DO NOT PUSH BACK BACKSPACE.
			textstring.push_back(static_cast<char>(event.text.unicode));
			std::this_thread::sleep_for(std::chrono::milliseconds(55));			//delay to prevent rapid keys being pressed.
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {			//delete chars from string
		if (!textstring.empty()) {
			textstring.pop_back();
			std::this_thread::sleep_for(std::chrono::milliseconds(55));			//delay to prevent rapid deletion
		}
	}

	text.setString(textstring);
	createwindow.draw(text);
}

Text::~Text()
{

}
