#pragma once
namespace TowerDefence
{
	enum TERRAIN {
		ROAD, FIELD, FOREST, NOTSTATED
	};
	enum TYPE {
		TOWER, MAGICTOWER,TRAP, ENEMY, CASTLE
	};
	class Object
	{
	private:
		TYPE objectType;
		TERRAIN availableTerrain;
		int x;
		int y;
		int gold;
	public:
		Object(int px, int py, TERRAIN terrain, TYPE type, int money) : x(px), y(py), availableTerrain(terrain), objectType(type), gold(money) {};

		int get_gold() { return gold; }
		TERRAIN get_terrain() { return availableTerrain; }
		TYPE get_type() { return objectType; }
		int get_x() { return x; }
		int get_y() { return y; }

		void set_gold(int g) { this->gold = g; }
		void set_position(int px, int py) { this->x = px; this->y = py; }
		void set_terrain(TERRAIN T) { this->availableTerrain = T; }

		//virtual int get_info() = 0;
	};
}