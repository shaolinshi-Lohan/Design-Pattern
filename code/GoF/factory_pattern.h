#pragma once
#include <memory>
#include<utility>
#include<iostream>
namespace creational_pattern
{
	class product
	{
	public:
		virtual void print() = 0;
	};
	class a_product : public  product
	{
	public:
		void print() override { std::cout << 'A' << std::endl; }
	};
	class b_product : public  product
	{
	public:
		void print() override { std::cout << 'B' << std::endl; }
	};

	class factory_pattern
	{
	public:
		virtual std::shared_ptr<product> get_product() = 0;
	};

	class a_product_factory_pattern : public factory_pattern
	{
	public:
		std::shared_ptr<product> get_product() override
		{
			return std::shared_ptr<product>{new a_product};
		}
	};
	class b_product_factory_pattern : public factory_pattern
	{
	public:
		std::shared_ptr<product> get_product() override
		{
			return std::shared_ptr<product>{new b_product};
		}
	};
} 

