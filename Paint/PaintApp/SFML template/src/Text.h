#pragma once
#include <SFML\Graphics.hpp>
#include "Entity.h"
#include <unordered_map>

class Text : public Entity {

public:

	Text(sf::Event& e);
	void drawEntity(sf::RenderWindow& createwindow) override;								//draw completed text on screen
	void resize(const sf::Mouse& mouse, sf::RenderWindow& createwindow) override;			//resize the text
	void setMousePos(sf::RenderWindow& createwindow,const sf::Mouse& mouse);										//set the mouse position of the screen
	void clampMousePos();																		//prevents textbox going off the boundary
	void setTextColour(draw d);																						//set the colour of the text
	void addtoString();										//add cahracters to the string
	void displayText(sf::RenderWindow& createwindow);										//shows the text that are on the screen
	~Text();

private:
	sf::Text text;				//text object
	sf::Font font;				//load font.
	sf::Event& event;			//event reference object
	std::string textstring;		//store the text strign
	static constexpr uint8_t textMinSize = 25;			//minimum text size
	static constexpr uint8_t textMaxSize = 90;			//maximum text size
	uint8_t textsize;									//current textsize
	std::unordered_map<draw,sf::Color> colourmap;		//hashmap to choose colour
	sf::Color textColor;								//store text color

};