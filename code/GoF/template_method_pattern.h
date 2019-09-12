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
		void step1() { std::cout << "���Ǿ��巽��" << std::endl; }
		virtual bool ishook() = 0;
		virtual void step2() = 0;
		virtual void step3() = 0;
	};

	class concrete_template : public template_method_pattern
	{
		virtual bool ishook() override
		{
			std::cout << "���ǹ��ӷ���" << std::endl;
			return true;
		}
		virtual void step2() override
		{
			std::cout << "���ǳ��󷽷�step2����,��֤���ӷ���" << std::endl;
		}
		virtual void step3() override
		{
			std::cout << "���ǳ��󷽷�step3����" << std::endl;
		}
	};
}