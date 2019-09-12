#pragma once
#include <iostream>
namespace structural_pattern
{
	class A_sub_system
	{
	public:
		void do_a() { std::cout << "A子系统-A方法" << std::endl; }
	};
	class B_sub_system
	{
	public:
		void do_b() { std::cout << "B子系统-B方法" << std::endl; }
	};
	class C_sub_system
	{
	public:
		void do_c() { std::cout << "C子系统-C方法" << std::endl; }
	};
	class facade_pattern
	{
	public:
		void do_action()
		{
			A_sub_system asub;
			B_sub_system bsub;
			C_sub_system csub;

			asub.do_a();
			bsub.do_b();
			csub.do_c();
		}
	};
}

