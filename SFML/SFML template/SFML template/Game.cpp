#include "Game.h"
#include <iostream>
#include <assert.h>

Game::Game(int screenwidth, int screenheight, const std::string& title, int framerate)
	:createwindow(sf::VideoMode(screenwidth, screenheight), title),
	toolbar(screenwidth , screenheight)
{
	assert(screenheight == 800);
	assert(screenwidth == 1400);
	for (int i = 0; i <= 6; ++i) {
		status.push_back({ false , false  , false });
	}

	/*initialzie colour palettes*/
	colourpalette.emplace_back(draw::blackpaint);
	colourpalette.emplace_back(draw::whitepaint);
	colourpalette.emplace_back(draw::bluepaint);
	colourpalette.emplace_back(draw::greenpaint);
	colourpalette.emplace_back(draw::yellowpaint);
	colourpalette.emplace_back(draw::redpaint);
	colourpalette.emplace_back(draw::magentapaint);
	colourpalette.emplace_back(draw::cyanpaint);

}

void Game::render() {		//rendering

	toolbar.DrawMenuBar(createwindow);			//draw menu bar
	
	if (shape != nullptr && std::any_of(status.begin(), status.end(), [](drawstatus &x) {return x.drawingEntity == true;})) { //draw shape if it is not nullptr and it is in progress of drawing
		shape->drawEntity(createwindow, toolbar);
	}
	
	for (const auto &x : storeEntities) {		//draw all shapes
		x->drawEntity(createwindow, toolbar);
	}
	 createwindow.display();
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
	
		if (!(std::any_of(storeEntities.cbegin(), storeEntities.cend(), [&](Entity* s) {return shape == s; }))) {
			storeEntities.emplace_back(shape);		//emplace back the shape only if the shape has not been emplaced before
			undo.push(shape);
			std::cout << "stored shape to vector" << std::endl;
			shape = nullptr;
			std::cout << "shape is now nullptr" << std::endl;
		}
	}

	for (auto& x : storeEntities) {		//resize shapes if mouse gets near the nodes.
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			x->resize(mouse, createwindow,toolbar);
		}
	}

	/*shape logic*/
	sf.setStatus(toolbar.ChooseFeature(mouse, createwindow), status);	//set the status of the shape
	sf.getObject(&shape, storeEntities, toolbar.ChooseFeature(mouse, createwindow));	//generate a shape object

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

				if (i == 2) {		//spline (status[2]). requries 3 nodes. hence, create extra node.
				shape->makenode(mouse, createwindow);		//make second node	
				}
				shape->setMousePos(mouse, createwindow, *shape, toolbar);
			}
		}
	}
	
		/*paint logic*/
		pf.setStatus(toolbar.ChooseFeature(mouse, createwindow), status);		//set the status for paint
		if (status[4].initializeEntity) {		//if it has been initializd by the setstatus function
			
			if (std::any_of(colourpalette.cbegin(), colourpalette.cend(), [&](const draw& x) {return toolbar.ChooseFeature(mouse , createwindow) == x; })){
				std::cout << "choose a colour!" << std::endl;
				chooseColor = toolbar.ChooseFeature(mouse, createwindow);
			}

				if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {		//if right clicked
					pf.getObject(&paint);					//make new object of type i if right click is pressed.
					paint->setColour(chooseColor);
					paint->setMousePos(mouse, createwindow);
					paint->resize(mouse, createwindow, toolbar);
					undo.push(paint);
					storeEntities.emplace_back(paint);
				}
		}


	/*airbrush logic*/
	af.setStatus(toolbar.ChooseFeature(mouse, createwindow), status);	//set the status of the shape
	if (status[6].initializeEntity) {							 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			af.getObject(&airbrush, storeEntities, toolbar.ChooseFeature(mouse, createwindow));	//generate a shape object
			airbrush->setMousePos(createwindow, mouse);
			airbrush->resize(mouse, createwindow, toolbar);
			airbrush->generatePoints(createwindow, mouse);
			storeEntities.emplace_back(airbrush);
			undo.push(airbrush);
		}
	}
	
	createwindow.clear(sf::Color::White);
	/* entities below are not immediately empalaced back into the storeEntites vector, hence it should be after clearing the screen so that it can be seen*/
	/*for example, texts not immediately empalced back into the vector*/
	
	/*text logic*/
	tf.getObject(&text, storeEntities, toolbar.ChooseFeature(mouse, createwindow), event);	//generate a text object
	tf.setStatus(toolbar.ChooseFeature(mouse, createwindow), status);	//set the status of the text
	if (status[5].initializeEntity) {		//if text status turns true

		if (std::any_of(colourpalette.cbegin(), colourpalette.cend(), [&](const draw& x) {return toolbar.ChooseFeature(mouse, createwindow) == x; })) {
			chooseColor = toolbar.ChooseFeature(mouse, createwindow);		//choosecolor for text
		}

		text->setMousePos(createwindow, mouse);
		text->clampMousePos(toolbar);			//prevent textbox from going above the boundary line.
		text->setTextColour(chooseColor);
		text->resize(mouse, createwindow, toolbar);			//resize the text	
		text->addtoString(createwindow, toolbar);			//add characters to string.
		text->displayText(createwindow, toolbar);			//display current text on the window

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {		//if the user wants to put text into canvas
			storeEntities.emplace_back(text);		//emplace back text object
			undo.push(text);						
			status[5].initializeEntity = false;		//reset status to false
			text = nullptr;							//reset to nullptr.
		}
	}
	
	/*undo logic*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {	//undo drawings done (CTRL+Z)
		if (undo.getTypeID() != "none") {	
			if (storeEntities.size() > 0) {
				storeEntities.pop_back();
			}
			undo.pop();
		}
	}

	/*clear whole screen logic*/
	if (toolbar.ChooseFeature(mouse,createwindow) == draw::clear) {		
		undo.clear();				//clear stack frame for undo
		storeEntities.clear();		//resize container to zero
	}
}

bool Game::quit()			//call quit game

//DO NOT DELETE CONTENTS OF THIS FUNCTION TO PREVENT AN UNRESPONSIVE SCREEN//
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
	
	for (auto& x : storeEntities) {			
		delete x;
		x = nullptr;
	}
	storeEntities.clear();

	if (!(std::any_of(storeEntities.cbegin(), storeEntities.cend(), [&](Entity* s) {return shape == s; }))) {
		delete shape;			//delete instatiated shapes that are not emplaced back into the storeEntities vector (this happens when a user clicks on a shape and closes the window).
		shape = nullptr;
	}

	if (!(std::any_of(storeEntities.cbegin(), storeEntities.cend(), [&](Entity* s) {return text == s; }))) {
		delete text;			//delete instatiated text that are not emplaced back into the storeEntities vector (this happens when a user clicks on a shape and closes the window).
		text = nullptr;
	}
}