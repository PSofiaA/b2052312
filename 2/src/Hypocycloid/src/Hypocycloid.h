#pragma once
#include <iostream> 
#include <cmath>

namespace geometry{
	class Hypocycloid
	{
	private:
		double r, 
			R;
		double d; 
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
		const char* Hypocycloid_type() const;
		double Radius_of_Curvature(double t) const;
		double Hypocycloid_Area(double t) const;
	};

}