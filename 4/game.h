#pragma once
#include <string>
#include <vector>
#include "Construction.h"
#include "Castle.h"
#include "Level.h"
#include "Lair.h"

using std::string;
using std::vector;

namespace TowerDefence
{
	template <typename Type>
	int get(Type& x, const char* message)
	{
		while (true)
		{
			std::cout << message << std::endl;
			std::cin >> x;
			if (std::cin.eof() || std::cin.bad())
				return -1;
			else if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "Input error. Try again\n";
			}
			else
				return 0;
		}
	}
	typedef int (*function_ptr)(Level&); //idea from 3rd lab to work with function pointer
	int make_move(Level&);
	int create_tower(Level&);
	int update_castle(Level&);
	int update_tower(Level&);

	void enter(); //EXPERIMENTAL!!
	int main_menu(Level&);
	bool general_question();
	void game_over();
	void game_win();
	int exit(Level&);
//std::vector<Enemy*>  enemies;
}