#pragma once
#include "Effect.h"
namespace TowerDefence
{
	class Magic
	{
	private:
		Effect* effect;
	public:
		void set_effect(Effect* e) { effect = e; };
		virtual void apply_effect(Effect& ef) = 0;
	};
}