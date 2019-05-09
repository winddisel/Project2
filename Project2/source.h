#pragma once
#define Es_cape 27
#define Up 72
#define Down 80
struct player
{
	char name[7];
	int score;
	int mday;
	int mon;
	int year;
};

struct save
{
	int weaponPos;
	int timer;
	int odometr;
	int lifes;
	char scr[14][50];
};
void ScreenOutput(char scr[14][50]);
void StartMenu(int switcher);
void GameMenu(int switcher);
void GameStart(char scr[14][50],int lifes,int *timer);
void Game(int var);
void GameOver(int score);
void Help(int switcher);
void TopChart();
