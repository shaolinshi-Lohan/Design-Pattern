#pragma once

#include <string>
#include <iostream>
#include <utility>
namespace behavioral_pattern
{
	class  mediator_pattern;
	class  concrete_mediator_pattern;
	
	class person_info
	{
	public:
		person_info() {};
		void set_mediator_pattern(mediator_pattern* m)
		{
			this->mediator = m;
		}
		virtual void change() {};
		virtual void updata() {};
	protected:
		mediator_pattern* mediator;
	};
	class doc_person : public person_info
	{
	public:
		virtual void change();
		virtual void updata() 
		{
			std::cout << "doc 更新完成" << std::endl;
		}
	};
	class web_person : public person_info
	{
	public:
		virtual void change();
		virtual void updata()
		{
			std::cout << "web 更新完成" << std::endl;
		}
	};
	class app_person : public person_info
	{
	public:
		virtual void change();
		virtual void updata()
		{
			std::cout << "app 更新完成" << std::endl;
		}
	};
	class mediator_pattern
	{
	public:
		virtual void do_change(person_info* person) = 0;
	};
	class concrete_mediator_pattern : public mediator_pattern
	{
	public:
		void do_change(person_info* person)
		{
			if (typeid(*person) == typeid(doc_person))
			{
				std::cout << "doc_person 发生变化" << std::endl;
				web.updata();
				app.updata();
			}
			else if (typeid(*person) == typeid(web_person))
			{
				std::cout << "web_person 发生变化" << std::endl;
				doc.updata();
				app.updata();
			}
			else if (typeid(*person) == typeid(app_person))
			{
				std::cout << "app_person 发生变化" << std::endl;
				doc.updata();
				web.updata();
			}
		}
	private:
		doc_person doc;
		web_person web;
		app_person app;
	};
}