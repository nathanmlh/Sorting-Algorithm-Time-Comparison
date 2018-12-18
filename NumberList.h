#pragma once

#include <iostream>		// cout
#include <vector>		// vector
#include <algorithm>	// random_shuffle, sort, swap
#include <time.h>		// time
#include <chrono>		// chrono
#include <stdlib.h>		// srand
#include <Windows.h>

class NumberList
{
private:
	std::vector<int> numbers;
	HANDLE hConsole; // for coloring text
public:
	NumberList();
	NumberList(std::vector<int>);

	std::vector<int> initialize(int /* size of */);
	void printVector();
	std::vector<int> shuffle();
	std::vector<int> sort();
	std::vector<int> selectionSort(); // O(n^2)
	std::vector<int> insertionSort();
	std::vector<int> bubbleSort();
	//vector<int> quickSort(int, int); 
	//int partition(int, int); // used in quickSort

	~NumberList();
};

