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
				std::cout << "10块以下找老爸要" << std::endl;
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
				std::cout << "10块到1000块找老妈要" << std::endl;
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
			std::cout << "职责链最终结点。银行大大的有钱快来抢吧" << std::endl;
		}
	};
}