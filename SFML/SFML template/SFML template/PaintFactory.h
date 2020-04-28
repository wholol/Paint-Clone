#pragma once
#include "Toolbar.h"
#include "Paint.h"
#include <unordered_map>

class PaintFactory {		//generates objects and status, and the status.

public:

	PaintFactory(){
		drawstatuspair.insert(std::make_pair( draw::redpaint, 4 ));
		drawstatuspair.insert(std::make_pair(draw::bluepaint, 5));
		drawstatuspair.insert(std::make_pair(draw::magentapaint, 6));
		drawstatuspair.insert(std::make_pair(draw::greenpaint, 7));
		drawstatuspair.insert(std::make_pair(draw::yellowpaint, 8));
		drawstatuspair.insert(std::make_pair(draw::blackpaint, 9));
		drawstatuspair.insert(std::make_pair(draw::cyanpaint, 10));
		drawstatuspair.insert(std::make_pair(draw::whitepaint, 11));
	}

	void getObject(Paint** paint,int status) {
		if (status == 4) {
			p = new Red();
			*paint = p;
		}
		
		else if (status == 5) {
			p = new Blue();
			*paint = p;
		}

		else if (status == 6) {
			p = new Magenta();
			*paint = p;
		}

		else if (status == 7) {
			p = new Green();
			*paint = p;
		}

		else if (status == 8) {
			p = new Yellow();
			*paint = p;
		}

		else if (status == 9) {
			p = new Black();
			*paint = p;
		}

		else if (status == 10) {
			p = new Cyan();
			*paint = p;
		}

		else if (status == 11) {
			p = new White();
			*paint = p;
		}
	
	}

	void setStatus(draw d,std::vector<drawstatus>& status) {

		auto f = drawstatuspair.find(d);
		if (f != drawstatuspair.end()) {
			status[f->second].initializeEntity = true;		
			for (int i = 0; i < status.size(); ++i) {		//reset other paints to false 
				if (i != f->second) {
					status[i].initializeEntity = false;
				}
			}
		}		
	}

private:
	Paint* p = nullptr;
	std::unordered_map<draw, int> drawstatuspair;
};