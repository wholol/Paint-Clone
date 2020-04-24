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
		shape->drawEntity(createwindow, toolbar);
	}
	
	for (const auto &x : storepaint) {		//draw all shapes
		x->drawEntity(createwindow, toolbar);
	}

	for (const auto &x : storeshapes) {		//draw all shapes
		x->drawEntity(createwindow , toolbar);
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
		std::for_each(status.begin(), status.end(), [](drawstatus &x) {	//reset all entity status to false if anything is drawn
			x.drawnEntity = false;
			x.drawingEntity = false;
			x.initializeEntity = false;
		});
	
		if (!(std::any_of(storeshapes.cbegin(), storeshapes.cend(), [&](Shape* s) {return shape == s; }))) {
			storeshapes.emplace_back(shape);		//emplace back the shape only if the shape has not been emplaced before
			undo.push(shape);
			std::cout << "stored shape to vector" << std::endl;
			shape = nullptr;
			std::cout << "shape is now nullptr" << std::endl;
		}
	}

	for (auto& x : storeshapes) {		//resize shapes if mouse gets near the nodes.
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			x->resizeShapes(mouse, createwindow,toolbar);
		}
	}

	/*shape logic*/
	sf.setStatus(toolbar.ChooseFeature(mouse, createwindow), status);	//set the status of the shape
	sf.getObject(&shape, storeshapes, status, toolbar.ChooseFeature(mouse, createwindow));	//stop geenrating objects everytime	
		
	for (int i = 0; i <= 3; ++i) {
		if (status[i].initializeEntity) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
				if (mouse.getPosition(createwindow).y >= toolbar.BoundaryLimit() + 2) {		//only initialzie drawing if below boundary
					status[i].drawingEntity = true;
				}
			}

			if (status[i].drawingEntity) {
				
				shape->makenode(mouse, createwindow);		//make first node	
				shape->makenode(mouse, createwindow);		//make second node	

				if (i == 2) {		//spline. requries 3 nodes instead of 2
					shape->makenode(mouse, createwindow);		//make second node	
				}

				shape->setMousePos(mouse, createwindow, *shape, toolbar);
			}
		}
	}

	/*paint logic*/
	pf.setStatus(toolbar.ChooseFeature(mouse, createwindow), status);
	for (int i = 4; i < status.size(); ++i) {			//for each paint status (DO NOT loop for shapes)
		if (status[i].initializeEntity) {		//if it has been initializd by the setstatus function
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {		//if right clicked
				pf.getObject(&paint, i);					//make new object of type i if right click is pressed.
				paint->setMousePos(mouse, createwindow);
				undo.push(paint);
				storepaint.emplace_back(paint);
			}
		}
	}


	/*undo logic*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {		//prorably get the type id
		
		std::cout << undo.getTypeID() << std::endl;

		if (undo.getTypeID() != "none") {
			if (undo.getTypeID() == "struct line" || undo.getTypeID() == "struct spline" || undo.getTypeID() == "struct cube"
				|| undo.getTypeID() == "struct circle") {
				if (storeshapes.size() > 0) {
					storeshapes.pop_back();
					std::cout << storeshapes.size() << std::endl;
				}
			}

			else {
				if (storepaint.size() > 0) {
					storepaint.pop_back();
					std::cout << storepaint.size() << std::endl;
				}
			}
			undo.pop();
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {		//prorably get the type id
		undo.clear();				//clear stack frame for undo
		storepaint.clear();			//resiz container to zero
		storeshapes.clear();		//resize container to zero
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

	if (!(std::any_of(storeshapes.cbegin(), storeshapes.cend(), [&](Shape* s) {return shape == s; }))) {
		delete shape;			//delete instatiated shapes that are not emplaced back into the store shapes vector
		shape = nullptr;
	}

	
}