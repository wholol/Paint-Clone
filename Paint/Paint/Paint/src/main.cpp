// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Game.h"


static struct AllocationMetrics {
	uint32_t allocated;
	uint32_t deallocated;
	uint32_t usage() {
		return allocated - deallocated;
	}
};

AllocationMetrics a;

void* operator new(size_t size) {
	a.allocated += size;
	return malloc(size);
}

void operator delete(void* memory, size_t size) {
	a.deallocated += size;
	free(memory);
}

static void PrintMemory() {
	std::cout << "Amount of memory used: " << a.allocated << std::endl;
	std::cout << "Amount of leaked memory:" << a.usage() << std::endl;
}

int main()
{
	{
		Game creategame(1400, 800, "game", 120);
		while (!creategame.quit()) {
			creategame.update();
			creategame.render();
		}
	}
	PrintMemory();
}
