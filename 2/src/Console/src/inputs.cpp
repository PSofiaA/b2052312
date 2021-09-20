#include "inputs.h"
using namespace std;
int Change_Generating_Circle_Radius(geometry::Hypocycloid& Hypocycloid)//порождающая окружность
{
	double r;
	if (get(r, 0, "Input new generating circle radius") < 0)
		return -1;
	try { Hypocycloid.setr(r); }
	catch (std::invalid_argument& error)
	{
		std::cout << "Attempt failed" << std::endl;
		std::cout << error.what() << std::endl;
	}
	return 0;
}
int Change_Director_Circle_Radius(geometry::Hypocycloid& Hypocycloid) //направляющая окружность 
{
	double R;
	if (get(R, 0, "Input new director circle radius") < 0)
			return -1;
	try { Hypocycloid.setR(R); }
	catch (std::invalid_argument& error)
	{
		std::cout << "Attempt failed" << std::endl;
		std::cout << error.what() << std::endl;
	}
	return 0;
}
int Change_Pen_Length(geometry::Hypocycloid& Hypocycloid) //изменение d
{
	double d;
	if (get(d, 0, "Input new pen length") < 0)
		return -1;
	try { Hypocycloid.setd(d); }
	catch (std::invalid_argument& error)
	{
		std::cout << "Attempt failed" << std::endl;
		std::cout << error.what() << std::endl;
	}
	return 0;
}
int Input_Angle(double& t) //ввод угла
{
	if (get(t, 0, "Input angle") < 0) //лимит для удобсвта
		return -1;
	return 0;
}
int curvRad(geometry::Hypocycloid& Hypocycloid)
{
	double t, rad; 
	if (Input_Angle(t) < 0) return -1;
	rad = Hypocycloid.Radius_of_Curvature(t);
	std::cout << "Radius of Curvature is " << rad << std::endl;
	return 0;
}
int area(geometry::Hypocycloid& Hypocycloid)
{
	double t, area;
	if (Input_Angle(t) < 0) return -1;
	area = Hypocycloid.Hypocycloid_Area(t);
	std::cout << "Hypocycloid area is " << area << std::endl;
	return 0;
}
 void Display(geometry::Hypocycloid& Hypocycloid)
{
	cout << "\nGenerating circle radius: " << Hypocycloid.getr() << endl;
	cout << "Director circle radius: " << Hypocycloid.getR() << endl;
	cout << "Pen length: " << Hypocycloid.getd() << endl;
}
int point(geometry::Hypocycloid& Hypocycloid, double& x, double& y)
{
	double t;
	if (Input_Angle(t) < 0) return -1;
	Hypocycloid.getPoint(t, x, y);
	cout << "x coordinate: " << x << endl;
	cout << "y coordinate: " << y << endl;
	return 0;
}
int inputr(double& r, double& R)
{
	if (get(r, 0, "Input generating circle radius:") < 0)
		return -1;
	else if (get(R, 0, "Input director circle radius:") < 0)
		return -1;

	return 0;
}
int inputd(double& d)
{
	const char* message = "";
	do
	{
		std::cout << message;
		if (get(d, 0, "Input pen length:") < 0)
			return -1;
		message = "Pen length cannot be 1!";
	} while (d == 1);
	return 0;
}
void type(geometry::Hypocycloid& Hypocycloid)
{
	const char* message = Hypocycloid.Hypocycloid_type();
	std::cout << message << endl;
}