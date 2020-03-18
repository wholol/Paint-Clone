#include "Game.h"
#include <iostream>
#include <thread>

Game::Game(int screenwidth, int screenheight, const std::string& title, int framerate)
	:createwindow(sf::VideoMode(screenwidth, screenheight), title)
{}


void Game::render() {		//rendering
	
	
	if (shape != nullptr) {
		shape->drawshape(createwindow);
	}
	
	for (const auto &x : storeshapes) {		//draw all shapes
		x->drawshape(createwindow);
	}
	
	 createwindow.display();
	
}

void Game::main_menu()
{
	
}

void Game::update() {		//update game /logic

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && shape != nullptr) {
		drawline = false;		//stop drawing the line (prevent the lin from follwoing mouse cursor).
		drawcube = false;
		drawcircle = false;
		drawspline = false;
		if (!(std::any_of(storeshapes.cbegin(), storeshapes.cend(), [&](Shape* s) {return shape == s; }))) {
			storeshapes.emplace_back(shape);		//emplace back the shape only if the shape has not been emplaced before
		}
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {  
		drawcube = false;
		drawcircle = false;
		drawspline = false;
		drawline = true;

		if (!(std::any_of(storeshapes.cbegin(), storeshapes.cend(), [&]( Shape* s) {return shape == s; }))) {
			delete shape;			//delete shapes that are not emplaced back into the store shapes vector
			shape = nullptr;
		}
		
		shape = new line();		//create new shape obj is left key is pressed
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		if (!(std::any_of(storeshapes.cbegin(), storeshapes.cend(), [&](Shape* s) {return shape == s; }))) {
			delete shape;			//delete instatiated shapes that are not emplaced back into the store shapes vector
			shape = nullptr;
		}

		drawline = false;
		drawcube = true;
		drawspline = false;
		drawcircle = false;

		shape = new cube();
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
		if (!(std::any_of(storeshapes.cbegin(), storeshapes.cend(), [&](Shape* s) {return shape == s; }))) {
			delete shape;			//delete instatiated shapes that are not emplaced back into the store shapes vector
			shape = nullptr;
		}
		
		drawline = false;
		drawcube = false;
		drawspline = false;
		drawcircle = true;
		shape = new circle();
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (!(std::any_of(storeshapes.cbegin(), storeshapes.cend(), [&](Shape* s) {return shape == s; }))) {
			delete shape;			//delete instatiated shapes that are not emplaced back into the store shapes vector
			shape = nullptr;
		}

		drawsecondline = false;
		drawline = false;
		drawcube = false;
		drawspline = true;
		drawcircle = false;
		shape = new spline();
	}

	for (auto& x: storeshapes) {		//resize shapes if mouse gets near the nodes.
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			x->resizeShapes(mouse, createwindow);
		}
	}

	if (drawline) {			//if space is pressed
		shape->makenode(mouse, createwindow);		//make first node	//push back vector
		shape->makenode(mouse, createwindow);		//make second node	//push back vector
		shape->storenodes[1].loc.posx = mouse.getPosition(createwindow).x;		//move the newest node around
		shape->storenodes[1].loc.posy = mouse.getPosition(createwindow).y;		//move the newest node around
	}

	if (drawspline) {			//if space is pressed
		shape->makenode(mouse, createwindow);		//make first node	//push back vector
		shape->makenode(mouse, createwindow);		//make second node	//push back vector
		shape->makenode(mouse, createwindow);		//make third node	//push back vector

		if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) {
			drawsecondline = true;
		}

		if (drawsecondline) {
			shape->storenodes[2].loc.posx = mouse.getPosition(createwindow).x;		//move the newest node around
			shape->storenodes[2].loc.posy = mouse.getPosition(createwindow).y;		//move the newest node around
		}

		else {
			shape->storenodes[1].loc.posx = mouse.getPosition(createwindow).x;		//move the newest node around
			shape->storenodes[1].loc.posy = mouse.getPosition(createwindow).y;
			shape->storenodes[2].loc.posx = mouse.getPosition(createwindow).x;		//move the newest node around
			shape->storenodes[2].loc.posy = mouse.getPosition(createwindow).y;		//move the newest node around
		}		
	}

	if (drawcube) {
		shape->makenode(mouse, createwindow);		//make first node	//push back vector
		shape->makenode(mouse, createwindow);		//make second node	//push back vector
		shape->storenodes[1].loc.posx = mouse.getPosition(createwindow).x;		//move the newest node around
		shape->storenodes[1].loc.posy = mouse.getPosition(createwindow).y;		//move the newest node around
	}


	if (drawcircle) {
		shape->makenode(mouse, createwindow);		//make first node	//push back vector
		shape->makenode(mouse, createwindow);		//make second node	//push back vector
		shape->storenodes[1].loc.posx = mouse.getPosition(createwindow).x;		//move the newest node around
		shape->storenodes[1].loc.posy = mouse.getPosition(createwindow).y;		//move the newest node around
	}

	createwindow.clear();
}


bool Game::quit()			//call quit game

//DO NOT DELETE CONTENTS OF THIS FUNCTION TO PREVENT AN UNRESPONSIV SCREEN//
{
	while (createwindow.pollEvent(event)) {		//NON BLOCKING FUNCTION, WILL NOT GET STUCK IN WHILE LOOP.
		if (event.type == sf::Event::Closed) {
			createwindow.close();
			quitgame = true;
		}
	}
	return quitgame;
	
}

Game::~Game()	{

}