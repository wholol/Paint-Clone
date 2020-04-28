#pragma once
#include "Entity.h"
#include "AirBrush.h"
#include "DrawStatus.h"
#include <iostream>

class AirBrushFactory {

public:
	void getObject(AirBrush** airbrush, const std::vector<Entity*>& storeEntities, draw d) {

			a = new AirBrush();
			*airbrush = a;
			std::cout << "shape generated of type: " << typeid(**airbrush).name() << std::endl;
		
	}

	void setStatus(draw d, std::vector<drawstatus>& status) {
		if (d == draw::airbrush) {
			status[airbrushstatus].initializeEntity = true;
			for (int i = 0; i < status.size(); ++i) {		//reset other paints to false 
				if (i != airbrushstatus) {
					status[i].initializeEntity = false;
				}
			}
		}
	}

	~AirBrushFactory() {
		a = nullptr;			//a's memeory is deleted by shape in the game.cpp's destructor since it is assigned to shape.
	}

private:
	AirBrush* a = nullptr;
	static constexpr uint8_t airbrushstatus = 6;
};