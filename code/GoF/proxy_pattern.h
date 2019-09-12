#pragma once
#include <iostream>
namespace structural_pattern
{
	class proxy_pattern
	{
	public:
		virtual void request() = 0;
	};

	class real_system : public proxy_pattern
	{
	public:
		virtual void request() override
		{
			std::cout << "真实系统请求应答" << std::endl;
		}
	};
	class proxy : public  proxy_pattern
	{
	public:
		virtual void request() override
		{
			real_system real;
			do_anything();
			real.request();
		}
	private:
		void do_anything()
		{
			std::cout << "代理者前置行为" << std::endl;
		}
	};
}