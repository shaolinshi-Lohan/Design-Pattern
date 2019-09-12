#pragma once

#include<iostream>
#include<memory>
namespace behavioral_pattern
{
	class state_pattern
	{
	public:
		virtual void solid() { std::cout << "���岻֧��" << std::endl; }
		virtual void liquid() { std::cout << "Һ�岻֧��" << std::endl; }
		virtual void gas() { std::cout << "���岻֧��" << std::endl; }
	};

	class solid_state_pattern : public state_pattern
	{
	public:
		void solid()
		{
			std::cout << "����-- ���" << std::endl;
		}
	};
	class liquid_state_pattern : public state_pattern
	{
	public:
		void liquid()
		{
			std::cout << "Һ��-- ����" << std::endl;
		}
	};
	class gas_state_pattern : public state_pattern
	{
	public:
		void gas()
		{
			std::cout << "����-- ����" << std::endl;
		}
	};

	class context
	{
	public:
		void set_status(std::shared_ptr<state_pattern> s) { this->status = s; }
		void change(int temp)
		{
			if (0 > temp)
				status->solid();
			else if (100 < temp)
				status->gas();
			else
				status->liquid();
		}
	private:
		std::shared_ptr<state_pattern> status;
	};
}


