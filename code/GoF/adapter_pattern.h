#pragma once
/*
���� ʵ��110vת220v
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
			std::cout << "�����й�220v��ѹ����" << std::endl;
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
			std::cout << "�ṩ������ѹ110v" << std::endl;
			std::unique_ptr<target220v> temp{ new target220v_china };
			to220v = std::move(temp);
			to220v->charging_stand();
		}

	private:
		std::unique_ptr<target220v> to220v;
	};
}


