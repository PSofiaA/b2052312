#include "dialog.h"
const char* dialog[]
{
	"0. Exit"
	"\n1. Add new contact",
	"2. Connect two contacts",
	"3. Highlight group of contacts",
	"4. Get length between two contacts",
	"5. Print all",
	
};
const int NMsgs = sizeof(dialog) / sizeof(dialog[0]);
int main_menu() {
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
int Dadd_cont(PCB& pcb)
{
	int t;
	int x, y;
	const char* message = "";
	do
	{
		std::cout << message << std::endl;
		message = "Incorrect input!";
		if (get(t, "Input contact type: ") < 0 || get(x, "Input x coordinate") < 0 || get(y, "Input y coordinate") < 0)
			return -1;
	} while (t < 0);
	try
	{
		pcb.create_contact(t, x, y);
	}
	catch (std::logic_error& error)
	{
		std::cout << "Attempt failed" << std::endl;
		std::cout << error.what();
	}
	return 0;
}
int Dconnect(PCB& pcb)
{
	int i1, i2;
	if (get(i1, "Input first contact index: ") < 0 || get(i2, "Input second contact index: ") < 0)
		return -1;
	try
	{
		pcb.connect(i1, i2);
	}
	catch (std::invalid_argument& error)
	{
		std::cout << "Attempt failed" << std::endl;
		std::cout << error.what();
	}
	return 0;
}
int Dhighlight(PCB& pcb)
{
	int choice;
	if (get(choice, "Choose criterion: \t 1. INPUTS \t2.OUTPUTS") < 0)
			return -1;
	pcb.highlight(choice);
	return 0;
}
int Dlength(PCB& pcb)
{
	int res, i1, i2;
	if (get(i1, "Input first contact index: ") < 0 || get(i2, "Input second contact index: ") < 0)
		return -1;
	try
	{
		res = pcb.length(i1, i2);
		std::cout << "Length: " << res << std::endl;
	}
	catch (std::logic_error &error)
	{
		std::cout << "Attempt failed" << std::endl;
		std::cout << error.what();
	}

	return 0;
}
int Dprint(PCB& pcb)
{
	pcb.print();
	return 0;
}

