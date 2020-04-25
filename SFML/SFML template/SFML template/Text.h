#pragma once
#include <SFML\Graphics.hpp>
#include "Entity.h"

class Text : public Entity {

public:
	Text(sf::Event& e);
	void drawEntity(sf::RenderWindow& createwindow, const Toolbar& toolbar) override;


private:
	sf::Text* text = nullptr;
	sf::Font font;		//load font.
	sf::Event& event;
	std::string textstring;		//store the text strign
};