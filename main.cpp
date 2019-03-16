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
	Tg tg(10, 10);
	tg.detT = 2;
	tg.SetDet(5);
	tg.show();
	char choice = 'n';	
	for (;;)
	{
		cin >> choice;
		tg.Move(choice);	
		//system(CLS);
		tg.show();
	}
	return 0;
}
