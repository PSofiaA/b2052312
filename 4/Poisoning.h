#pragma once
class Poisoning : public Effect
{
public:
	Poisoning(EffectType t, int p, int dur, int maxd) : Effect(t, p, dur, maxd) {};
	void invoke(Enemy& target) override;
};