#ifndef TG_H
#define TG_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//константы для класса TetrisGame

//нулевое значение - отсутствие символа
const char ColorProbel = ' ';
const char UpRamka = '_';
const char LeftRamka = '|';
const char DownRamka = '_';
const char RightRamka = '|';
const char UpLeftRamka = '@';
const char UpRightRamka = '@';
const char DownRightRamka = '@';
const char DownLeftRamka = '@';

//класс TetrisGame
class TetrisGame
{
public:	
	//закрытые поля класса
	int width;
	int height;
	
	vector<char> Ground;
	
	bool is_MoveD;
	bool is_MoveL;
	bool is_MoveR;
	bool no_MoveD;
	
	int detX[4];
	char detC;
	int detT;
	
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
	
	void SetDet(int pos);
	void SetDetKub(int pos);
	void SetDetStick(int pos);
	void SetDetL(int pos);
	void SetDetAnL(int pos);
	void SetDetT(int pos);
	void SetDetN(int pos);
	void SetDetAnN(int pos);
	
	void TurnDet();
	void TurnDetKub();
	void TurnDetStick();
	void TurnDetL();
	void TurnDetAnL();
	void TurnDetT();
	void TurnDetN();
	void TurnDetAnN();
	
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
	if (is_MoveD == 0)
	{
		return false;
	}
	return true;
}

void TetrisGame::SetDet(int pos)
{
	detC = '#';
	
	is_MoveD = true;
	is_MoveL = true;
	is_MoveR = true;
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
		case 4:
			SetDetT(pos);
			break;
		case 5:
			SetDetN(pos);
			break;
		case 6:
			SetDetAnN(pos);
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

void TetrisGame::SetDetT(int pos)
{
	detX[0] = pos;
	detX[1] = detX[0] + width - 1;
	detX[2] = detX[1] + 1;
	detX[3] = detX[2] + 1;
}

void TetrisGame::SetDetN(int pos)
{
	detX[0] = pos;
	detX[1] = detX[0] + width;
	detX[2] = detX[1] + 1;
	detX[3] = detX[2] + width;
}

void TetrisGame::SetDetAnN(int pos)
{
	detX[0] = pos;
	detX[1] = detX[0] + width;
	detX[2] = detX[1] - 1;
	detX[3] = detX[2] + width;
}

void TetrisGame::Move(char m)
{
	switch (m)
	{
		case 'd':	
		case '8':
			Down();	
			break;
		case 'l':	
		case '4':
			Left();	
			break;
		case 'r':	
		case '6':
			Right();
			break;
		case 't':
		case '5':
			TurnDet();
			break;
		default:
			cout << "Error!";
	}
}

void TetrisGame::Down()
{
	for (int i = 0; i < 4; i++)	
	{
		if (detX[i] >= Square() - width)
		{
			//если хотя бы 1 часть детали в самом низу поля	
			is_MoveD = false;
			cout << 'd' << is_MoveD << endl;
			break;
		} else if (is_det(detX[i] + width))
		{
			//если внизу частьи детали другая деталь
			cout << 'm' << is_MoveD << endl;
			continue;	
		} else if (Ground[detX[i] + width] != ColorProbel)
		{
			is_MoveD = false;
			cout << 'q' << is_MoveD << endl;
			break;
		} else
		{
			is_MoveD = true;
			cout << 'n' << is_MoveD << endl;
		}
	}
	if (is_MoveD == true)
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
	for (int i = 0; i < 4; i++)
	{
		if (detX[i] % width == 0)
		{
			//если слева части детали левая стенка	
			is_MoveL = false;
			break;
		} else if (is_det(detX[i] - 1))
		{
			//если слева части детали другая часть этой детали
			continue;	
		} else if (Ground[detX[i] - 1] != ColorProbel)
		{
			is_MoveL = false;
			break;
		} else
		{
			is_MoveL = true;
		}
	}
	if (is_MoveL == true)
	{
		for (int i = 0; i < 4; i++)
		{
			Ground[detX[i]] = ColorProbel;
			detX[i] = detX[i] - 1;
		}
	}
	else
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
	for (int i = 0; i < 4; i++)
	{
		if ((detX[i] + 1) % width == 0)
		{
			//если справа части детали правая стенка
			is_MoveR = false;
			break;
		} else if (is_det(detX[i] + 1))
		{
			//если слева части детали другая часть этой детали
			continue;
		} else if (Ground[detX[i] + 1] != ColorProbel)
		{
			is_MoveR = false;
			break;
		} else
		{
			is_MoveR = true;
		}
	}
	if (is_MoveR == true)
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

void TetrisGame::TurnDet()
{
	switch (detT)
	{
		case 0:
			TurnDetKub();
			break;
		case 1:
			TurnDetStick();
			break;
		case 2:
			TurnDetL();
			break;
		case 3:
			TurnDetAnL();
			break;
		case 4:
			TurnDetT();
			break;
		case 5:
			//TurnDetN();
			break;
		case 6:
			//TurnDetAnN();
			break;
		default:
			cout << "Error";
			return;
	}
	for (int i = 0; i < 4; i++)
	{
		Ground[detX[i]] = detC;
	}
}

void TetrisGame::TurnDetKub()
{	
	//ничего не делать
}

void TetrisGame::TurnDetStick()
{
	//2 состояния
	
	for (int i = 0; i < 4; i++)
	{
		Ground[detX[i]] = ColorProbel;
	}
	
	if (detX[0] + width == detX[1]){
		//нормальное состояние
		cout << "hi";
		
		detX[0] = detX[2] - 2;
		detX[1] = detX[0] + 1;
		detX[3] = detX[2] + 1;
	} else
	{
		//2 состояние
		for (int i = 0; i < 4; i++)
		{
			Ground[detX[i]] = ColorProbel;
		}
		
		detX[0] = detX[2] - 2 * width;
		detX[1] = detX[0] + width;
		detX[3] = detX[2] + width;
	}
}

void TetrisGame::TurnDetL()
{
	//4 состояния
	
	for (int i = 0; i < 4; i++)
	{
		Ground[detX[i]] = ColorProbel;
	}
	
	if (detX[0] + width == detX[1])
	{
		//нормальное состояние
		cout << 1;
		detX[0]++;
		detX[1] -= width;
		detX[2] -= 2 * width + 1;
		detX[3] -= width + 2;
	} else if (detX[0] - 1 == detX[1])
	{
		//2 состояние
		cout << 2;
		detX[0] += 2 * width;
		detX[1] += width + 1;
		detX[2] += 2;
		detX[3] -= width - 1;
	} else if (detX[0] - width == detX[1])
	{
		//3 состояние
		cout << 3;
		detX[0] -= width + 2;
		detX[1]--;
		detX[2] += width;
		detX[3]++;
	} else
	{
		//4 состояние
		cout << 4;
		detX[0] -= width - 1;
		detX[2] += width - 1;
		detX[3] += 2 * width;
	}
}

void TetrisGame::TurnDetAnL()
{
	//4 состояния
	
	for (int i = 0; i < 4; i++)
	{
		Ground[detX[i]] = ColorProbel;
	}
	
	if (detX[0] + width == detX[1])
	{
		//нормальное состояние
		detX[0] += width;
		detX[1]--;
		detX[2] -= width + 2;
		detX[3] -= 2 * width + 1;
	} else if (detX[0] - 1 == detX[1])
	{
		//2 состояние
		detX[0] += width - 1;
		detX[2] -= width - 1;
		detX[3] += 2;
	} else if (detX[0] - width == detX[1])
	{
		//3 состояние
		detX[0] -= 2 * width + 1;
		detX[1] -= width;
		detX[2]++;
		detX[3] += width;
	} else
	{
		//4 состояние
		detX[0] += 2;
		detX[1] += width + 1;
		detX[2] += 2 * width;
		detX[3] += width - 1;
	}
}

void TetrisGame::TurnDetT()
{
	// 4 позиции
	
	for (int i = 0; i < 4; i++)
	{
		Ground[detX[i]] = ColorProbel;
	}
	
	if (detX[0] + width - 1 == detX[1])
	{
		//нормальное состояние
	} else if (detX[0] - width - 1 == detX[1])
	{
		//2 состояние
	} else if (detX[0] - width + 1)
	{
		//3 состояние
	} else
	{
		//4 состояние
	}
}

#endif
