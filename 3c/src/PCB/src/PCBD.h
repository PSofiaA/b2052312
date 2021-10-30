#pragma once
#include <iostream>
#include <time.h>
#include <string>
#include <cmath>
using namespace std;
enum Type
{
	OUTPUT, //0
	INPUT //1
};
struct Contact 
{
	Type type;
	int x;
	int y;
	int connected_num;

	friend istream& operator>>(istream& in, Contact& contact);
	Contact() noexcept;
	Contact(Type type, int x, int y);
	bool operator==(const Contact a) const noexcept;
};
class PCB
{
private:
	int Inputs = 0; 
	int Outputs = 0;
	Contact* trass = nullptr;

	bool check(int index) const noexcept;
	bool check(int a, int b) const noexcept;
	const Contact& find(int index) const;
public:
	PCB() noexcept; // default constructor
	PCB(Type type, int x, int y);
	PCB(const int In,const int Out);
	PCB(const PCB&);
	PCB(PCB&&)noexcept;

	void changeSize();
	PCB get_Contacts(Contact *&) noexcept; //! пересмотреть (как сказал кот он лишний тк есть финд)
	int get_Inputs() const noexcept;
	int get_Outputs() const noexcept;
	int get_Size() const noexcept;
	//перегрузить + его во френдзону 
	PCB& operator =(PCB&);
	PCB& operator=(PCB&&) noexcept;
	friend ostream& operator<<(ostream& out, const PCB&);
	PCB& operator+=(Contact&);
	const Contact& operator[](int index) const;
	friend void operator+(PCB& pcb1, PCB& pcb2);
	PCB& PCB::operator--();
	PCB PCB::operator--(int);

	bool existance(const Contact& c) const noexcept; //по ссылке тк она меньше в памяти
	PCB& add_contact(Type type, int X, int Y); //create -> add
	PCB& add_contact(Contact& c); 
	PCB& connect(int a, int b);
	void highlight(const int choice, Contact*& result) const noexcept;
	int length(int a, int b) const;
};