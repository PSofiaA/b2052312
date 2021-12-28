#pragma once
#include "Object.h"
namespace TowerDefence
{
	class Tile
	{
	private:
		Object* object;
		TERRAIN type;
	public:
		~Tile();
		Tile(TERRAIN t) : object(nullptr), type(t) {};
		Tile(Object* ob, TERRAIN t) : object(ob), type(t) {};
		TERRAIN get_terrain() { return type; };
		Object* get_object() { return object; };

		void set_terrain(TERRAIN t) {type = t;};
		void set_object(Object*);
		
		void remove_object();
		bool check_object(Object*);
	
	};
}