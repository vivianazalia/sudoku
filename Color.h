#pragma once
#include<Windows.h>

using namespace std;

class Color
{
private:
	HANDLE hCon;
public:
	Color() {
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	void SetColor(int color ) {
		SetConsoleTextAttribute(hCon, color);
	}
};

