#pragma once
#include "Vector3.h"
using namespace Prog3;
template <typename Type>
int get(Type& x, const char* message)
{
	while (true)
	{
		std::cout << message << std::endl;
		std::cin >> x;
		if (std::cin.eof() || std::cin.bad())
			return -1;
		else if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Input error. Try again\n";
		}
		else
			return 0;
	}
}
typedef int (*function_ptr)(Vector3&);
int main_menu();
int add_element(Vector3& v);
int print(Vector3& v);
int ascending(Vector3& v);
int descending(Vector3& v);
int sum_between(Vector3& v);
void sort_a(double*& m, int n);
// сумму элементов массива, расположенных между первым и вторым положительными элементами

