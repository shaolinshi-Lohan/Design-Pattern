#pragma once

#include<memory>
#include<iostream>
namespace behavioral_pattern
{
	class chain_responsibility
	{
	public:
		virtual void request(int money) = 0;
		void set_chain_responsibility(std::weak_ptr<chain_responsibility> c)
		{
			chain = c;
		}
	protected:
		std::weak_ptr<chain_responsibility> chain;
	};
	class father_chain_responsibility : public chain_responsibility
	{
	public:
		void request(int money)
		{
#define MAX_MONEY 10
			if (MAX_MONEY > money)
			{
				std::cout << "10���������ϰ�Ҫ" << std::endl;
			}
			else
			{
				chain.lock().get()->request(money);
			}
		}
	};
	class mother_chain_responsibility : public chain_responsibility
	{
	public:
		void request(int money)
		{
#define MOM_MAX_MONEY 1000
			if (MOM_MAX_MONEY > money)
			{
				std::cout << "10�鵽1000��������Ҫ" << std::endl;
			}
			else
			{
				chain.lock().get()->request(money);
			}
		}
	};
	class bank_chain_responsibility : public chain_responsibility
	{
	public:
		void request(int money)
		{
			std::cout << "ְ�������ս�㡣���д�����Ǯ��������" << std::endl;
		}
	};
}