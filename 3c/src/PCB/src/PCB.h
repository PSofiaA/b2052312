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
	Type type;//дура там не инт
	int x;
	int y;
	int connected_num;

	friend istream& operator>>(istream& in, Contact& contact);
	Contact() noexcept;
	Contact(const int type, int x, int y);
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
	PCB(int type, int x, int y);
	PCB(const int In,const int Out);
	PCB(const PCB&);
	PCB(PCB&&); 

	void changeSize();
	PCB get_Contacts(Contact *&) noexcept; //! пересмотреть (как сказал кот он лишний тк есть финд)
	int get_Inputs() const noexcept;
	int get_Outputs() const noexcept;
	int get_Size() const noexcept;
	//перегрузить + его во френдзону 
	PCB& operator =(PCB&);
	PCB& operator=(PCB&&);
	friend ostream& operator<<(ostream& out, const PCB&);
	PCB& operator+=(Contact&);
	const Contact& operator[](int index) const;
	//PCB operator--();
	//PCB operator--(int);

	//PCB& deleteContact(int index);
	bool existance(const Contact& c) const noexcept; //по ссылке тк она меньше в памяти
	PCB& add_contact(int type, int X, int Y); //create -> add
	PCB& add_contact(Contact& c); 
	PCB& connect(int a, int b);
	PCB& highlight(const int choice, Contact*& result) const noexcept;
	int length(int a, int b) const;
};