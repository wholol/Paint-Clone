#pragma once
#include <SFML\Graphics.hpp>
#include "Entity.h"

class Text : public Entity {

public:
	Text(sf::Event& e);
	void drawEntity(sf::RenderWindow& createwindow, const Toolbar& toolbar) override;
	void resize(const sf::Mouse& mouse, sf::RenderWindow& createwindow, const Toolbar& toolbar) override;
	void setMousePos(sf::RenderWindow& createwindow,const sf::Mouse& mouse);
	void addtoString(sf::RenderWindow& createwindow, const Toolbar& toolbar);
	~Text();
private:
	sf::Text text;
	sf::Font font;		//load font.
	sf::Event& event;		//event reference object
	std::string textstring;		//store the text strign
	int mouseposx;
	int mouseposy;
	static constexpr uint8_t textMinSize = 25;
	static constexpr uint8_t textMaxSize = 90;
	uint8_t textsize;

};