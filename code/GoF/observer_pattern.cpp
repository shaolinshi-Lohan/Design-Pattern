#include "observer_pattern.h"
#include "gtest\gtest.h"

void behavioral_pattern::room_observer_pattern::add(std::shared_ptr<member> mem)
{
	list_mem.push_back(mem) ;
}
void behavioral_pattern::room_observer_pattern::del(std::shared_ptr<member> mem)
{
	for(auto itr= list_mem.begin();itr!=list_mem.end();++itr)
	{
		if (itr->get()->get_id() == mem->get_id())
		{
			list_mem.erase(itr);
			break;
		}
	}
}
void behavioral_pattern::room_observer_pattern::notify(msg_info& msg)
{
	for each(auto itr in list_mem)
	{
		if (itr->get_id() != msg.id)
		{
			itr->update();
		}
	}
}
void behavioral_pattern::member::update()
{
	std::cout << get_id() << "__accept" << std::endl;
}
void behavioral_pattern::member::call_notify(std::shared_ptr<observer_pattern> room)
{
	msg_info info("send msg", get_id());
	std::cout << get_id() << "__send msg" << std::endl;
	room->notify(info);
}
int behavioral_pattern::mom_member::get_id()
{
	return 1;
}
int behavioral_pattern::son_member::get_id()
{
	return 2;
}

using namespace behavioral_pattern;
/*
TEST(test_observer_pattern_add_notify, success_add_notify)
{
	std::shared_ptr<observer_pattern> obs{ new room_observer_pattern() };
	std::shared_ptr<member> mom{ new mom_member() };
	std::shared_ptr<member> son{ new son_member() };
	obs->add(mom);
	obs->add(son);
	son->call_notify(obs);
	mom->call_notify(obs);
}
*/

