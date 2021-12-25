#include "Game.h"
using namespace TowerDefence;
int main()
{
	Level level;
	int choice = -1;
	while (true)
	{	
		choice = main_menu();
		if (choice == 0)
			break;
	}
	return 0;
}