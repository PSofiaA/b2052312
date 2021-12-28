#pragma once
#include  <stdexcept>
#include "Enemy.h"
/*!
* @file
*/
namespace TowerDefence
{
	/*!
	* @enum ��������� ���� �������� \n
	* weakening - ����������, �������� ������������ ����������� �� ������� �������� ������� \n
	* poisoning - ����������, ���� ������ ���������� �������� ������ �������� ������� \n
	* deceleration - ����������, ����, ��������� ����� ����������� �� ������� �������� ������� \n
	*/
	enum EffectType
	{
		weakening,
		poisoning,
		deceleration
	};
	/*!
	* ����� �������, ���������� �����, ������������ ������ Magic
	*/
	class Effect
	{
	protected:
		/*! 
		*��� ������� (����������, ���������� ��� ����������)
		*/
		EffectType type;
		/* �������� �������
		*/
		int power;
		/*!
		*���������� ����� �������� �������
		*/
		int duration;
		/*! 
		* ����� �������� �������
		*/
		int max_duration;
	public:
		/*!
		* �����������
		*  @param t - ��� ������� \n
		*  @param p - �������� �������\n
		*  @param dur - ���������� ����� �������� �������\n
		*  @param maxd - ����� �������� �������\n
		*/
		Effect(EffectType t, int p, int dur, int maxd) : type(t), power(p), duration(dur), max_duration(maxd) {};
		~Effect() {};

		/*! 
		* ���������� ��� �������
		* @return ������� �������������� ���� �������
		*/
		EffectType get_type() const noexcept { return type; };
		/*!
		* ���������� �������� �������
		*  @return int, �������� �������
		*/
		int get_power() const noexcept { return power; };
		/*! 
		* ���������� ���������� ����� �������� �������
		* @return int, ���������� ����� �������� �������
		*/
		int get_duration() const noexcept { return duration; };
		/*! 
		* ���������� ����� �������� �������
		* @return int, ����� �������� �������
		*/
		int get_max_duration() const noexcept { return max_duration;  };

		/*!
		* ������������� ��� �������
		*/
		void set_type(EffectType t) { type = t; };
		/*! 
		* ������������� �������� �������
		* @throw std::invalid_argument ���� ��������������� ������� ���� ������������� ��������
		*/
		void set_power(int p)
		{ if (p <= 0) throw std::invalid_argument("Incorrect power!"); power = p; };
		/*! 
		* ������������� ���������� ����� �������� �������
		* @throw std::invalid_argument ���� ��������������� ������� ���� ������������� ��������
		*/
		void set_duration(int d)
		{ if (d > max_duration || d<0) throw std::invalid_argument("Incorrect duration"); duration = d; };
		/*!
		* ������������� ����� �������� �������
		* @throw std::invalid_argument ���� ��������������� ������� ���� ������������� ��������
		*/
		void set_max_duration(int md)
		{
			if (md <= 0) throw std::invalid_argument("Incorrect max duration!"); max_duration = md;
		};

		/*!
		* �������� ������� (����������� � ����������� �� ���� �������)
		* @param - ����, �� �������� ������������� ������
		* deceleration - ��������� �������� �������� �������� �����
		* poisoning - ��������� �������� HP ����� �� �������� �������
		* weakening - ��������������� �������� scale_damage �����, �������� �� �������� �����, ���������� �����
		*/
		virtual void invoke(Enemy& target) = 0;
	};
	
}