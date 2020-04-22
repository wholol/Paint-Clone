#pragma once
#include "Paint.h"

Paint::Paint() 
	:circle(minbrushradius)
{

}

void Paint::ChangeBrushSize()
	
{
	

}



void Red::ToolbarCollisionDetection(){


}


void Red::drawpaint(sf::RenderWindow &createwindow) {
	
	uint8_t radius = minbrushradius;
	circle.setRadius(radius);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(sf::Vector2f(mouseposx - radius , mouseposy - radius));
	createwindow.draw(circle);
}

void Red::setMousePos(const sf::Mouse& mouse, sf::RenderWindow &createwindow) {
	mouseposx = mouse.getPosition(createwindow).x;
	mouseposy = mouse.getPosition(createwindow).y;
}


void Yellow::ToolbarCollisionDetection() {


}

void Yellow::drawpaint(sf::RenderWindow &createwindow) {


}



void Blue::ToolbarCollisionDetection() {


}

void Blue::drawpaint(sf::RenderWindow &createwindow) {


}




void Black::ToolbarCollisionDetection() {


}

void Black::drawpaint(sf::RenderWindow &createwindow) {


}



void Magenta::ToolbarCollisionDetection() {


}

void Magenta::drawpaint(sf::RenderWindow &createwindow) {


}



void Cyan::ToolbarCollisionDetection() {


}

void Cyan::drawpaint(sf::RenderWindow &createwindow) {


}


void Green::ToolbarCollisionDetection() {


}

void Green::drawpaint(sf::RenderWindow &createwindow) {


}



void White::ToolbarCollisionDetection() {


}

void White::drawpaint(sf::RenderWindow &createwindow) {


}