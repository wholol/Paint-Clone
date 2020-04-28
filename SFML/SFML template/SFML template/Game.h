#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include "Shape.h"
#include "Toolbar.h"
#include "DrawStatus.h"
#include "Paint.h"
#include "PaintFactory.h"
#include "ShapeFactory.h"
#include "Undo.h"
#include "Text.h"
#include "TextFactory.h"
#include "AirBrush.h"
#include "AirBrushFactory.h"


class Game {			//game class. should have render, update/events, quit and initialize.

public:
	Game(int screenwidth, int screenheight, const std::string& title, int framerate);	//game constructor
	Game &operator=(Game &other) = delete;				//prevent assigning game object
	Game(const Game& other) = delete;					//no deep copying a game object
	Game(Game &&other) = delete;						//no moving game object
	~Game();
	
	void main_menu();
	void update();					//update logic
	void render();					//rende r
	bool quit();					//quit the window

private:
	Undo undo;
	PaintFactory pf;
	ShapeFactory sf;
	TextFactory tf;
	AirBrushFactory af;
	Shape* shape = nullptr;			
	Paint* paint = nullptr;
	Text* text = nullptr;
	AirBrush* airbrush = nullptr;
	Toolbar toolbar;
	std::vector<drawstatus> status;	//stores the drawstatus of shapes
	std::vector <Entity*> storeEntities;		//store shapes to be drawn onto the screen.
	bool quitgame = false;			//quit game
	bool MainMenu = true;		
	sf::Mouse mouse;
	sf::Event event;					//events class
	sf::RenderWindow createwindow;		//windows class
	bool GameOver = false;				//gameover boolean
};