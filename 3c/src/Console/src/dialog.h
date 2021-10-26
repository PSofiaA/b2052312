#pragma once
#include <PCB.h>
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
typedef int (*function_ptr)(PCB&);
int main_menu();
int Dadd_cont(PCB& pcb);
int Dconnect(PCB& pcb);
int Dhighlight(PCB& pcb);
int Dlength(PCB& pcb);
int Dprint(PCB& pcb);
int Dfind(PCB& pcb);
