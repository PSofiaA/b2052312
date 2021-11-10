#pragma once
#include "Enemy.h"
#include "Effect.h"
namespace TowerDefence
{
	class Construction
	{
	private:
		int radius;
		int price;
		int lvl;
		Effect* effect;
		TERRAIN type;
	public:
		int get_radius() { return radius; };
		int get_price() { return price; };
		int get_lvl() { return lvl; };

		void set_radius(int r) { radius = r; };
		void set_price(int p) { price = p; };
		void set_lvl(int l) { lvl = l; };

		virtual void attack(Enemy &target) =0;
	};
};
	