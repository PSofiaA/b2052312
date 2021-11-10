#include "Dialog.h"
#include <iostream>
using namespace Prog3;
using std::cin;
using std::cout;
using std::endl;
using std::move;
const char* dialog[]
{
	"0. Exit"
	"\n1. Add new element",
	"2. Print your vector",
	"3. Ascending",
	"4. Descending",
	"5. Get sum between two first positive elements"
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
int add_element(Vector3& v)
{
	double element;
	get(element, "Enter number: ");
	try
	{
			v.addElement(element);
	}
	catch (int)
	{
		cout << "Vector overflow" << endl;
	}
	return 0;
}
int print(Vector3& v)
{
	cout <<"Vector ->" << v;
	return 0;
}

int ascending(Vector3& v)
{
	int size = v.getCurSize();
	double buf;
	
	if (size != 0)
	{
		double* numbers = new double[size];
		for (int i = 0; i < size; i++)
			numbers[i] = v.getNum(i);
		for (int i = 0; i < size - 1; i++) //bubblesort
		{
			for (int j = 0; j < size - i - 1; j++)
				if (numbers[j] > numbers[j + 1])
				{
					buf = numbers[j];
					numbers[j] = numbers[j + 1];
					numbers[j + 1] = buf;
				}
		}
		Vector3 v2(size, numbers);
		v = move(v2);
		cout << "Vector ->" << v;
		delete[] numbers;
	}
	return 0;
}
int descending(Vector3& v)
{
	int size = v.getCurSize();
	double buf;
	if (size != 0)
	{
		double* numbers = new double[size];
		for (int i = 0; i < size; i++)
			numbers[i] = v.getNum(i);
		for (int i = 0; i < size - 1; i++) //bubblesort
		{
			for (int j = 0; j < size - i - 1; j++)
				if (numbers[j] < numbers[j + 1])
				{
					buf = numbers[j];
					numbers[j] = numbers[j + 1];
					numbers[j + 1] = buf;
				}
		}
		Vector3 v2(size, numbers);
		v = move(v2);
		cout << "Vector ->" << v;
		delete[] numbers;
	}
	return 0;
}
int sum_between(Vector3& v)
{
	int size = v.getCurSize();
	double res = 0;
	int counter = 0;
	if (size != 0)
	{
		int k = 0;
		double* numbers = new double[size];
		for (int i = 0; i < size; i++)
			numbers[i] = v.getNum(i);
		for (int i = 0; i < size; i++)
		{
			if (numbers[i] > 0)
				counter++;
			if (counter == 2)
				break;
			if (numbers[i] < 0 && counter == 1)
				res += numbers[i];
		}
		cout << "Res ->" << res;
		delete[] numbers;
	}
	return 0;
}
// сумму элементов массива, расположенных между первым и вторым положительными элементами