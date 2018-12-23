#include "NumberList.h"



NumberList::NumberList() {
	srand(time(NULL));
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // retrieves handle for output

	numbers = initialize(SIZE_OF_RECTS); // initialize numbers with size of (SIZE_OF_RECTS)

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Sorting Algorithm Time Comparisons", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

std::vector<int> NumberList::initialize(int size) {
	auto start = std::chrono::system_clock::now();
	SetConsoleTextAttribute(hConsole, 15);

	for (int i = 1; i <= size; i++) { // initialize
		numbers.push_back(i);
	}

	auto end = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Time elapsed for initialization: " << duration.count() << std::endl;

	return numbers;
}

void NumberList::printVector() {
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "Printing vector..." << std::endl;
	for (int i = 0; i < numbers.size(); i++) {
		std::cout << numbers[i] << "\t";
	}
	std::cout << std::endl << std::endl;
}

std::vector<int> NumberList::shuffleNumbers() {
	auto start = std::chrono::system_clock::now();
	SetConsoleTextAttribute(hConsole, 15);

	std::random_shuffle(numbers.begin(), numbers.end());

	auto end = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Time elapsed for shuffle: " << duration.count() << std::endl;

	return numbers;
}

std::vector<int> NumberList::sort() { // sort algorithm using sort function from <algorithm>
	auto start = std::chrono::system_clock::now();
	SetConsoleTextAttribute(hConsole, 1);

	std::sort(numbers.begin(), numbers.end());

	auto end = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Time elapsed for sort: " << duration.count() << std::endl;

	return numbers;
}

std::vector<int> NumberList::selectionSort() {
	auto start = std::chrono::system_clock::now();
	SetConsoleTextAttribute(hConsole, 2);

	int selection;

	for (int i = 0; i < numbers.size(); i++) {
		selection = i;
		for (int j = i + 1; j < numbers.size(); j++) {
			if (numbers[j] < numbers[selection]) {
				selection = j;
			}
		}
		std::swap(numbers[selection], numbers[i]);
		fillScreenWithRects(20); // displays to screen
	}

	auto end = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Time elapsed for selection sort: " << duration.count() << std::endl;

	return numbers;
}

std::vector<int> NumberList::insertionSort() {
	auto start = std::chrono::system_clock::now();
	SetConsoleTextAttribute(hConsole, 3);
	int position, valueToInsert;

	for (int i = 0; i < numbers.size(); i++) {
		// select value to be inserted
		valueToInsert = numbers[i];
		position = i;

		while (position > 0 && numbers[position - 1] > valueToInsert) {
			numbers[position] = numbers[position - 1];
			position = position - 1;
		}

		numbers[position] = valueToInsert;
		fillScreenWithRects(10);
	}

	auto end = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Time elapsed for insertion sort: " << duration.count() << std::endl;

	return numbers;
}

std::vector<int> NumberList::bubbleSort() {
	auto start = std::chrono::system_clock::now();
	SetConsoleTextAttribute(hConsole, 5);

	bool swapped;

	for (int i = 0; i < numbers.size() - 1; i++) {
		swapped = false;
		for (int j = 0; j < numbers.size() - 1; j++) {
			if (numbers[j] > numbers[j + 1]) {
				std::swap(numbers[j], numbers[j + 1]);
				swapped = true;
				fillScreenWithRects(0.1);
			}
		}
		if (!swapped)
			break;
	}

	auto end = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Time elapsed for bubble sort: " << duration.count() << std::endl;

	return numbers;
}

//std::vector<int> NumberList::quickSort(int low, int high) {
//	auto start = std::chrono::system_clock::now();
//
//	if (low < high) {
//		// pi is partitioning index, numbers[pi] is now at right place
//		int pi = partition(numbers, low, high);
//
//		quickSort(numbers, low, pi - 1);
//		quickSort(numbers, pi + 1, high);
//	}
//
//	auto end = std::chrono::system_clock::now();
//	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
//	std::cout << "Time elapsed for quick sort: " << duration.count() << endl;
//
//	return numbers;
//}
//
//int NumberList::partition(int low, int high) {
//	// pivot (Element to be placed at right position
//	int pivot = numbers[high];
//
//	int i = (low - 1); // Index of smaller element
//
//	for (int j = low; j <= high - 1; j++) {
//		// If current element is smaller than or equal to pivot
//		if (numbers[j] <= pivot) {
//			i++;
//			std::swap(numbers[j], numbers[i]);
//		}
//	}
//	swap(numbers[i + 1], numbers[high]);
//
//	return (i + 1);
//}

void NumberList::fillScreenWithRects(int time) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
	SDL_RenderClear(renderer); // fill screen with black

	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255); // pink

	for (int i = 0; i < (SIZE_OF_RECTS); i++) { 
		rects[i].h = (numbers[i]); // init height with height values of numbers
		rects[i].w = 2; // init width
		rects[i].x = i * 2; // init x pos
		rects[i].y = (SCREEN_HEIGHT - rects[i].h); // init y pos
		SDL_RenderFillRect(renderer, &rects[i]); // sets specific color of rect
	}

	SDL_RenderDrawRects(renderer, rects, SIZE_OF_RECTS);

	SDL_RenderPresent(renderer);
	SDL_Delay(time); // wait
}

void NumberList::printRectHeights() {
	for (int i = 0; i < SIZE_OF_RECTS; i++) {
		std::cout << rects[i].h << std::endl;
	}
}

NumberList::~NumberList() {
	numbers.clear(); // clears vector
}
