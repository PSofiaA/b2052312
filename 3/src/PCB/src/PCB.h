#pragma once
#include <iostream>
#include<time.h>
#include <string>
#include <cmath>
#define SIZE 20
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
	Contact(const int type, int x, int y);
	Contact(const Contact& ñ) : type(ñ.type), x(ñ.x), y(ñ.y), connected_num(ñ.connected_num) {}; // copy constructor
	bool operator==(const Contact a) const noexcept;
};
class PCB
{
private:
	int Inputs = 0;
	int Outputs = 0; 
	Contact trass[SIZE];
public:
	PCB() noexcept; // default constructor
	PCB(const int In,const int Out);

	PCB get_Contacts(Contact *& c) noexcept;
	int get_Inputs() noexcept;
	int get_Outputs() noexcept;

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