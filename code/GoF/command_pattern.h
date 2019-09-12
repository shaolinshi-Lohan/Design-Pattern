#pragma once
/*����ģʽ
ʵ���������Ҳ���*/
#include <iostream>
#include <memory>
namespace behavioral_pattern
{
	class up_action
	{
	public:
		void do_action()
		{
			std::cout << "up move" << std::endl;
		}

	};
	class down_action
	{
	public:
		void do_action()
		{
			std::cout << "down move" << std::endl;
		}
	};
	class command_pattern
	{
	public:
		virtual void move() = 0;
	};

	class up_command_pattern :public command_pattern
	{
	public:
		virtual void move()
		{
			std::cout << "up_command_pattern" << std::endl;
			upact->do_action();
		}
	private:
		std::unique_ptr<up_action> upact{ new up_action() };
	};

	

	class down_command_pattern :public command_pattern
	{
	public:
		virtual void move()
		{
			std::cout << "down_command_pattern" << std::endl;
			downact->do_action();
		}
	private:
		std::unique_ptr<down_action> downact{ new down_action() };
	};
}


