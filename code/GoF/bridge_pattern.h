#pragma once
#include <iostream>
#include <string>
#include <memory>
namespace structural_pattern
{
	class formate
	{
	public:
		virtual void convert(std::string data) = 0;
	};

	class txt_formate : public formate
	{
	public:
		virtual void convert(std::string data) override
		{
			std::cout << data.c_str() << " ת��TXT��ʽ���" << std::endl;
		}
	};
	class pdf_formate : public formate
	{
	public:
		virtual void convert(std::string data) override
		{
			std::cout << data.c_str() << " ת��PDF��ʽ���" << std::endl;
		}
	};

	class bridge_pattern
	{
	public:
		void set_formate(std::shared_ptr<formate> f)
		{
			fmt = f;
		}
		virtual void do_convert() = 0;
	protected:
		std::shared_ptr<formate> fmt;
	};

	class db_bridge_pattern : public bridge_pattern
	{
	public:
		virtual void do_convert() override
		{
			std::string data = "DB ���ݿ�����--";
			fmt.get()->convert(data);
		}
	};
	class mysql_bridge_pattern : public bridge_pattern
	{
	public:
		virtual void do_convert() override
		{
			std::string data = "MYSQL ���ݿ�����--";
			fmt.get()->convert(data);
		}
	};
}


