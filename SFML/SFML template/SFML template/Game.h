#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include "PolyMorph.h"
#include "Toolbar.h"
#include "DrawStatus.h"
#include "Paint.h"
#include "PaintFactory.h"

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
	PaintFactory pf;
	Shape* shape = nullptr;
	Paint* paint = nullptr;
	Toolbar toolbar;
	std::vector<drawstatus> status;	//stores the drawstatus of shapes
	std::vector <Shape*> storeshapes;		//store shapes to be drawn onto the screen.
	std::vector<Paint*> storepaint;			//stores vectors to be painted on the screen.
	bool drawsecondline = false;		
	bool quitgame = false;			//quit game
	bool MainMenu = true;		
	bool drawred = false;
	
	
	sf::Mouse mouse;
	sf::Event event;					//events class
	sf::RenderWindow createwindow;		//windows class
	bool GameOver = false;				//gameover boolean


};