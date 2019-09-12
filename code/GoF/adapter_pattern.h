#pragma once
/*
案例 实现110v转220v
*/
#include <iostream>
#include <memory>
namespace structural_pattern
{
	class target220v
	{
	public:
		virtual void charging_stand() = 0;
	};

	class target220v_china : public target220v
	{
	public:
		virtual void charging_stand() override
		{
			std::cout << "适配中国220v电压电器" << std::endl;
		}
	};

	class adapter110v
	{
	public:
		virtual void charging() = 0;
	};


	class adapter_pattern :  public adapter110v
	{
	public:
		virtual void charging() override
		{
			std::cout << "提供美国电压110v" << std::endl;
			std::unique_ptr<target220v> temp{ new target220v_china };
			to220v = std::move(temp);
			to220v->charging_stand();
		}

	private:
		std::unique_ptr<target220v> to220v;
	};
}


