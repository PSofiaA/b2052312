#include "PCB.h"

const char* error[]{
		"Error! Incorrect type! Output - 0, input - 1\n", //0
		"Error! Contact could be connected only to 1 or 0 element\n", //1
		"Error! Incorrect index! \n", //2
		"Invalid connection! \n", //3
		"This contact already exists \n",//4
		"Empty \n" //5
};
bool Contact::operator==(const Contact a) const noexcept
{
	return (this->connected_num == a.connected_num && this->type == a.type && this->x == a.x && this->y == a.y);
}
Contact& Contact::operator=(Contact c)
{
	this->connected_num = c.connected_num;
	this->type = c.type;
	this->x = c.x;
	this->y = c.y;
	return *this;
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
	if (type > 1 || type<0)
		throw invalid_argument(error[0]);
	this->type = type;
	this->x = x;
	this->y = y;
	this->connected_num = -1;
}
PCB::PCB() noexcept {
	// ����� ������ ��� ������ �������� �������� �� �����, ��� �������� ��� ����������
	// ���������������� ������� ���� �� ����� - ��� ��������� ������ �������� ����������� ������� �� ���������
	this->Inputs = 0;
	this->Outputs = 0;
}
PCB::PCB(int type, int x, int y)
{
	if (type > 1)
		throw invalid_argument(error[0]);
	this->trass[0].type = type;
	if (type == 1)
		this->Inputs++;
	else this->Outputs++;
	this->trass[0].x = x;
	this->trass[0].y = y;
	this->trass[0].connected_num = -1;
}
PCB::PCB(const int In,const int Out)
{
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
int PCB::get_Inputs() const noexcept
{
	return Inputs;
}
int PCB::get_Outputs() const noexcept
{
	return Outputs;
}
PCB PCB::get_Contacts(Contact*& c) noexcept
{
	for (int i = 0; i < Inputs + Outputs; i++)
		c[i] = this->trass[i];
	return *this;
}
int PCB::get_Size() const noexcept
{
	return (Inputs + Outputs);
}
PCB PCB::add_contact(int type, int X, int Y)
{
	try
	{
		Contact �(type, X, Y);
		return add_contact(�);
	}
	catch (const logic_error& error) 
	{
		throw error;
	}
	catch (const invalid_argument& error)
	{
		throw error;
	}
}
PCB PCB::add_contact(Contact c)
{
	if (Inputs + Outputs >= 20)
		throw logic_error(error[2]);
	if (existance(c))
		throw invalid_argument(error[4]);
	this->trass[Inputs + Outputs] = c;
		if (c.type == 0)
			Outputs++;
		else Inputs++;
	return *this;
}
Contact PCB::find(int index) const
{
	if (index > Inputs + Outputs)
		throw logic_error(error[2]);
	return this->trass[index];	
}
bool PCB::existance(Contact c) const noexcept
{
	for (int i = 0; i < Inputs + Outputs; i++)
	{
		if (c == trass[i])
			return true;
	}
	return false;
}
bool PCB::check(int index) const noexcept
{
	if (this->trass[index].connected_num != -1)
		return false;
	return true;
}
bool PCB::check(int a, int b) const noexcept
{
	if (a > SIZE || b > SIZE)
		return false;
	if (a > Inputs + Outputs || b > Inputs + Outputs)
		return false;
	if (this->trass[a].type == this->trass[b].type)
		return false;
	return true;
}
PCB PCB::connect(int a, int b)
{
	a = a - 1;
	b = b - 1;
	if (!check(a,b) || !check(a) || !check(b))
		throw invalid_argument(error[3]);
	else
	{
		this->trass[a].connected_num = b;
		this->trass[b].connected_num = a;
	}
	return *this;
}
int PCB::length(int a, int b) const
{
	int AB, s1, s2;
	a = a - 1;
	b = b - 1;
	if (a >= Inputs + Outputs || b >= Inputs + Outputs)
		throw logic_error(error[2]);
	else
	{
		s1 = (this->trass[b].x - this->trass[a].x) * (this->trass[b].x - this->trass[a].x);
		s2 = (this->trass[b].y - this->trass[a].y) * (this->trass[b].y - this->trass[a].y);
		AB = round(pow(s1+s2, 0.5));
		return AB;
	}
}
PCB PCB::highlight(const int choice, Contact*&result) const noexcept
{
	int j = 0;
	if (choice == 1)
	{
		for (int i = 0; i < Inputs + Outputs; i++)
			if (this->trass[i].type == INPUT)
			{
				result[j].type = this->trass[i].type;
				result[j].connected_num = this->trass[i].connected_num;
				result[j].x = this->trass[i].x;
				result[j].y = this->trass[i].y;
				j++;
			}
	}
	if (choice == 2)
	{
		for (int i = 0; i < Inputs + Outputs; i++)
			if (this->trass[i].type == OUTPUT)
			{
				result[j].type = this->trass[i].type;
				result[j].connected_num = this->trass[i].connected_num;
				result[j].x = this->trass[i].x;
				result[j].y = this->trass[i].y;
				result[j] = this->trass[i];
				j++;
			}
	}
	return *this;
}
ostream& operator<<(ostream& out, const PCB& pcb)
{
	if (pcb.Inputs == 0 && pcb.Outputs == 0)
		out << "Nothing here" << endl;
	for (int i = 0; i < pcb.Inputs + pcb.Outputs; i++)
	{
		if (pcb.trass[i].type == INPUT)
			out << i + 1 << "th contact " << "  TYPE: INPUT, X: " << pcb.trass[i].x << " Y: " << pcb.trass[i].y << endl;
		else
			out << i + 1 << "th contact " << "  TYPE: OUTPUT, X: " << pcb.trass[i].x << " Y: " << pcb.trass[i].y << endl;
		if (pcb.trass[i].connected_num != -1)
			out << "	CONNECTED: " << pcb.trass[i].connected_num + 1 << endl;
	}
	return out;
}
istream& operator>>(istream& in, Contact& contact)
{
	int type, x, y;
	in >> type >> x >> y;
	if (type < 0 || type>1)
		throw invalid_argument(error[0]);
	contact.type = type;
	contact.x = x;
	contact.y = y;
	return in;
}
PCB& PCB::operator+=(Contact& c)
{
	try {
		return add_contact(c);
	}
	catch (const logic_error& error)
	{
		throw error;
	}
	catch (const invalid_argument& error)
	{
		throw error;
	}
}
Contact& PCB::operator[](int index)
{
	try
	{
		return find(index);
	}
	catch(const logic_error& error)
	{
		throw error;
	}
}

/*
PCB& PCB::operator=(PCB &p)
{
	this->Inputs = p.Inputs;
	this->Outputs = p.Outputs;
	delete[] this->trass;
	for (int i = 0; i < this->Inputs + this->Outputs; i++)
	{
		this->trass[i](p.trass[i]);
	}
	return *this;
}*/
/*PCB PCB::operator--()
{
	
}
PCB PCB::operator--(int)
{

}*/