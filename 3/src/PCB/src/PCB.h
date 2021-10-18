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

	friend istream& operator>>(istream& in, Contact& contact);
	Contact() noexcept;
	Contact(const int type, int x, int y);
	Contact(const Contact& ñ) : type(ñ.type), x(ñ.x), y(ñ.y), connected_num(ñ.connected_num) {}; // copy constructor
	bool operator==(const Contact a) const noexcept;
	Contact& operator=(Contact c);
};
class PCB
{
private:
	int Inputs = 0; 
	int Outputs = 0;
	Contact trass[SIZE];

	bool check(int index) const noexcept;
	bool check(int a, int b) const noexcept;
	Contact find(int index) const;
public:
	PCB() noexcept; // default constructor
	PCB(int type, int x, int y);
	PCB(const int In,const int Out);

	PCB get_Contacts(Contact *& c) noexcept;
	int get_Inputs() const noexcept;
	int get_Outputs() const noexcept;
	int get_Size() const noexcept;

	friend ostream& operator<<(ostream& out, const  PCB& pcb);
	PCB operator+=(Contact c);
	Contact& operator[](int index);
	//PCB operator--();
	//PCB operator--(int);

	//PCB& deleteContact(int index);
	bool existance(Contact c) const noexcept;
	PCB add_contact(int type, int X, int Y); //create -> add
	PCB add_contact(Contact c);
	PCB connect(int a, int b);
	PCB highlight(const int choice, Contact*& result) const noexcept;
	int length(int a, int b) const;
};