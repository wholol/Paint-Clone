#pragma once
#include <stack>
#include "Entity.h"

class Undo {
public:

	void push(Entity* entity);
	void pop();
	void clear();

	std::string getTypeID() const;
private:
	std::stack<Entity*> undo;
	std::string typeID;
};