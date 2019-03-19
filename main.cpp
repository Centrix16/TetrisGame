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
	while (true)
	{
        cin >> choice; if (choice == 'e') break;
		tg.Move(choice);
		//system(CLS);
		tg.show();
		cout << "dist " << tg.DistanceBottomGround() << endl;
        if (tg.DistanceBottomGround() == 0)
        {
            cout << "IsDown!" << endl;
            for (;;)
            {
                cin >> choice; if (choice == 'd') break;
                tg.Move(choice);
				tg.show();
		        //system(CLS);
	            tg.show();
            }
			tg.detT = 2;
	        tg.SetDet(5);
			tg.show();
        }
	}
	return 0;
}
