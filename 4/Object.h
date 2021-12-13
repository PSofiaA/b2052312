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
		Position position;
	public:
		Position get_position() { return position; }
		void set_position(int px, int py) { this->position.x = px; this->position.y = py; }
	};
}