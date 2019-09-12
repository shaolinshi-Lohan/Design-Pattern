#pragma once
#include<memory>
#include<string>
#include<iostream>
#include<list>
namespace behavioral_pattern
{
	class visitor_pattern;
	class element
	{
	public:
		virtual void accept(std::weak_ptr<visitor_pattern> v) {};
		void set(std::string s) { this->str = s; }
		std::string get() { return str; }
	private:
		std::string str;
	};
	class a_element : public element{ void accept(std::weak_ptr<visitor_pattern> v); };
	class b_element : public element{ void accept(std::weak_ptr<visitor_pattern> v); };
	class visitor_pattern
	{
	public:
		virtual void visit(a_element ele) = 0;
		virtual void visit(b_element ele) = 0;
	};
	class hr_visitor_pattern : public visitor_pattern
	{
		virtual void visit(a_element ele);
		virtual void visit(b_element ele);
	};
	class pd_visitor_pattern : public visitor_pattern
	{
		virtual void visit(a_element ele);
		virtual void visit(b_element ele);
	};
	class element_list
	{
	public:
		void insert_element(std::shared_ptr<element> e)
		{
			list_ele.push_back(e);
		}
		void do_visit(std::shared_ptr<visitor_pattern> v)
		{
			for each(auto itr  in list_ele)
			{
				itr.get()->accept(v);
			}
		}
	private:
		std::list<std::shared_ptr<element>> list_ele;
	};
}