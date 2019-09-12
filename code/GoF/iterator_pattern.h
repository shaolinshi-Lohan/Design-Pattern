#pragma once

#include <vector>
#include <iterator>
#include <iostream>
namespace behavioral_pattern
{
	class iterator_pattern
	{
	public:
	void save_vec()
	{
		vec.push_back(0);
		vec.push_back(1);
	}
	void iterator_vec()
	{
		itr = vec.begin();
		for (; itr != vec.end(); ++itr)
		{
			std::cout << *itr << std::endl;
		}
	}
	private:
		std::vector<int> vec;
		std::vector<int>::iterator itr;
	};
}

