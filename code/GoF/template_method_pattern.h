#pragma once

#include<iostream>
namespace behavioral_pattern
{
	class template_method_pattern
	{
	public:
		void master()
		{
			step1();
			if (ishook())
			{
				step2();
			}
			step3();
		}
		void step1() { std::cout << "这是具体方法" << std::endl; }
		virtual bool ishook() = 0;
		virtual void step2() = 0;
		virtual void step3() = 0;
	};

	class concrete_template : public template_method_pattern
	{
		virtual bool ishook() override
		{
			std::cout << "这是钩子方法" << std::endl;
			return true;
		}
		virtual void step2() override
		{
			std::cout << "这是抽象方法step2方法,验证钩子方法" << std::endl;
		}
		virtual void step3() override
		{
			std::cout << "这是抽象方法step3方法" << std::endl;
		}
	};
}