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
        cin >> choice; if (choice == 'e') break;
		tg.Move(choice);	
		system(CLS);
		tg.show();
        if (tg.DistanceBottomGround() == 0)
        {
            cout << "IsDown " << endl;
            for (;;)
            {
                cin >> choice; if (choice == 'd') break;
                tg.detT = 2;
	            tg.SetDet(5);
		        system(CLS);
	            tg.show();
            }
        }
	}
	return 0;
}
