#include "visitor_pattern.h"
#include "gtest\gtest.h"

using namespace behavioral_pattern;

void a_element::accept(std::weak_ptr<visitor_pattern> v)
{
	v.lock().get()->visit(*this);
}
void b_element::accept(std::weak_ptr<visitor_pattern> v)
{
	v.lock().get()->visit(*this);
}
void hr_visitor_pattern::visit(a_element ele)
{
	std::cout << "hr_visitor_pattern: a_element: " << ele.get().c_str() << std::endl;
}
void hr_visitor_pattern::visit(b_element ele)
{
	std::cout << "hr_visitor_pattern: b_element: " << ele.get().c_str() << std::endl;
}

void pd_visitor_pattern::visit(a_element ele)
{
	std::cout << "pd_visitor_pattern: a_element: " << ele.get().c_str() << std::endl;
}
void pd_visitor_pattern::visit(b_element ele)
{
	std::cout << "pd_visitor_pattern: b_element: " << ele.get().c_str() << std::endl;
}
/*
TEST(test_visitor_pattern, success_insert_visit)
{
	std::shared_ptr<element> e1{new a_element()};
	e1.get()->set("aa00");
	std::shared_ptr<element> e2{ new a_element() };
	e2.get()->set("aa11");
	std::shared_ptr<element> e3{ new b_element() };
	e3.get()->set("bb22");

	element_list li;
	li.insert_element(e1);
	li.insert_element(e2);
	li.insert_element(e3);

	std::shared_ptr<visitor_pattern> v{ new pd_visitor_pattern() };
	li.do_visit(v);
}
*/