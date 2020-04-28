#pragma once
#include "Toolbar.h"
#include "Paint.h"
#include <unordered_map>

class PaintFactory {		//generates objects and status, and the status.

public:

	void getObject(Paint** paint) {
			p = new Paint();
			std::cout << "paint entity created." << std::endl;
			*paint = p;
	}

	void setStatus(draw d,std::vector<drawstatus>& status) {

		if (d == draw::paint) {
			status[drawpaintstatus].initializeEntity = true;

			for (int i = 0; i < status.size(); ++i) {
				if (i != drawpaintstatus) {
					status[i].initializeEntity = false;
				}
			}
		}
	}

private:
	Paint* p = nullptr;
	static constexpr int drawpaintstatus = 4;			//status umber for drawpaint
};