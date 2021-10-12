#pragma once
#include <iostream>
#include<time.h>
#include <string>
#include <cmath>
#define SIZE 10
using namespace std;
enum Type
{
	OUTPUT, //0
	INPUT //1
};
struct Contact 
{
	int type;
	int x;
	int y;
	int connected_num;

	Contact() noexcept;
		//: type(1), x(0), y(0), connected_num(0) {};//default
	Contact(const int type, int x, int y);
	Contact(const Contact& с) : type(с.type), x(с.x), y(с.y), connected_num(с.connected_num) {}; // copy constructor
	bool operator==(const Contact a) const noexcept;
};
class PCB
{
private:
	int Inputs; // число Входных клемм
	int Outputs; // число Выходных клемм
	Contact trass[SIZE];
public:
	PCB() noexcept; // default constructor
	PCB(const int In,const int Out);

	PCB get_Contacts(Contact *& c) noexcept;
	//PCB& setCont(const Contact* trass, int In, int Out);

	//methods
	int existance(Contact c) const noexcept;
	PCB print() const noexcept;
	PCB create_contact(int type, int X, int Y);
	PCB add_contact(Contact c);
	int check(int index) const noexcept;
	PCB connect(int a, int b);
	PCB highlight(const int choice) noexcept;
	int length(int a, int b);
};