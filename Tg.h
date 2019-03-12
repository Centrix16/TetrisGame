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
	bool is_det(int pos);

public:
	//открытые функции-члены
	TetrisGame(int Width = 10, int Height = 20) : width(Width), height(Height), score(0), record(0), line(0)
	{
		SettingGround(width, height);
	}
	
	void show();
	bool is_Move();
	
	void SetDet(int detT, int pos);
	void SetDetKub(int pos);
	void SetDetStick(int pos);
	void SetDetL(int pos);
	void SetDetAnL(int pos);

	void TurnDet(int detT, int pos);
	void TurnDetKub(int pos);
	
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

bool TetrisGame::is_det(int pos)
{
	for (int i = 0; i < 4; i++)
	{
		if (detX[i] == pos) return true;
	}
	
	return false;
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

bool TetrisGame::is_Move()
{
	for (int i = 0; i < 4; i++)
	{
		if (detX[i] >= Square() - width)
		{
			return false;
		}
	}
	return true;
}

void TetrisGame::SetDet(int detT, int pos)
{
	detC = 219;
	
	switch(detT)
	{
		case 0:
			SetDetKub(pos);
			break;
		case 1:
			SetDetStick(pos);
			break;
		case 2:
			SetDetL(pos);
			break;
		case 3:
			SetDetAnL(pos);
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

void TetrisGame::SetDetKub(int pos)
{
	detX[0] = pos;
	detX[1] = detX[0] + 1;
	detX[2] = detX[0] + width;
	detX[3] = detX[2] + 1;
}

void TetrisGame::SetDetStick(int pos)
{
	detX[0] = pos;
	detX[1] = detX[0] + width;
	detX[2] = detX[1] + width;
	detX[3] = detX[2] + width;
}

void TetrisGame::SetDetL(int pos)
{
	detX[0] = pos;
	detX[1] = detX[0] + width;
	detX[2] = detX[1] + width;
	detX[3] = detX[2] + 1;
}

void TetrisGame::SetDetAnL(int pos)
{
	detX[0] = pos;
	detX[1] = detX[0] + width;
	detX[2] = detX[1] + width;
	detX[3] = detX[2] - 1;
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
			//если хотя бы 1 часть детали в самом низу поля
			is_move = false;
			break;
		} else if (is_det(detX[i] - width))
		{
			//если внизу частьи детали другая деталь
			continue;
		} else
		{
			is_move = true;
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
	bool is_move = false;
	
	for (int i = 0; i < 4; i++)
	{
		if (detX[i] % width == 0)
		{
			//если слева части детали левая стенка
			is_move = false;
		} else if (is_det(detX[i] - 1))
		{
			//если слева части детали другая часть этой детали
			continue;
		} else
		{
			is_move = true;
		}
	}
	if (is_move == true)
	{
		for (int i = 0; i < 4; i++)
		{
			Ground[detX[i]] = ColorProbel;
			detX[i] = detX[i] - 1;
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

void TetrisGame::Right()
{
	bool is_move = false;
	
	for (int i = 0; i < 4; i++)
	{
		if ((detX[i] + 1) % width == 0)
		{
			//если справа части детали правая стенка
			is_move = false;
		} else if (is_det(detX[i] + 1))
		{
			//если слева части детали другая часть этой детали
			continue;
		} else
		{
			is_move = true;
		}
	}
	if (is_move == true)
	{
		for (int i = 0; i < 4; i++)
		{
			Ground[detX[i]] = ColorProbel;
			detX[i] = detX[i] + 1;
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

void TetrisGame::TurnDet(int detT, int pos)
{
	detC = 219;
	
	switch(detT)
	{
		case 0:
			SetDetKub(pos);
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

void TurnDetKub(int pos)
{
	//ничего не делать
}

#endif
