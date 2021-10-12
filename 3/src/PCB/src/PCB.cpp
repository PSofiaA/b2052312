#include "PCB.h"

const char* error[]{
		"Error! Incorrect type! Output - 0, input - 1\n",
		"Error! Contact could be connected only to 1 or 0 element\n",
		"Error! Overload! \n",
		"Error! Incorrect index! \n",
		"Incorrect connection! \n",
		"Incorrect input! \n"
};
bool Contact::operator==(const Contact a) const noexcept
{
	return (this->connected_num == a.connected_num && this->type == a.type && this->x == a.x && this->y == a.y);
}
Contact::Contact() noexcept 
{
	this->type = 0;
	this->x = 0;
	this->y = 0;
	this->connected_num = -1;
}
Contact::Contact(const int type, int x, int y)
{
	if (type > 1 || type < 0)
		throw invalid_argument(error[0]);
	this->type = type;
	this->x = x;
	this->y = y;
	this->connected_num = -1;
}
PCB::PCB() noexcept {
	this->Inputs = 0;
	this->Outputs = 0;
}
PCB::PCB(const int In,const int Out)
{
	if (In < 0 || Out < 0)
		throw invalid_argument(error[5]);
	if (In + Out > 20)
		throw logic_error(error[2]);
	this->Inputs = In;
	this->Outputs = Out;
	srand(time(NULL));
	for (int i = 0; i < In; i++) {
		this->trass[i].type = INPUT;
		this->trass[i].connected_num = -1;
		this->trass[i].x = 1 + 4 * rand() / (int)RAND_MAX;
		this->trass[i].y = 0 + 4 * rand() / (int)RAND_MAX;
	}
	for (int j = In; j < Out + In; j++) {
		this->trass[j].type = OUTPUT;
		this->trass[j].connected_num = -1;
		this->trass[j].x = 1 + 4 * rand() / (int)RAND_MAX;
		this->trass[j].y = 0 + 4 * rand() / (int)RAND_MAX;
	}
}

PCB PCB::get_Contacts(Contact*& c) noexcept
{
	for (int i = 0; i < Inputs + Outputs; i++)
		c[i] = this->trass[i];
	return *this;
}
int PCB::get_Inputs() noexcept
{
	return Inputs;
}
int PCB::get_Outputs() noexcept
{
	return Outputs;
}

PCB PCB::print() const noexcept
{
	if (this->Inputs == 0 && this->Outputs == 0)
	{
		cout << "Nothing here" << std::endl;
		return *this;
	}
	for (int i = 0; i < Inputs + Outputs; i++)
	{
		if (this->trass[i].type == INPUT)
			cout << i+1 << "th contact " << "  TYPE: INPUT, X: " << this->trass[i].x << " Y: " << this->trass[i].y << std::endl;
		else 
			cout << i+1 << "th contact " << "  TYPE: OUTPUT, X: " << this->trass[i].x << " Y: " << this->trass[i].y << std::endl;
		if (this->trass[i].connected_num != -1)
			cout << "	CONNECTED: " << this->trass[i].connected_num + 1 << std::endl;
	}
	return *this;
}
PCB PCB::create_contact(int type, int X, int Y)
{
	try
	{
		Contact Ñ(type, X, Y);
		return add_contact(Ñ);
	}
	catch (const std::logic_error& error) 
	{
		throw error;
	}
}
PCB PCB::add_contact(Contact c)
{
	if (Inputs + Outputs >= 20)
		throw length_error(error[5]);
	if (existance(c) == 0)
	{
		this->trass[Inputs + Outputs] = c;
		if (c.type == 0)
			Outputs++;
		else Inputs++;
	}
	return *this;

}
int PCB::existance(Contact c) const noexcept
{
	for (int i = 0; i < Inputs + Outputs; i++)
	{
		if (c == trass[i])
			return 1;
	}
	return 0;
}
int PCB::check(int index) const noexcept
{
	if (this->trass[index].connected_num != -1)
		return -1;
	return 0;
}
PCB PCB::connect(int a, int b)
{
	a = a - 1;
	b = b - 1;
	if (a > SIZE || b > SIZE) 
		throw invalid_argument(error[3]);
	if (a > Inputs + Outputs || b > Inputs + Outputs)
		throw invalid_argument(error[3]);
	if (this->trass[a].type == this->trass[b].type)
		throw invalid_argument(error[3]);
	else if (check(a)==-1 || check(b)==-1)
		throw invalid_argument(error[3]);
	else
	{
		this->trass[a].connected_num = b;
		this->trass[b].connected_num = a;
	}
	return *this;
}

int PCB::length(int a, int b)
{
	int AB, s1, s2;
	a = a - 1;
	b = b - 1;
	if (a >Inputs + Outputs || b > Inputs + Outputs)
		throw logic_error(error[3]);
	else
	{
		s1 = (this->trass[b].x - this->trass[a].x) * (this->trass[b].x - this->trass[a].x);
		s2 = (this->trass[b].y - this->trass[a].y) * (this->trass[b].y - this->trass[a].y);
		AB = round(pow(s1+s2, 0.5));
		return AB;
	}
}
PCB PCB::highlight(const int choice) noexcept
{
	if (choice == 1)
	{
		for (int i = 0; i < Inputs + Outputs; i++)
		if (this->trass[i].type == INPUT)
			cout << i + 1 << "th contact " << "  TYPE: INPUT, X: " << this->trass[i].x << " Y: " << this->trass[i].y << std::endl;
	}
	if (choice == 2)
	{
		for (int i = 0; i < Inputs + Outputs; i++)
			if (this->trass[i].type == OUTPUT)
				cout << i + 1 << "th contact " << "  TYPE: INPUT, X: " << this->trass[i].x << " Y: " << this->trass[i].y << std::endl;
	}
	return *this;
}
/*PCB::PCB(int type, int x, int y)
{
	if (type > 1 || type < 0)
		throw invalid_argument(error[0]);
	this->trass[0].type = type;
	if (type == 1)
		this->Inputs++;
	else this->Outputs++;
	this->trass[0].x = x;
	this->trass[0].y = y;
	this->trass[0].connected_num = -1;
}*/