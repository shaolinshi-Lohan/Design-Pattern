#pragma once
/*����ģʽ*/
#include <iostream>
#include <memory>
namespace behavioral_pattern
{
	class strategy_pattern
	{
	public:
		virtual void algorithm() = 0;
	};

	class concrete_strategy_pattern_A :public strategy_pattern
	{
	public:
		virtual void algorithm() override
		{
			std::cout << "���Է���A" << std::endl;
		}
	};
	class concrete_strategy_pattern_B :public strategy_pattern
	{
	public:
		virtual void algorithm() override
		{
			std::cout << "���Է���B" << std::endl;
		}
	};
}

