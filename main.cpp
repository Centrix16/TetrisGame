#include <iostream>
#include <cstdlib>
#include <ctime>

#include "scripts.h"
//#include "tg.h"

using namespace std;

int main()
{	
<<<<<<< HEAD
	classic();
=======
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
>>>>>>> be13ad7bfa3ab39c142c4d57ee981ba38308ab6e
	return 0;
}
