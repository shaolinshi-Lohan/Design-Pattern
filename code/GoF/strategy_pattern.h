#pragma once
/*策略模式*/
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
			std::cout << "策略方案A" << std::endl;
		}
	};
	class concrete_strategy_pattern_B :public strategy_pattern
	{
	public:
		virtual void algorithm() override
		{
			std::cout << "策略方案B" << std::endl;
		}
	};
}

