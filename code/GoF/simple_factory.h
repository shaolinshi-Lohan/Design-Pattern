#pragma once
#include <memory>
#include<utility>
#include<iostream>

namespace creational_pattern
{
	class product{};
	class a_product : public  product {};
	class b_product : public  product {};

	class simple_factory
	{
	public:
		static std::shared_ptr<product> get_product(int type = 0)
		{
			if (1 == type)
				return std::shared_ptr<product>{new a_product};
			return std::shared_ptr<product>{new b_product};
		}
	};
}


