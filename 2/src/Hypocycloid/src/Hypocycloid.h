#pragma once
#include <iostream> 
#include <cmath>
#define _USE_MATH_DEFINES

namespace geometry{
	class Hypocycloid
	{
	private:
		double r, //радиус производящей окрти - меньш(та что движется) 
			R; //радиус направляющей окружности
		double d; //расстояние от описывающей точки до центра производящей окружности
	public://constructors
		Hypocycloid(double r, double R, double d );
		//setters
		void setR(double R);
		void setr(double r);
		void setd(double d);
		//getters
		double getr() const { return r; };
		double getR() const { return R; };
		double getd() const { return d; };

		void getPoint(double t, double& x, double& y);
		const char* Hypocycloid_type();
		double Radius_of_Curvature(double t);
		double Hypocycloid_Area(double t);
	};

}