#pragma once
#include <unordered_map>
#include <iostream>
#include "Toolbar.h"
#include "Shape.h"
#include "DrawStatus.h"

class ShapeFactory {

public:

	ShapeFactory() {
		shapestatuspair.insert(std::make_pair(draw::line, 0));
		shapestatuspair.insert(std::make_pair(draw::cube, 1));
		shapestatuspair.insert(std::make_pair(draw::spline, 2));
		shapestatuspair.insert(std::make_pair(draw::circle, 3));
	}
	
	void getObject(Shape** shape, const std::vector<Entity*>& storeEntities, draw d) {

		if (*shape) {
			typeID = typeid(**shape).name();
		}

		else {
			typeID = "none";
		}

		if (d == draw::line) {	//before generating a shape, ensure that shape memory is freed (only generates when usr presses the rectangle for line!).
			
			if (typeID == "struct line"){
				*shape = p;
					return;
			}
			
			if (*shape != nullptr && !(std::any_of(storeEntities.cbegin(), storeEntities.cend(), [&](Entity* s) {return *shape == s; }))) {
				std::cout << "deleting shape entity of type:" << typeid(**shape).name() << std::endl;
				delete *shape;			//delete instatiated shapes that are not emplaced back into the store shapes vector
				*shape = nullptr;
			}

			p = new line();
			*shape = p;
			std::cout << "shape generated of type: " << typeid(**shape).name() << std::endl;
			
		}

		else if (d == draw::cube) {

			if (typeID == "struct cube") {
				*shape = p;
				return;
			}

			 if (*shape != nullptr && !(std::any_of(storeEntities.cbegin(), storeEntities.cend(), [&](Entity* s) {return *shape == s; }))) {
				std::cout << "deleting shape entity of type:" << typeid(**shape).name() << std::endl;
				delete *shape;			//delete instatiated shapes that are not emplaced back into the store shapes vector
				*shape = nullptr;
			 }
	
			p = new cube();
			*shape = p;
			std::cout << "shape generated of type: " << typeid(**shape).name() << std::endl;
		}
		
		else if (d == draw::spline) {
			if (typeID == "struct spline") {
				*shape = p;
				return;
			}

			if (*shape != nullptr && !(std::any_of(storeEntities.cbegin(), storeEntities.cend(), [&](Entity* s) {return *shape == s; }))) {
				std::cout << "deleting shape entity of type:" << typeid(**shape).name() << std::endl;
				delete *shape;			//delete instatiated shapes that are not emplaced back into the store shapes vector
				*shape = nullptr;
			}

			p = new spline();
			*shape = p;
			std::cout << "shape generated of type: " << typeid(**shape).name() << std::endl;
			
		}
		
		else if (d == draw::circle) {

			if (typeID == "struct circle") {
				*shape = p;
				return;
			}

			if (*shape != nullptr && !(std::any_of(storeEntities.cbegin(), storeEntities.cend(), [&](Entity* s) {return *shape == s; }))) {
				std::cout << "deleting shape entity of type:" << typeid(**shape).name() << std::endl;
				delete *shape;			//delete instatiated shapes that are not emplaced back into the store shapes vector
				*shape = nullptr;
			}

			p = new circle();
			*shape = p;
			std::cout << "shape generated of type: " << typeid(**shape).name() << std::endl;
			
		}
	}

	void setStatus(draw d, std::vector<drawstatus>& status) {
		auto f = shapestatuspair.find(d);
		if (f != shapestatuspair.end()) {
			status[f->second].initializeEntity = true;		//initialize entity
			for (int i = 0; i < status.size(); ++i) {		//reset all othr entitiies to false.
				if (i != f->second) {
					status[i].initializeEntity = false;
				}
			}
		}
	}

	~ShapeFactory() {
		p = nullptr;			//p's memeory is deleted by shape in the game.cpp's destructor since it is assigned to shape.
	}

private:
	std::unordered_map<draw, int> shapestatuspair;
	Shape* p = nullptr;
	int stat;
	std::string typeID;

};