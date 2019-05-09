#include <iostream>
#include "source.h"
#include <windows.h>
#include <ctime>
#include <conio.h>
using namespace std;

int main()
{
	
	system("pause>>NULL");
	return 0;
}

void ScreenOutput(char scr[14][50])
{
	system("cls");
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 50; j++)
			cout << scr[i][j];
		if (i != 13)
			cout << endl;
	}
}
void Help(int switcher)
{
	system("cls");
	cout << "Scroll: Up / Down Arrows | return : ESCAPE\n";
	char arr[1800] = {"Management in the menu \
Move through the items - up / down arrows select the item\
 - SPACE or ENTER Return to the previous menu - ESCAPE\
 CONTROL IN THE GAME \
Move up / down - UP / DOWN ARROW Take a shot - SPACEBAR Return to the menu, saving the game ESCAPE\
BRIEFING  You are a pilot of a space ship caught in a space storm. "};
	for (int i = 0, buf = switcher;i<13;i++)
	{
		for (int j = buf * 50; j < buf * 50 + 50; j++)
			cout << arr[j];
		if (i != 12)
			cout << endl;
		buf++;
	}
	int controller = _getch();
	if (controller == 224)
		controller = _getch();
	if (controller == Up)
		if (switcher > 0)
			Help(switcher - 1);
		else
			Help(0);
	if (controller == Down)
		if (switcher < 22)
			Help(switcher + 1);
		else
			Help(22);
	if (controller == Es_cape)
		StartMenu(2);
}

void StartMenu(int switcher)
{
	system("cls");
	switch (switcher)
	{
	case 1:
		cout<<"\n\n\n                             <<   PLAY!   >>\n\n \
		HELP! \n\n              Hall of Fame\n\n                        EXIT";
		break;
	case 2:
		cout << "\n\n\n                                PLAY!\n\n          <<\
		HELP!   >>\n\n              Hall of Fame\n\n                        EXIT";
		break;
	case 3:
		cout << "\n\n\n                                PLAY!\n\n \
		HELP! \n\n              <<   Hall of Fame   >>\n\n                        EXIT";
		break;
	case 4:
		cout << "\n\n\n                                 PLAY!\n\n \
		HELP! \n\n              Hall of Fame\n\n                    <<   EXIT   >>";
		break;
	}
	int choice = _getch();
	if (choice == 224)
		choice = _getch();
	if (choice == Up)
		if (switcher != 1)
			StartMenu(switcher - 1);
		else
			StartMenu(4);
	if (choice == Down)
		if (switcher != 4)
			StartMenu(switcher + 1);
		else
			StartMenu(1);
	if (choice == 13 || choice == 32)
	{
		if (switcher == 1)
			GameMenu(1);
		if (switcher == 2)
			Help(0);
		if (switcher == 3)
			TopChart();
		if (switcher == 4)
			_exit(0);
	}
}
void GameMenu(int switcher)
{
	system("cls");
	if (switcher == 1)
		cout << "\n\n\n\n\n                                   <<    NEW GAME!   >>\n\n\
CONTINUE!";
	else
		cout << "\n\n\n\n\n                                           NEW GAME!\n\n                      <<\
CONTINUE!   >>";
	int choice = _getch();
	if (choice == 224)
		choice = _getch();
	if (choice == Up || choice == Down)
		GameMenu(3 - switcher);
	if (choice == Es_cape)
		StartMenu(1);
	if (choice == 13 || choice == 32)
		Game(switcher);
}

void GameStart(char scr[14][50],int lifes,int *timer)
{
	for (int i = 0; i < 14; i++)
		for (int j = 0; j < 50; j++)
			scr[i][j] = ' ';
	for (int i = 50; lifes > 0; i--, lifes--)
		scr[0][i] = '&';
	*timer = 80;
	char borderSymbols[] = {'∤',' ‡  ','⁜',' '};
	for (int aboveBelow = 0; aboveBelow < 50; aboveBelow++)
	{
		scr[1][aboveBelow] = borderSymbols[rand() % 3];
		if (scr[1][aboveBelow] == '‡')
			scr[2][aboveBelow] = '⁜';

		scr[13][aboveBelow] = borderSymbols[rand() % 3];
		if (scr[13][aboveBelow] == '‡')
			scr[12][aboveBelow] = '⁜';
	}
	scr[6][0] = '\\'; scr[6][1] = '\\';
	scr[7][0] = '3'; scr[7][1] = '='; scr[7][2] = '=';
	scr[8][0] = '/'; scr[8][1] = '/';
}

void GameOver(int score)
{
	system("cls");
	player newPlayer;
	newPlayer.score = score;
	cout << "";
}
void TopChart()
{

}
void Game(int var)
{

}