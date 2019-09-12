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
			std::cout << "��ʵϵͳ����Ӧ��" << std::endl;
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
			std::cout << "������ǰ����Ϊ" << std::endl;
		}
	};
}