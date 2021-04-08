#include"GameManager.h"
#include"Color.h"
#include<iostream>

//Global Variable
GameManager gm;
Color color;

//Prototype Function
void ShowGame();

int main() {
	int menu;
	bool gameOn = true;

	while (gameOn != false) {
		color.SetColor(7);
		cout << endl;
		cout << "=========================================================" << endl;
		cout << "                      SUDOKU                        " << endl;
		cout << "=========================================================" << endl;
		cout << "                        made by : " << endl;
		cout << "             4210191015 - Vivian Azalia A" << endl;
		cout << "             4210191021 - Intan Putri K. W" << endl << endl;
		cout << "               Praktikum Pemrograman 4" << endl << endl;
		cout << " 1) Start the game.\n";
		cout << " 2) Exit.\n";
		cout << " Enter your choice and press return: ";

		cin >> menu;

		switch (menu)
		{
		case 1:
			ShowGame();
			break;
		case 2:
			color.SetColor(12);
			cout << "\n --- The game has ended !!! ---\n";
			gameOn = false;
			break;
		default:
			color.SetColor(12);
			cout << " Not a Valid Choice. \n";
			cout << " Choose again.\n";
			cin >> menu;
			break;
		}
	}

	system("pause");

	return 0;
}

void ShowGame() {
	gm.StartGame();

	while (!gm.IsMatching())
	{
		gm.Input();
	}
}


//4210191015 - Vivian Azalia A
//4210191021 - Intan Putri K W