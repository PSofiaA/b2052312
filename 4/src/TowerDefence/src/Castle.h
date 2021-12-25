#pragma once
#include <string>
using std::string;

namespace TowerDefence
{
	class Castle : public StatefulObject
	{

	public:
		Castle(int id, int hp, int mhp, int g, ObjectState state) :
			StatefulObject(id, hp, mhp, g, state) {};
	};
}