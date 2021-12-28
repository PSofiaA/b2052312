#pragma once
#include <string>
#include <vector>
#include <Deceleration.h>
#include <Poisoning.h>
#include <Weakening.h>
#include <Trap.h>
#include <Castle.h>
#include <Level.h>
#include <Tower.h>
#include <MagicTower.h>
#include <iomanip> 
#include <iostream>

using std::string;
using std::vector;

namespace TowerDefence
{
	/*class Game {
	private:
		int timer;
		Level* level;
	public:
		Game() : timer(0) {level = new Level};
	};*/
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
	typedef int (*function_ptr)(Level& level);//idea from 3rd lab to work with function pointer
	int create_tower(Level&);
	int create_trap(Level&);
	int draw_level(Level&);
	//int spawn_enemy(Level&);

	void enter(); //EXPERIMENTAL!!
	int main_menu();
	void game_over();
	void game_win();
//std::vector<Enemy*>  enemies;
}