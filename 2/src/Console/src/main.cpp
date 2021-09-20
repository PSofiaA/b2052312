#include <iostream>
#include "inputs.h"
using namespace geometry;
int main()
{
	std::cout << "\tH Y P O C Y C L O I D" << std::endl;
	std::cout << "To start things off, please, read theoretical material (doc file named relevant information)" << std::endl;
	double r, R, d;
	Hypocycloid* hypocycloid = nullptr;
	do {

		if (get(r, 0, "\nInput generating circle radius:") < 0)
			return 1;
		else if (get(R, 0, "\nInput director circle radius:") < 0)
			return 1;
		else if (get(d, 0, "\nInput pen length:") < 0)
			return 1;
		try {
			hypocycloid = new Hypocycloid(r, R, d);
		}
		catch (std::invalid_argument&error) {
			std::cout << error.what() << std::endl;
		}
	} while (!hypocycloid);
	Display(*hypocycloid);
	int choice = -1;
	double x, y;
	do
	{
		if (get(choice, -1, "\n\t0.Exit\n\t1.Change Generating circle radius\n\t2.Change Director circle radius\n"
			"\t3.Change Pen length\n\t4.Get point coordinates\n\t5.Calculate curvature radius by angle"
			"\n\t6.Calculate Hypocycloid area by angle\n\t7.Hypocycloid type\n") < 0)
		{
			delete hypocycloid;
			return 1;
		}
		switch (choice)
		{
		case 1:
			if (Change_Generating_Circle_Radius(*hypocycloid) < 0)
			{
				delete hypocycloid;
				return 1;
			}
			Display(*hypocycloid);
			break;
		case 2:
			if(Change_Director_Circle_Radius(*hypocycloid)<0)
			{
				delete hypocycloid;
				return 1;
			}
			Display(*hypocycloid);
			break;
		case 3:			
			if (Change_Pen_Length(*hypocycloid) < 0)
			{
				delete hypocycloid;
				return 1;
			}
			Display(*hypocycloid);
			break;
		case 4:
			if (point(*hypocycloid, x, y) < 0)
			{
				delete hypocycloid;
				return 1;
			}
			break;
		case 5:
			if (curvRad(*hypocycloid) < 0)
			{
				delete hypocycloid;
				return 1;
			}
			break;
		case 6:
			if (area(*hypocycloid) < 0)
			{
				delete hypocycloid;
				return 1;
			}
			break;
		case 7:
			type(*hypocycloid);
			break;
		}
	} while (choice != 0);
	delete hypocycloid;
	return 0;
}