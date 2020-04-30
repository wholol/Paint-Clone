#pragma once
#include "Undo.h"

void Undo::push(Entity* entity)
{
	undo.push(entity);
	typeID = typeid(*entity).name();
}

void Undo::pop()
{
	if (!undo.empty()) {
		Entity* temp = undo.top();
		undo.pop();
		if (undo.empty()) {
			typeID = "none";
		}

		else {
			typeID = typeid(*undo.top()).name();		//get the typeID of the object AFTER popping. (to determine the next item to pop).
		}
		delete temp;
		temp = nullptr;
	}
}

void Undo::clear()
{
	while (!undo.empty()) {
		Entity* temp = undo.top();
		undo.pop();
		delete temp;
		temp = nullptr;
	}
	typeID = "none";
}

std::string Undo::getTypeID() const
{
	return typeID;
}
