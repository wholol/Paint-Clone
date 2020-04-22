#include "Game.h"
#include <iostream>


Game::Game(int screenwidth, int screenheight, const std::string& title, int framerate)
	:createwindow(sf::VideoMode(screenwidth, screenheight), title),
	toolbar(screenwidth , screenheight)
{
	for (int i = 0; i < 5; ++i) {
		status.push_back({ false , false  , false });
	}
}



void Game::render() {		//rendering

	toolbar.DrawMenuBar(createwindow);			//draw menu bar
	

	if (shape != nullptr && std::any_of(status.begin(), status.end(), [](drawstatus &x) {return x.drawingEntity == true;})) { //draw shape if it is not nullptr and it is in progress of drawing
		shape->drawshape(createwindow);
	}
	
	

	for (const auto &x : storeshapes) {		//draw all shapes
		x->drawshape(createwindow);
	}

	for (const auto &x : storepaint) {		//draw all shapes
		x->drawpaint(createwindow);
	}


	
	 createwindow.display();
	
}

void Game::main_menu()
{
	
}

void Game::update() {		//update game /logic

	if (std::any_of(status.begin(), status.end(), [](drawstatus &x) {return x.drawingEntity == true; }) 
		&& sf::Mouse::isButtonPressed(sf::Mouse::Left))	//if the user wants to input function onto screen
	{
		std::for_each(status.begin(), status.end(), [](drawstatus &x) { 
			if (x.drawingEntity == true) {
				x.drawnEntity = true;
			}
		}	
		);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		storepaint.emplace_back(paint);
	}

	if (shape != nullptr && std::any_of(status.begin(), status.end(), [](drawstatus &x) {return x.drawnEntity == true; })) {
		std::for_each(status.begin(), status.end(), [](drawstatus &x) {	//reset all entity status to false.
			x.drawnEntity = false;
			x.drawingEntity = false;
			x.initializeEntity = false;
		});
	
		if (!(std::any_of(storeshapes.cbegin(), storeshapes.cend(), [&](Shape* s) {return shape == s; }))) {
			storeshapes.emplace_back(shape);		//emplace back the shape only if the shape has not been emplaced before
		}
	}

	for (auto& x : storeshapes) {		//resize shapes if mouse gets near the nodes.
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			x->resizeShapes(mouse, createwindow);
		}
	}

	if (toolbar.ChooseFeature( mouse , createwindow ) == draw::line && !status[0].initializeEntity) {		//allocate heap for line
		if (!(std::any_of(storeshapes.cbegin(), storeshapes.cend(), [&](Shape* s) {return shape == s; }))) {
			delete shape;			//delete shapes that are not emplaced back into the store shapes vector
			shape = nullptr;
		}

		shape = new line();		//create new shape obj is left key is pressed
		status[0].initializeEntity = true;	//iniitialize entity
	}

	if (toolbar.ChooseFeature( mouse , createwindow) == draw::cube && !status[1].initializeEntity) {	//allocate heap for cube
		if (!(std::any_of(storeshapes.cbegin(), storeshapes.cend(), [&](Shape* s) {return shape == s; }))) {
			delete shape;			//delete instatiated shapes that are not emplaced back into the store shapes vector
			shape = nullptr;
		}

		shape = new cube();				//create new cube object
		status[1].initializeEntity = true;	//initialize entity
	}

	if (toolbar.ChooseFeature(mouse , createwindow) == draw::spline && !status[2].initializeEntity) {
		if (!(std::any_of(storeshapes.cbegin(), storeshapes.cend(), [&](Shape* s) {return shape == s; }))) {
			delete shape;			//delete instatiated shapes that are not emplaced back into the store shapes vector
			shape = nullptr;
		}

		shape = new spline();
		status[2].initializeEntity = true;	//initialize entity
	}

	if (toolbar.ChooseFeature(mouse , createwindow) == draw::circle && !status[3].initializeEntity) {
		if (!(std::any_of(storeshapes.cbegin(), storeshapes.cend(), [&](Shape* s) {return shape == s; }))) {
			delete shape;			//delete instatiated shapes that are not emplaced back into the store shapes vector
			shape = nullptr;
		}

		shape = new circle();
		status[3].initializeEntity = true;	//initialize entity
	}
	
	if (status[0].initializeEntity) {			//line case
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			status[0].drawingEntity = true;
		}

		if (status[0].drawingEntity) {
			shape->makenode(mouse, createwindow);		//make first node	
			shape->makenode(mouse, createwindow);		//make second node	
			shape->storenodes[1].loc.posx = mouse.getPosition(createwindow).x;		//move the newest node around
			shape->storenodes[1].loc.posy = mouse.getPosition(createwindow).y;		//move the newest node around
		}
	}

	
	if (status[2].initializeEntity) {			//if space is pressed

		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			status[2].drawingEntity = true;
		}

		if (status[2].drawingEntity) {
			shape->makenode(mouse, createwindow);		//make first node	
			shape->makenode(mouse, createwindow);		//make second node	
			shape->makenode(mouse, createwindow);		//thir node for spline	
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
				shape->storenodes[2].loc.posy = mouse.getPosition(createwindow).y;
			}
		}
	}

	if (status[1].initializeEntity) {		//cube case
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			status[1].drawingEntity = true;
		}

			if (status[1].drawingEntity) {
				shape->makenode(mouse, createwindow);		//make first node	
				shape->makenode(mouse, createwindow);		//make second node	
				shape->storenodes[1].loc.posx = mouse.getPosition(createwindow).x;		//move the newest node around
				shape->storenodes[1].loc.posy = mouse.getPosition(createwindow).y;		//move the newest node around
			}
	}

	if (status[3].initializeEntity) {		//cube case

		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			status[3].drawingEntity = true;
		}
			if (status[3].drawingEntity) {
				shape->makenode(mouse, createwindow);		//make first node	
				shape->makenode(mouse, createwindow);		//make second node	
				shape->storenodes[1].loc.posx = mouse.getPosition(createwindow).x;		//move the newest node around
				shape->storenodes[1].loc.posy = mouse.getPosition(createwindow).y;		//move the newest node around
			}
	}

	

	
	createwindow.clear(sf::Color::White);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		paint = new Red();
		paint->setMousePos(mouse, createwindow);
		storepaint.emplace_back(paint);
	}
	
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
	
	for (auto& x : storeshapes) {
		delete x;
		x = nullptr;
	}
	storeshapes.clear();
}