#pragma once
#include "DrawStatus.h"
#include "Toolbar.h"
#include "Text.h"
#include <unordered_map>
#include <iostream>

class TextFactory {

public:

	void getObject(Text** text, const std::vector<Entity*>& storeEntities, draw d,sf::Event& e) {

		if (d == draw::text) {		//delete any text objects that ar not emplaced back into the storeEntities vector.
			if (*text != nullptr && !(std::any_of(storeEntities.cbegin(), storeEntities.cend(), [&](Entity* s) {return *text == s; }))) {
				std::cout << "deleting entity of type:" << typeid(**text).name() << std::endl;
				delete *text;			//delete instatiated shapes that are not emplaced back into the store shapes vector
				*text = nullptr;
			}

			t = new Text(e);
			*text = t;
			std::cout << "Entity generated of type: " << typeid(**text).name() << std::endl;
		}
	}

	void setStatus(draw d, std::vector<drawstatus>& status) {
		if (d == draw::text) {

			status[textstatus].initializeEntity = true;
			for (int i = 0; i < status.size(); ++i) {		//reset other paints to false 
				if (i != textstatus) {
					status[i].initializeEntity = false;
				}
			}
		}
	}


private:
	Text* t = nullptr;
	static constexpr int textstatus = 5;


};