#include <iostream>
#include "tg.h"
#include <cstdlib>
using namespace std;

typedef TetrisGame Tg;

int main()
{
	Tg tg(10, 10);
	tg.SetDet(0);
	tg.show();
	char choice = 'n';
	while (choice != 'e')
	{
		cin >> choice;
		tg.Move(choice);
		system("clear");
		tg.show();
	}
	return 0;
}
