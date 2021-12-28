#include "Tile.h"
#include <stdexcept>
namespace TowerDefence
{
	bool Tile::check_object(Object* object)
	{
		if (object->get_terrain() == this->type)
			return true;
		else
			return false;
	}
	Tile::~Tile()
	{
		delete this->object;
	}
	void Tile::set_object(Object* toset)
	{
		if (check_object(toset) && (this->object == nullptr))
		{
			this->object = toset;
		}
		if (!check_object(toset))
			throw std::runtime_error("Incorrect terrain type!");
	}
	void Tile::remove_object()
	{
		if (this->object)
		{
			this->object = nullptr;
		}
	}
}