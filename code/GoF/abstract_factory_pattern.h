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
	class app_product : public  product {};


	class game_app_product : public  app_product
	{
	public:
		void print() override { std::cout << "game -- app" << std::endl; }
	};
	class bank_app_product : public  app_product
	{
	public:
		void print() override { std::cout << "bank -- app" << std::endl; }
	};

	class web_product : public  product {};
	class game_web_product : public  web_product
	{
	public:
		void print() override { std::cout << "game -- web" << std::endl; }
	};
	class bank_web_product : public  web_product
	{
	public:
		void print() override { std::cout << "bank -- web" << std::endl; }
	};

	class abstract_factory_pattern
	{
	public:
		virtual std::shared_ptr<product> get_game_product() = 0;
		virtual std::shared_ptr<product> get_bank_product() = 0;
	};

	class app_product_abstract_factory_pattern : public abstract_factory_pattern
	{
	public:
		std::shared_ptr<product> get_game_product() override
		{
			return std::shared_ptr<product>{new game_app_product };
		}
		std::shared_ptr<product> get_bank_product() override
		{
			return std::shared_ptr<product>{new bank_app_product};
		}
	};
	class web_product_abstract_factory_pattern : public abstract_factory_pattern
	{
	public:
		std::shared_ptr<product> get_game_product() override
		{
			return std::shared_ptr<product>{new game_web_product };
		}
		std::shared_ptr<product> get_bank_product() override
		{
			return std::shared_ptr<product>{new bank_web_product};
		}
	};
}

