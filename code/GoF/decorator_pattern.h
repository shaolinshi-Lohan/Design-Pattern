#pragma once
#include <memory>
#include <iostream>
namespace structural_pattern
{
	class decorator_pattern
	{
	public:
		virtual void operation() = 0;
	};
	class concrete_component : public decorator_pattern
	{
	public :
		void operation() override
		{
			std::cout << "���幹������󷽷�" << std::endl;
		}
	};
	class decorator : public decorator_pattern
	{
	public :
		
	protected:
		std::shared_ptr<decorator_pattern> comp;
	};

	class concrete_decorator : public decorator
	{
	public:
		void pre_operation()
		{
			std::cout << "ǰ��װ��" << std::endl;
		}
		void suff_operation()
		{
			std::cout << "��׺װ��" << std::endl;
		}
		void operation() override
		{
			std::shared_ptr<decorator_pattern> temp{ new concrete_component() };
			comp = temp;
			this->pre_operation();
			comp.get()->operation();
			this->suff_operation();
		}
	};
}