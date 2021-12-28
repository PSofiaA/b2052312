#include "Game.h"
using namespace TowerDefence;
int main()
{
	Level* level = new Level();
	level->init();
	int choice = -1;
	function_ptr menu[] = { nullptr,draw_level,create_tower, create_trap };
	while (true)
	{	
		choice = main_menu();
		if (choice == 0)
			break;
		menu[choice](*level);
	}
	return 0;
}