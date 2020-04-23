#include "Game.h"
#include <iostream>


Game::Game(int screenwidth, int screenheight, const std::string& title, int framerate)
	:createwindow(sf::VideoMode(screenwidth, screenheight), title),
	toolbar(screenwidth , screenheight)
{
	for (int i = 0; i <= 11; ++i) {
		status.push_back({ false , false  , false });
	}
}


void Game::render() {		//rendering

	toolbar.DrawMenuBar(createwindow);			//draw menu bar
	
	if (shape != nullptr && std::any_of(status.begin(), status.end(), [](drawstatus &x) {return x.drawingEntity == true;})) { //draw shape if it is not nullptr and it is in progress of drawing
		shape->drawshape(createwindow, toolbar);
	}
	
	for (const auto &x : storepaint) {		//draw all shapes
			x->drawpaint(createwindow, toolbar);
	}

	for (const auto &x : storeshapes) {		//draw all shapes
		x->drawshape(createwindow , toolbar);
	}

	 createwindow.display();
}

void Game::main_menu()
{
	
}

void Game::update() {		//update game /logic

	if (std::any_of(status.begin(), status.end(), [](drawstatus &x) {return x.drawingEntity == true; }) //if any shape is in drawing status
		&& sf::Mouse::isButtonPressed(sf::Mouse::Left))	//if the user wants to input function onto screen, press left
	{
		std::for_each(status.begin(), status.end(), [](drawstatus &x) {		//after user clicks, set that entity to true.
			if (x.drawingEntity == true) {
				x.drawnEntity = true;
			}
		}	
		);
	}

	if (std::any_of(status.begin(), status.end(), [](drawstatus &x) {return x.drawnEntity == true; })) {
		std::for_each(status.begin(), status.end(), [](drawstatus &x) {	//reset all entity status to false.
			x.drawnEntity = false;
			x.drawingEntity = false;
			x.initializeEntity = false;
		});
	
		if (!(std::any_of(storeshapes.cbegin(), storeshapes.cend(), [&](Shape* s) {return shape == s; }))) {
			storeshapes.emplace_back(shape);		//emplace back the shape only if the shape has not been emplaced before
			std::cout << "stored shape to vector" << std::endl;
			shape = nullptr;
			std::cout << "shape is now nullptr" << std::endl;
		}
	}

	for (auto& x : storeshapes) {		//resize shapes if mouse gets near the nodes.
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			x->resizeShapes(mouse, createwindow);
		}
	}

	sf.setStatus(toolbar.ChooseFeature(mouse, createwindow), status);	//set the status of the shape
	sf.getObject(&shape, storeshapes, status, toolbar.ChooseFeature(mouse, createwindow));	//stop geenrating objects everytime	
		
	if (status[0].initializeEntity) {			//line case
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			status[0].drawingEntity = true;
		}

		if (status[0].drawingEntity) {
			shape->makenode(mouse, createwindow);		//make first node	
			shape->makenode(mouse, createwindow);		//make second node	
			shape->storenodes[1].loc.posx = mouse.getPosition(createwindow).x;		//move the newest node around
			shape->storenodes[1].loc.posy = mouse.getPosition(createwindow).y;
			if (shape->storenodes[1].loc.posy <= toolbar.BoundaryLimit()) {
				shape->storenodes[1].loc.posy = toolbar.BoundaryLimit();
			}
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

	/*paint logic*/
	pf.setStatus(toolbar.ChooseFeature(mouse, createwindow), status);

	for (int i = 4; i < status.size(); ++i) {			//for each paint status (DO NOT loop for shapes)
		if (status[i].initializeEntity) {		//if it has been initializd by the setstatus function
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {		//if right clicked
				paint = pf.getObject(i);					//make new object of type i if right click is pressed.

				paint->setMousePos(mouse, createwindow);
				storepaint.emplace_back(paint);
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

	for (auto& x : storepaint) {
		delete x;
		x = nullptr;
	}
	storepaint.clear();
}