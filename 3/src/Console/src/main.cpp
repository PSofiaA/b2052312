#include "dialog.h"
int main()
{
	PCB* pcb = new PCB();
	std::cout << "PRINTED CIRCUIT BOARD" << std::endl;
	int choice = -1;
	function_ptr menu[] = { nullptr, Dadd_cont, Dconnect, Dhighlight, Dlength, Dprint};
	while (true)
	{	
		choice = main_menu();
		if (choice == 0)
			break;
		menu[choice](*pcb);
	}
	delete pcb;
	return 0;
}