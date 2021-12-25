#pragma once
namespace TowerDefence
{
	struct Position
	{
		int x;
		int y;
	};
	class Object
	{
	private:
		TERRAIN availableTerrain;
		Position position;
	public:
		Object(int x, int y, TERRAIN terrain) : this->position.x = x, this->position.y = y, this->availableTerrain = terrain {};

		TERRAIN get_terrain() { return terrain; }
		Position get_position() { return position; }
		void set_position(int px, int py) { this->position.x = px; this->position.y = py; }
		void set_terrain(TERRAIN T) { this->terrain = T; }
	};
}