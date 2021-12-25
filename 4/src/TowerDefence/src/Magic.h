#pragma once
#include "Effect.h"
namespace TowerDefence
{
	class Magic
	{
	protected:
		Effect* effect;
	public:
		Effect* get_effect() { return effect; };
		void set_effect(Effect* e) { effect = e; };
		virtual void apply_effect(Effect&) = 0;
	};
}