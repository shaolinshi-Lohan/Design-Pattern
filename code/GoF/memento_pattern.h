#pragma once
#include <stack>
#include <string>
#include <iostream>
namespace behavioral_pattern
{
	class status
	{
	public:
		void set(std::string str) { this->status_info = str; }
		std::string get() { return this->status_info; }
	private:
		std::string status_info;
	};
	class memento_pattern
	{
	public:
		void push(status st)
		{
			stack_status.push(st);
		}
		status pop()
		{
			status temp;
			if (!stack_status.empty())
			{
				temp = stack_status.top();
				stack_status.pop();
			}
			return temp;
		}
	private:
		std::stack<status> stack_status;
	};
	class rpg
	{
	public:
		void set(std::string str) { this->status_info = str; }
		std::string get() { return this->status_info; }
		status save()
		{
			status st;
			st.set(this->status_info);
			return st;
		}
		void restore(status& st)
		{
			this->status_info = st.get();
		}
	private:
		std::string status_info;
	};
}


