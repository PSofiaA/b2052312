#include "dialog.h"
const char* dialog[]
{
	"0. Exit"
	"\n1. Add new contact",
	"2. Connect two contacts",
	"3. Highlight group of contacts",
	"4. Get length between two contacts",
	"5. Print all",
	"6. Find contact by index",
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
	Contact c;
	/*do
	{
		std::cout << message << std::endl;
		message = "Incorrect input!";
		if (get(t, "Input contact type: ") < 0 || get(x, "Input x coordinate") < 0 || get(y, "Input y coordinate") < 0)
			return -1;
	} while (t < 0);
	try
	{
		pcb.add_contact(t, x, y);
	}
	catch (std::logic_error& error)
	{
		std::cout << "Attempt failed" << std::endl;
		std::cout << error.what();
	}
		//if (!pcb.check(c))
		//return -1;*/
	cout << "Enter type (1 - input, 0 - output), X and Y coordinates of a contact: --> " << endl;
	try
	{
		cin >> c;
		pcb += c;
	}
	catch (logic_error& error)
	{
		cout << "Attempt failed" << endl;
		cout << error.what();
	}
	catch (invalid_argument& error)
	{
		cout << "Attempt failed" << endl;
		cout << error.what();
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
	Contact* a = new Contact[SIZE];
	pcb.highlight(choice, a);
	cout << "Here's the highlighted group: " << std::endl;
	if (choice == 1)
	{
		for (int i = 0; i < pcb.get_Inputs(); i++)
		cout << i + 1 << "th contact " << "X: " << a[i].x << " Y: " << a[i].y << std::endl;
	}
	if (choice == 2)
	{
		for (int i = 0; i < pcb.get_Outputs(); i++)
			cout << i + 1 << "th contact " << "X: " << a[i].x << " Y: " << a[i].y << std::endl;
	}
	delete[] a;
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
	cout << pcb;
	return 0;
}
int Dfind(PCB& pcb)
{
	int index;
	Contact a;
	if (get(index, "Input contact index you want to be found: ") < 0)
		return -1;
	try
	{
		a = pcb[index-1];
		if(a.type == INPUT)
			cout << index << "th contact TYPE:INPUT ";
		else 
			cout << index << "th contact TYPE:OUTPUT ";
		cout << "X: " << a.x << " Y: " << a.y << std::endl;
	}
	catch (std::logic_error& error)
	{
		std::cout << "Attempt failed" << std::endl;
		std::cout << error.what();
	}
	return 0;
}

