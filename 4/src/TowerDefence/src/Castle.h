#pragma once
#include "StatefulObject.h"
#include <string>
using std::string;

namespace TowerDefence
{
	class Castle : public StatefulObject
	{
	public:
		Castle(TERRAIN T, int X, int Y) :StatefulObject(1, 20, 20, 25, Alive,T,X,Y, CASTLE) {};
	};
}