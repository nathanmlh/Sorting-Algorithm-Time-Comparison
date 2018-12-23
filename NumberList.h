#pragma once

#include <iostream>		// cout
#include <vector>		// vector
#include <algorithm>	// random_shuffle, sort, swap
#include <time.h>		// time
#include <chrono>		// chrono
#include <stdlib.h>		// srand
#include <Windows.h>

#include <SDL.h> // graphics library

class NumberList
{
private:
	std::vector<int> numbers;
	HANDLE hConsole; // for coloring text

	static const int SCREEN_WIDTH = 600;
	static const int SCREEN_HEIGHT = 480;
	static const int SIZE_OF_RECTS = SCREEN_WIDTH / 2;

	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	SDL_Rect rects[SIZE_OF_RECTS];

public:
	NumberList(); // intializes numbers with amount: (SCREEN_WIDTH/2)

	std::vector<int> initialize(int);
	void printVector();
	std::vector<int> shuffleNumbers();
	std::vector<int> sort();
	std::vector<int> selectionSort(); // O(n^2)
	std::vector<int> insertionSort();
	std::vector<int> bubbleSort();
	//vector<int> quickSort(int, int); 
	//int partition(int, int); // used in quickSort

	void fillScreenWithRects(int);
	void printRectHeights();

	~NumberList();
};

