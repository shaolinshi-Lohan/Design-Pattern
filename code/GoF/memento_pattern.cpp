#include "memento_pattern.h"

#include "gtest\gtest.h"

/*
using namespace behavioral_pattern;
TEST(test_memento_pattern_save_restore, success_stack)
{
	memento_pattern memento; 
	rpg r;
	r.set("qwwer");
	memento.push(r.save());
	r.set("assdf");
	std::cout << r.get().c_str() << std::endl;

	r.restore(memento.pop());
	std::cout << r.get().c_str() << std::endl;
}
*/