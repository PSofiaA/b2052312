#pragma once
#include "Effect.h"
namespace TowerDefence
{
	class Magic
	{
	protected:
		Effect* effect;
	public:
		void set_effect(Effect* e) { effect = e; };
		virtual void apply_effect(Effect&) = 0;
	};
}