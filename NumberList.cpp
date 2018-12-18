#include "NumberList.h"



NumberList::NumberList() {
	srand(time(NULL));
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // retrieves handle for output
}

NumberList::NumberList(std::vector<int> vec) {
	numbers = vec;
	srand(time(NULL));
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // retrieves handle for output
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

std::vector<int> NumberList::shuffle() {
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

NumberList::~NumberList() {
	numbers.clear();
}
