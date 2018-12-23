#include <iostream>		// cout
#include <time.h>		// time
#include <stdlib.h>		// srand
#include <conio.h>		// _getch

#include <SDL.h>

#include "NumberList.h"

int main(int argc, char **argv) {

	NumberList numbers;

	numbers.shuffleNumbers();
	numbers.fillScreenWithRects(2000);

	numbers.selectionSort();
	SDL_Delay(2000);
	numbers.shuffleNumbers();
	numbers.fillScreenWithRects(2000);

	numbers.bubbleSort();
	SDL_Delay(2000);

	numbers.shuffleNumbers();
	numbers.fillScreenWithRects(2000);
	numbers.insertionSort();
	SDL_Delay(2000);

	return 0;
}
