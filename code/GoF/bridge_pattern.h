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
			std::cout << data.c_str() << " 转成TXT格式完毕" << std::endl;
		}
	};
	class pdf_formate : public formate
	{
	public:
		virtual void convert(std::string data) override
		{
			std::cout << data.c_str() << " 转成PDF格式完毕" << std::endl;
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
			std::string data = "DB 数据库数据--";
			fmt.get()->convert(data);
		}
	};
	class mysql_bridge_pattern : public bridge_pattern
	{
	public:
		virtual void do_convert() override
		{
			std::string data = "MYSQL 数据库数据--";
			fmt.get()->convert(data);
		}
	};
}


