#pragma once
#include <iostream> 
#include <Hypocycloid.h>
template <typename Type>
int get(Type& x, int min, const char* message)
{
	while (true)
	{
		std::cout << message<<std::endl;
		std::cin >> x;
		if (std::cin.eof() || std::cin.bad())
			return -1;
		else if (std::cin.fail() || x <= min)
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Input error. Try again\n";
		}
		else
			return 0;
	}
}
void Display(geometry::Hypocycloid& Hypocycloid);
int Change_Generating_Circle_Radius(geometry::Hypocycloid& Hypocycloid);//порождающая окружность
int Change_Director_Circle_Radius(geometry::Hypocycloid& Hypocycloid); //направляющая окружность 
int Change_Pen_Length(geometry::Hypocycloid& Hypocycloid); //изменение d
int Input_Angle(double& t); //ввод угла
int area(geometry::Hypocycloid& Hypocycloid);
int curvRad(geometry::Hypocycloid& Hypocycloid);
int point(geometry::Hypocycloid& Hypocycloid, double& x, double& y);

int inputr(double& r, double& R);
int inputd(double& d);
void type(geometry::Hypocycloid& Hypocycloid);