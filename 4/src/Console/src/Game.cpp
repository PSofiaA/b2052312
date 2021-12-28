#include "Game.h"
namespace TowerDefence
{
	const char* dialog[]
	{
		"0. Exit",
		"1. Draw a map",
		"2. Create tower",
		"3. Create trap",
		"4. Spawn enemy"
	};
	const char* object[]
	{
		"--T--",
		"--MT--",
		"--TR--",
		"--E--",
		"--C--"
	};
	const char* terrain[]
	{
		" --- ",
		" *** ",
		" >>> "
	};

	const int NMsgs = sizeof(dialog) / sizeof(dialog[0]);

	int main_menu()
	{
		const char* message = "Make your choice";
		int input;
		do {
			std::cout << std::endl << message << std::endl;
			message = "Incorrect input!";
			for (int i = 0; i < NMsgs; ++i)
				std::cout << dialog[i] << std::endl;
			if (TowerDefence::get(input, "\nMake your choice:  ") == -1)
				return 0;
		} while (input < 0 || input > NMsgs);
		return input;
	}

	void enter()
	{
		std::cout << "Enter to continue" << std::endl;
		while (std::cin.get() != '\n') {}
		return;
	}
	void game_over()
	{
		std::cout << "WINNER" << std::endl;
	}
	void game_win()
	{
		std::cout << "LOSER" << std::endl;
	}
	int draw_level(Level& level)
	{
		vector<vector<Tile*>> tt = level.get_tiles();
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (!tt[i][j]->get_object())
					std::cout << std::setw(5u) << terrain[tt[i][j]->get_terrain()];
				else
					std::cout << std::setw(5u) << object[tt[i][j]->get_object()->get_type()];
			}
			std::cout << std::endl;
		}
		std::cout << std::endl << "G O L D: " << tt[0][0]->get_object()->get_gold();
		return 0;
	}
	int create_tower(Level& level)
	{
		int a, x, y, b;
		std::cout << "Choose coordinates of tile" << std::endl;
		get(x, "x:  ");
		get(y, "y:  ");
		get(a, "Choose tower type: 1 for magic tower  and 2 for simple tower");
		switch (a)
		{
		case 1:
		{
			get(b, "Choose effect: Weakening - 1 \n Poisoning - 2 \n Deceleration - 3\n");
			if (b == 1)
			{
				Weakening* effect = new Weakening();
				MagicTower* mtower = new MagicTower(effect, 10, x, y);
				try
				{
					level.add(mtower, x, y);
				}
				catch (std::runtime_error& error)
				{
					std::cout << "Attempt failed" << std::endl;
					std::cout << error.what();
				}
			}
			if (b == 2)
			{
				Poisoning* effect = new Poisoning();
				MagicTower* mtower = new MagicTower(effect, 11, x, y);
				try
				{
					level.add(mtower, x, y);
				}
				catch (std::runtime_error& error)
				{
					std::cout << "Attempt failed" << std::endl;
					std::cout << error.what();
				}
			}
			if (b == 3)
			{
				Deceleration* effect = new Deceleration();
				MagicTower* mtower = new MagicTower(effect, 9, x, y);
				try
				{
					level.add(mtower, x, y);
				}
				catch (std::runtime_error& error)
				{
					std::cout << "Attempt failed" << std::endl;
					std::cout << error.what();
				}
			}
			return 0;
		}
		case 2:
		{
			Tower* tower = new Tower(10, x, y, TOWER);
			try
			{
				level.add(tower, x, y);
			}
			catch (std::runtime_error& error)
			{
				std::cout << "Attempt failed" << std::endl;
				std::cout << error.what();
			}
		}
		return 0;
		}
	
	}
	int create_trap(Level& level)
	{
		int a, x, y, b;
		std::cout << "Choose coordinates of tile" << std::endl;
		get(x, "x:  ");
		get(y, "y:  ");
		get(b, "Choose effect: Weakening - 1 \n Poisoning - 2 \n Deceleration - 3\n");
		if (b == 1)
		{
			Weakening* effect = new Weakening();
			MagicTrap* trap = new MagicTrap(10, x, y, effect);
			try
			{
				level.add(trap, x, y);
			}
			catch (std::runtime_error& error)
			{
				std::cout << "Attempt failed" << std::endl;
				std::cout << error.what();
			}
		}
		if (b == 2)
		{
			Poisoning* effect = new Poisoning();
			MagicTrap* trap = new MagicTrap(10, x, y, effect);
			try
			{
				level.add(trap, x, y);
			}
			catch (std::runtime_error& error)
			{
				std::cout << "Attempt failed" << std::endl;
				std::cout << error.what();
			}
		}
		if (b == 3)
		{
			Deceleration* effect = new Deceleration();
			MagicTrap* trap = new MagicTrap(10, x, y, effect);
			try
			{
				level.add(trap, x, y);
			}
			catch (std::runtime_error& error)
			{
				std::cout << "Attempt failed" << std::endl;
				std::cout << error.what();
			}
		}
		return 0;
	}
}