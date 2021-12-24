#include "Game.h"

namespace Tower_Defence
{
	const char* dialog[]
	{
		"0. Exit",				
		"1. Create tower",
		"2. Update castle",
		"3. Update tower",
		"4. Make move"
	};
	const int NMsgs = sizeof(dialog) / sizeof(dialog[0]);
	function_ptr menu[] = { exit, create_tower,update_castle,update_tower,make_move  };

	int main_menu(Level&) 
	{
		const char* message = "";
		int input;
		do {
			std::cout << message << std::endl;
			message = "Incorrect input!";
			for (int i = 0; i < NMsgs; ++i)
				std::cout << dialog[i] << std::endl;
			if (get(input, "\nMake your choice:  ") == -1)
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
}