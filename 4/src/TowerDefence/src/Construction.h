#pragma once
#include "Object.h"
#include "Enemy.h"
namespace TowerDefence
{
	class Construction: public Object
	{
	private:
		int radius;
		int lvl;
	public:
		Construction(int rad, int pr, int l, TERRAIN t, int x, int y, TYPE type) : Object(x,y,t,type, pr), radius(rad), lvl(l) {};
		int get_radius() { return radius; };
		int get_lvl() { return lvl; };

		void set_radius(int r) { radius = r; };
		void set_lvl(int l) { lvl = l; };

		virtual void attack(Enemy &target) = 0;
		//virtual Tile* choose_target(Level& level) = 0;
		//virtual Enemy& choose_target(Level* level) = 0;
		virtual ~Construction() {};
	};
};
	