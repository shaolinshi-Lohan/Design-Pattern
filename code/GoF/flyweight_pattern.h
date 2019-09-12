#pragma once

#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <exception>
namespace structural_pattern
{
	class coord
	{
	public:
		coord(int x, int y) :x(x), y(y) {};
		int get_x() { return x; }
		int get_y() { return y; }
	private:
		int x;
		int y;
	};

	class flyweight_pattern
	{
	public:
		virtual void set_coord(int x, int y) = 0;
		virtual void disp() = 0;
	protected:
		std::vector<coord>vec_coord;
	};

	class black_igo : public flyweight_pattern
	{
		void set_coord(int x, int y) override
		{
			coord crd{ x,y };
			vec_coord.push_back(crd);
		}
		void disp() override
		{
			for each(auto itr in vec_coord)
			{
				std::cout << "black -- " << itr.get_x() << "  " << itr.get_y() << std::endl;
			}
		}
	};

	class white_igo : public flyweight_pattern
	{
		void set_coord(int x,int y) override
		{
			coord crd{ x,y };
			vec_coord.push_back(crd);
		}
		void disp() override
		{
			for each(auto itr in vec_coord)
			{
				std::cout << "white -- " << itr.get_x() << "  " << itr.get_y() << std::endl;
			}
		}
	};

	class factory_flyweight_pattern
	{
	public:
		factory_flyweight_pattern()
		{
			static flyweight_pattern* b = new black_igo();
			static flyweight_pattern* a = new white_igo();;
			flyweight.insert(std::pair<int, flyweight_pattern*>(1, b));
			flyweight.insert(std::pair<int, flyweight_pattern*>(2, a));
		}
		flyweight_pattern*get_igo(int key)
		{
			if (flyweight.find(key) != flyweight.end())
			{
				return flyweight.at(key);
			}
			throw new std::exception("no element");
		}
	private:
		std::map<int, flyweight_pattern*> flyweight;
	};
}