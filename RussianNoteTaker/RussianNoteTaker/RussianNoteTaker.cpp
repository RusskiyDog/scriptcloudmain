// RussianNoteTaker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <locale.h>
#include <iostream>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <string>

using namespace std;

wstring slova;

void main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	wcout << L"Привет! Добро пожаловать в Русский Заметка Программ v1.1 от Ник Дорр!" << endl;
	wcout << L"Пожалуйста, пишете слова по Русски: ";
	wcin >> slova;
	wcout << slova << endl;
	getchar();
	getchar();
}

