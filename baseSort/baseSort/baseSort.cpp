// baseSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int startIndex;
int low;
int nums[];
int temp;

using namespace std;

void sort();

void main()
{
	int i = 0;
	cout << "Enter the first number: ";
	while (true) {
		cin >> noskipws >> temp;			// Put the number into a temporary value so we can check if it is valid.
		if (temp == -1) {					// If user input is empty, break and go onto sorting since they are done entering values.
			break;
		} else {
			nums[i] = temp;					// Put the number into the array.
		}
		i++;								// Increment i so that we are putting the next number into the next slot.
		cout << "Enter the next number (or [ENTER to begin sorting): ";
	}
	sort();
}

void sort() {
	startIndex = 0;
	for (int i = 0; i < (sizeof(nums) / 4); i++) { // Kind of obvious, but this just goes through the array until we're done.

	}
}