#include <iostream>
#include "tg.h"
#include <cstdlib>

#if _WIN32
#define CLS "cls"
#else
#define CLS "clear"
#endif

using namespace std;

typedef TetrisGame Tg;

int main()
{
	system("chcp 866>nul");
	Tg tg(10, 10);
	tg.SetDet(1, 9);
	tg.show();
	char choice = 'n';
	while (choice != 'e')
	{
		cin >> choice;
		tg.Move(choice);
		//system(CLS);
		tg.show();
	}
	return 0;
}
