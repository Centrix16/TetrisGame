#ifndef TG_H
#define TG_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//константы для класса TetrisGame
//нулевое значение - отсутствие символа
const char    ColorProbel = ' ';
const char        UpRamka = '_';
const char      LeftRamka = '|';
const char      DownRamka = '_';
const char     RightRamka = '|';
const char    UpLeftRamka = '@';
const char   UpRightRamka = '@';
const char DownRightRamka = '@';
const char  DownLeftRamka = '@';


//класс TetrisGame
class TetrisGame
{
public:
	//закрытые поля класса
	int width;
	int height;
	
	vector<char> Ground;
	int detX[4];
	
	char detC;
	
	int score;
	int record;
	int line;
	
	//закрытые функции
	void SettingGround(int width, int height);
	int Square();

public:
	//открытые функции-члены
	TetrisGame(int Width = 10, int Height = 20) : width(Width), height(Height), score(0), record(0), line(0)
	{
		SettingGround(width, height);
	}
	
	void show();
	
	void SetDet(int detT);
	void SetDetKub();
	
	void Move(char m);
	void Down();
	void Left();
	void Right();
	
};

//
void TetrisGame::SettingGround(int width = 10, int height = 20)
{
	int NumberKletok = width * height;
	for (int i = 0; i < Square(); i++)
	{
		Ground.push_back(ColorProbel);
	}
}

int TetrisGame::Square()
{
	return width * height;
}

//
void TetrisGame::show()
{
	cout << "score " << score << endl;
	cout << "record " << record << endl;
	cout << "line " << line << endl;
	
	if (UpRamka)
	{
		if (UpLeftRamka) cout << UpLeftRamka;
		for (int x = 0; x < width; x++) cout << UpRamka;
		if (UpRightRamka) cout << UpRightRamka;
		cout << endl;
	}
	
	for (int y = 0; y < height; y++)
	{
		if (LeftRamka) cout << LeftRamka;
		for (int x = 0; x < width; x++) cout << Ground[x + y * width];
		if (RightRamka) cout << RightRamka;
		cout << endl;
	}
	
	if (DownRamka)
	{
		if (UpLeftRamka) cout << DownLeftRamka;
		for (int x = 0; x < width; x++) cout << DownRamka;
		if (UpRightRamka) cout << DownRightRamka;
		cout << endl;
	} 
}

void TetrisGame::SetDet(int detT)
{
	detC = '#';
	
	switch(detT)
	{
		case 0:
			SetDetKub();
			break;
		default:
			cout << "Error! ";
			return;
	}
	
	for (int i = 0; i < 4; i++)
	{
		Ground[detX[i]] = detC;
	}
}

void TetrisGame::SetDetKub()
{
	detX[0] = 2;
	detX[1] = detX[0] + 1;
	detX[2] = detX[0] + width;
	detX[3] = detX[2] + 1;
}

void TetrisGame::Move(char m)
{
	switch (m)
	{
		case 'd':
			Down();
			break;
		case 'l':
			Left();
			break;
		case 'r':
			Right();
			break;
		default:
			cout << "Error!";
	}
}
void TetrisGame::Down()
{
	bool is_move = false;
	
	for (int i = 0; i < 4; i++)
	{
		if (detX[i] >= Square() - width)
		{
			is_move = false;
			break;
		} else if (Ground[detX[i]] != detC)
		{
			continue;
		} else if (Ground[detX[i]] != ColorProbel)
		{
			is_move = false;
			break;
		}
	}
	if (is_move == true)
	{
		for (int i = 0; i < 4; i++)
		{
			Ground[detX[i]] = ColorProbel;
			detX[i] = detX[i] + width;
		}
	} else
	{
		return;
	}
	
	for (int i = 0; i < 4; i++)
	{
		Ground[detX[i]] = detC;
	}
}

void TetrisGame::Left()
{
	
}

void TetrisGame::Right()
{
	
}

#endif
