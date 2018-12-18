#include <iostream>		// cout
//#include <vector>		// vector
//#include <algorithm>	// random_shuffle, sort, swap
//#include <time.h>		// time
//#include <chrono>		// chrono
//#include <stdlib.h>	// srand
#include <conio.h>		// _getch
#include "NumberList.h"


//vector<int> initialize(vector<int>, int size);
//void printVector(vector<int>);
//vector<int> shuffle(vector<int>);
//vector<int> sort(vector<int>);
//vector<int> selectionSort(vector<int>); // O(n^2)
//vector<int> insertionSort(vector<int>);
//vector<int> bubbleSort(vector<int>); 
//vector<int> quickSort(vector<int>, int, int); 
//int partition(vector<int>, int, int); // used in quickSort

int main() {

	/*vector<int> numbers;
	numbers = initialize(numbers, 10);
	printVector(numbers);

	numbers = shuffle(numbers);
	printVector(numbers);*/

	//numbers = quickSort(numbers, numbers.back(), numbers.front());
	//numbers = shuffle(numbers);
	//numbers = sort(numbers);
	//numbers = shuffle(numbers);
	//numbers = selectionSort(numbers);
	//numbers = shuffle(numbers);
	//numbers = insertionSort(numbers);
	//numbers = shuffle(numbers);
	//numbers = bubbleSort(numbers);

	NumberList numbers;
	numbers.initialize(10);
	numbers.printVector();

	// good old sorting algorithm
	numbers.shuffle();
	numbers.printVector();
	numbers.sort();
	numbers.printVector();

	// selection sort
	numbers.shuffle();
	numbers.printVector();
	numbers.selectionSort();
	numbers.printVector();

	// insertion sort
	numbers.shuffle();
	numbers.printVector();
	numbers.insertionSort();
	numbers.printVector();

	// bubble sort
	numbers.shuffle();
	numbers.printVector();
	numbers.bubbleSort();
	numbers.printVector();

	_getch();
	return 0;
}

//vector<int> initialize(vector<int> numbers, int size) {
//	auto start = chrono::system_clock::now();
//
//	for (int i = 1; i <= size; i++) { // initialize
//		numbers.push_back(i);
//	}
//
//	auto end = chrono::system_clock::now();
//	auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
//	cout << "Time elapsed for initialization: " << duration.count() << endl;
//
//	return numbers;
//}
//
//void printVector(vector<int> numbers) {
//	for (int i = 0; i < numbers.size(); i++) {
//		cout << numbers[i] << "\t";
//	}
//}
//
//vector<int> shuffle(vector<int> numbers) {
//	auto start = chrono::system_clock::now();
//
//	random_shuffle(numbers.begin(), numbers.end());
//
//	auto end = chrono::system_clock::now();
//	auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
//	cout << "Time elapsed for shuffle: " << duration.count() << endl;
//
//	return numbers;
//}
//
//vector<int> sort(vector<int> numbers) { // sort algorithm using sort function from <algorithm>
//	auto start = chrono::system_clock::now();
//
//	sort(numbers.begin(), numbers.end());
//
//	auto end = chrono::system_clock::now();
//	auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
//	cout << "Time elapsed for sort: " << duration.count() << endl;
//
//	return numbers;
//}
//
//vector<int> selectionSort(vector<int> numbers) {
//	auto start = chrono::system_clock::now();
//
//	int selection;
//
//	for (int i = 0; i < numbers.size(); i++) {
//		selection = i;
//		for (int j = i+1; j < numbers.size(); j++) {
//			if (numbers[j] < numbers[selection]) {
//				selection = j;
//			}
//		}
//		swap(numbers[selection], numbers[i]);
//	}
//
//	auto end = chrono::system_clock::now();
//	auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
//	cout << "Time elapsed for selection sort: " << duration.count() << endl;
//
//	return numbers;
//}
//
//vector<int> insertionSort(vector<int> numbers) {
//	auto start = chrono::system_clock::now();
//	int position, valueToInsert;
//
//	for (int i = 0; i < numbers.size(); i++) {
//		// select value to be inserted
//		valueToInsert = numbers[i];
//		position = i;
//
//		while (position > 0 && numbers[position-1] > valueToInsert) {
//			numbers[position] = numbers[position - 1];
//			position = position - 1;
//		}
//
//		numbers[position] = valueToInsert;
//	}
//
//	auto end = chrono::system_clock::now();
//	auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
//	cout << "Time elapsed for insertion sort: " << duration.count() << endl;
//
//	return numbers;
//}
//
//vector<int> bubbleSort(vector<int> numbers) {
//	auto start = chrono::system_clock::now();
//	
//	bool swapped;
//
//	for (int i = 0; i < numbers.size()-1; i++) {
//		swapped = false;
//		for (int j = 0; j < numbers.size() - 1; j++) {
//			if (numbers[j] > numbers[j + 1]) {
//				swap(numbers[j], numbers[j + 1]);
//				swapped = true;
//			}
//		}
//		if (!swapped)
//			break;
//	}
//
//	auto end = chrono::system_clock::now();
//	auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
//	cout << "Time elapsed for bubble sort: " << duration.count() << endl;
//
//	return numbers;
//}

//vector<int> quickSort(vector<int> numbers, int low, int high) {
//	auto start = chrono::system_clock::now();
//
//	if (low < high) {
//		// pi is partitioning index, numbers[pi] is now at right place
//		int pi = partition(numbers, low, high);
//
//		quickSort(numbers, low, pi - 1);
//		quickSort(numbers, pi + 1, high);
//	}
//
//	auto end = chrono::system_clock::now();
//	auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
//	cout << "Time elapsed for quick sort: " << duration.count() << endl;
//
//	return numbers;
//}
//
//int partition(vector<int> numbers, int low, int high) {
//	// pivot (Element to be placed at right position
//	int pivot = numbers[high];
//
//	int i = (low - 1); // Index of smaller element
//
//	for (int j = low; j <= high - 1; j++) {
//		// If current element is smaller than or equal to pivot
//		if (numbers[j] <= pivot) {
//			i++;
//			swap(numbers[j], numbers[i]);
//		}
//	}
//	swap(numbers[i + 1], numbers[high]);
//
//	return (i + 1);
//}