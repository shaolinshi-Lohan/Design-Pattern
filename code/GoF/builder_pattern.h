#pragma once
#include<iostream>
#include<string>
#include<memory>
namespace creational_pattern
{
	class product
	{
	public:
		std::string part_head{""};
		std::string part_trail{ "" };
	};
	class builder_pattern
	{
	public:
		virtual void build_part_head() = 0;
		virtual void build_part_trail() = 0;
		virtual std::shared_ptr<product> get_product() = 0;
	protected:
		std::shared_ptr<product> pro{ new product };
	};

	class product_builder_pattern : public builder_pattern
	{
	public:
		virtual void build_part_head() override
		{
			pro.get()->part_head = "创建头部成功";
		}
		virtual void build_part_trail() override
		{
			pro.get()->part_trail = "创建尾部成功";
		}
		virtual std::shared_ptr<product> get_product() override
		{
			return pro;
		}
	};
	class director
	{
	public:
		std::shared_ptr<product> construct()
		{
			builder.get()->build_part_head();
			builder.get()->build_part_trail();
			return builder.get()->get_product();
		}

	private:
		std::shared_ptr<builder_pattern> builder{ new product_builder_pattern() };
	};
}