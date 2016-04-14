// rouletteSim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <time.h>
#include <string>
#include <math.h>
#include <random>
#include <iomanip>
#include <ctime>

int bettingMethod;
int resultColor;
int betColor;
int cash;
int gen;
int betCash;
int maxCash;
int minCash;
int wins;
double winPercentage;
bool success;

void roll();
void checkForWin();
void startRolling();
void calculatePercentage();
void endStats();

using namespace std;

void main()
{
	srand(time(0));
	cout << "Welcome to Roulette Simulator v1.4 by ScriptCloud Studios." << endl;
	cout << endl;
	cout << "What color will you bet on? " << endl;
	cout << "1. Red (48.6486%)" << endl;
	cout << "2. Black (48.6486%)" << endl;
	cout << "3. Green (2.7027%)" << endl;
	cout << "Enter your choice: ";
	cin >> betColor;
	system("CLS");

	cout << "What will your strategy be?" << endl;
	cout << "1. Double bet on loss" << endl;
	cout << "2. Double bet everytime" << endl;
	cout << "3. Double bet on win" << endl;
	cout << "4. Halve bet on loss" << endl;
	cout << "5. Halve bet everytime" << endl;
	cout << "6. Halve bet on win" << endl;
	cout << "7. Bet half of total balance everytime" << endl;
	cout << "8. All or nothing, everytime" << endl;
	cout << "Enter your choice: ";
	cin >> bettingMethod;
	system("CLS");

	cout << "What will your starting cash be? ";
	cin >> cash;
	system("CLS");
	
	if (bettingMethod != 7 || bettingMethod != 8) {
		cout << "What will your starting bet be? ";
		cin >> betCash;
	}
	
	system("CLS");

	startRolling();
}

void roll() {
	int result = rand() % 37 + 1;
	if (result <= 18)
		resultColor = 1;
	else if (result <= 36)
		resultColor = 2;
	else resultColor = 3;
	checkForWin();
}

void checkForWin() {
	if (resultColor == betColor) {
		success = true;
		wins++;
		cash += betCash;
		switch (bettingMethod) {
		case 1: betCash = betCash;
			break;
		case 2: betCash += betCash;
			break;
		case 3: betCash += betCash;
			break;
		case 4: betCash == betCash;
			break;
		case 5: betCash = betCash / 2;
			break;
		case 6: betCash = betCash / 2;
			break;
		case 7: betCash = cash / 2;
			break;
		case 8: betCash = cash;
			break;
		}
	}
		
	else {
		success = false;
		cash -= betCash;
		switch (bettingMethod) {
		case 1: betCash += betCash;
			break;
		case 2: betCash += betCash;
			break;
		case 3: betCash = betCash;
			break;
		case 4: betCash = betCash / 2;
			break;
		case 5: betCash = betCash / 2;
			break;
		case 6: betCash = betCash;
			break;
		case 7: betCash = cash / 2;
			break;
		case 8: betCash = cash;
			break;
		}
	}
}

void startRolling() {
	gen = 1;
	maxCash = cash;
	minCash = cash;
	while (cash > 0) {
		roll();
		if (cash > maxCash) {
			maxCash = cash;
		} else if (cash < minCash && cash > 0) {
			minCash = cash;
		}
		cout << "Result for generation " << gen << ": " << endl;
		cout << "Won: " << success << endl;
		if (cash < 0) {
			cout << "Broke! You bet all that you had!" << endl;
			cash = 0;
		}
		cout << "New balance: " << cash << endl;
		cout << endl;
		gen++;
	}
	calculatePercentage();
	endStats();
}

void calculatePercentage() {
	gen -= 1;
	double t1 = (double) wins / gen;
	winPercentage = t1 * 100;
}

void endStats() {
	cout << fixed;
	cout << setprecision(2);
	cout << "Statistics of this simulation: " << endl;
	cout << "Number of generations: " << gen << endl;
	cout << "Number of wins: " << wins << endl;
	cout << "Win Percentage: " << winPercentage << "%" << endl;
	cout << "Highest balance ever reached: " << maxCash << endl;
	cout << "Lowest balance ever reached: " << minCash << endl;
	cout << endl;
	cout << "Press [ENTER] to continue...";
	getchar();
	getchar();
}