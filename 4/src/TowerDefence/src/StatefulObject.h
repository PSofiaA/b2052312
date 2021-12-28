#pragma once
#include "Object.h"
namespace TowerDefence
{
	enum ObjectState
	{
		Dead,
		Alive
	};
	class StatefulObject: public Object
	{
	protected:
		int ID;
		int HP;
		int max_HP;
		ObjectState state;

	public:
		StatefulObject(int id, int hp, int mhp, int g, ObjectState s, TERRAIN T, int X, int Y, TYPE type) :
			Object(X,Y,T,type,g), ID(id), HP(hp), max_HP(mhp), state(s) {};
		virtual ~StatefulObject() = default;
		ObjectState get_state() const { return state; }
		int get_HP() const { return HP; }
		int get_max_HP() const { return max_HP; }
		//int get_gold()const { return gold; }

		void set_state(ObjectState s) { state = s; }
		void set_HP(int hp) { HP = hp; }
		void set_max_HP(int mh) { max_HP = mh; }
		//void set_gold(int g) { gold = g; }
		
		void update_state()
		{
			(HP <= 0) ? state = Dead : state = Alive;
		}
		virtual void take_damage(int damage)
		{
			if (state != Dead)
			{
				HP -= damage;
				update_state();
			}
		
		}
	};
}
