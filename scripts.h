#ifndef SCRIPTS_H
#define SCRIPTS_H

#if _WIN32
#define CLS "cls"
#else
#define CLS "clear"
#endif

#include <ctime>
#include <cstdlib>
#include "tg.h"


using std::cout;

void classic();

void classic(){
	srand(time(NULL));
	Tg tg(10, 10);
	tg.detT = 2;//rand() % 7;
	tg.SetDet(5);
	int turn = 1 + rand() % 4; for (int i = 0; i < turn; i++) tg.TurnDet();
	system(CLS);
	tg.show();
	char choice = 'n';	
	while (true)
	{
        if (tg.DistanceBottomGround() == 0)
        {
            //если деталь касается другой детали или дна стакана
            while (true)
            {
                cin >> choice; if (choice == 'd') break; if (choice == 'e') exit(0);
                tg.Move(choice);
                system(CLS);
				tg.show();
		        if (tg.DistanceBottomGround() != 0)
		        {
					//если деталь уже не касается другой детали или дна стакана
					//то переходим к label
		        	goto label;
		        }
            }
			tg.detT = rand() % 7;
			tg.DeletingLines();
	        tg.SetDet(5);
	        turn = 1 + rand() % 4; for (int i = 0; i < turn; i++) tg.TurnDet();
	        system(CLS);
			tg.show();
        }
        label://метка
        cin >> choice; if (choice == 'e') break; if (choice == 'e') exit(0);
		tg.Move(choice);
		system(CLS);
		tg.show();
	}
	return;
}

#endif