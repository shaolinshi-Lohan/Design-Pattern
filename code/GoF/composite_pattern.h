#pragma once
/*组合模式*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
namespace structural_pattern
{
	class composite_pattern
	{
	public:
		virtual void get_status() = 0;
		virtual void add_composite(composite_pattern* comp) {};
		virtual void remove_composite(composite_pattern* comp) {};
	public:
		short file_type;
		unsigned long file_id;
	};

	class file_composite_pattern : public composite_pattern
	{
	public:
		file_composite_pattern(short file_type, unsigned long file_id)
		{
			this->file_id = file_id;
			this->file_type = file_type;
		}
		void get_status() override
		{
			std::cout << "type[" << file_type <<"] id["<< file_id<<"]"<<std::endl;
		}
	};
	class folder_composite_pattern : public composite_pattern
	{
	public:
		folder_composite_pattern(short file_type, unsigned long file_id)
		{
			this->file_id = file_id;
			this->file_type = file_type;
		}
	
		void get_status() override
		{
			std::cout << "type[" << file_type << "] id[" << file_id << "]" << std::endl;
			for each (auto var in list_comp)
			{
#define FILE_NUM 10000
				for (auto i = var.get()->file_id / FILE_NUM;i; --i)
				{
					std::cout << "----";
				}
				var.get()->get_status();
			}
		}
		void add_composite(composite_pattern* comp)
		{
			list_comp.push_back(std::shared_ptr<composite_pattern>(comp));
			std::cout << "add " << "type[" << comp->file_type << "] id[" << comp->file_id << "]" << std::endl;
		}
		void remove_composite(composite_pattern* comp)
		{
			for (auto itr = list_comp.begin(); itr != list_comp.end(); ++itr)
			{
				if (itr->get()->file_id == comp->file_id && itr->get()->file_type == comp->file_type)
				{
					list_comp.erase(itr);
					std::cout<<"earse "<<  "type[" << comp->file_type << "] id[" << comp->file_id << "]" << std::endl;
				}
			}
		}
	private:
		std::vector<std::shared_ptr<composite_pattern>>list_comp{};
	};
}