#include "Vector3.h"
#include "Dialog.h"
using namespace Prog3;
int main() {
    Vector3* vector = new Vector3();
	std::cout << " VECTOR CALCULATOR " << std::endl;
	int choice = -1;
	function_ptr menu[] = { nullptr, add_element, print, ascending, descending,sum_between };
	while (true)
	{
		choice = main_menu();
		if (choice == 0)
			break;
		menu[choice](*vector);
	}
	delete vector;
	return 0;
}
