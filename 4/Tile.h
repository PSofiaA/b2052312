#include "Castle.h"
namespace TowerDefence
{
	enum TERRAIN {
		ROAD, FIELD, FOREST
	};
	class Tile
	{
	private:
		TERRAIN type;
		int size;
		int coordinate;//???????????
	public:
		int get_size() { return size; };
		int get_coordinate() { return coordinate; };
		TERRAIN get_terrain() { return type; };

		void set_terrain(TERRAIN t) {type = t;};
		void set_coordinate(int c) { coordinate = c; };
		void set_size(int s) { size = s; };
		
		Tile(TERRAIN type, int size);
	};
}