#include "Hypocycloid.h"

namespace geometry {
	const char* error[]{
		"Incorrect generating circle radius (less than 0)!",
		"Incorrect director circle radius (less than 0)!",
		"Error: generating circle radius > director circle radius",
		"Incorrect pen length (less than 1)!"
	};

	Hypocycloid::Hypocycloid(double sr, double sR, double sd) {
		if (sr <= 0) throw std::invalid_argument(error[0]);
		if (sR <= 0) throw std::invalid_argument(error[1]);
		if (sr >= sR) throw std::invalid_argument(error[2]);
		if (sd <= 1) throw std::invalid_argument(error[3]);
		this->r = sr; this->R = sR; this->d = sd;
	}

	void Hypocycloid::setr(double sr)
	{	
		if (sr <= 0) throw std::invalid_argument(error[0]);
		if (sr >= R) throw std::invalid_argument(error[2]);
		r = sr;
	}
	void Hypocycloid::setR(double sR) 
	{
		if (sR <= 0) throw std::invalid_argument(error[1]);
		if (sR <= r) throw std::invalid_argument(error[2]);
		R = sR;
	}
	void Hypocycloid::setd(double sd)
	{
		if (sd <= 1) throw std::invalid_argument(error[3]);
		d = sd;
	}
	const char* Hypocycloid::Hypocycloid_type()
	{
		const char* message = "";
		if (d > r)
			message = "Elongated Hypocycloid";
		else if (d < r)
			message = "Shortened Hypocycloid";
		else message = "Normal Hypocycloid";
		return message;
	}
	void  Hypocycloid::getPoint(double t, double& x, double& y) //t - угол поворота луча,
		//соединяющего центр порождающего круга с центром направляющей окружности.
	{
		x = (R - r) * cos(t) + d * cos((R - r) * t / r);
		y = (R - r) *  sin(t) - d * sin((R - r) * t / r);
	}
	double Hypocycloid::Radius_of_Curvature(double t)
	{
		double numerator = (R - r) * pow( r*r + d*d - 2 * d * r * cos(R * t / r), 1.5);
		double denominator = abs(pow(d, 2)*(R - r) - pow(r, 3) - (R - 2*r) * d * r * cos(R * t / r));
		if (denominator == 0)
			return -1;
		double res = numerator / denominator;
		return res;
	}
	double Hypocycloid::Hypocycloid_Area(double t)
	{
		double term1 = (R - r - pow(d, 2) / r) * t;
		double term2 = (d * (R - 2 * r) / R) * sin(R * t / r);
		double area = abs(((R - r) / 2) * (term1 - term2));
		return area;
	}
}