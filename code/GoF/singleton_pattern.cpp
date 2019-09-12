#include "singleton_pattern.h"

#include "gtest\gtest.h"
using namespace creational_pattern;


creational_pattern::singleton_pattern::~singleton_pattern() noexcept
{
}

singleton_pattern& singleton_pattern::getInstance()
{
	static singleton_pattern instance{};
	return instance;
}


int singleton_pattern::testFun()
{ 
	std::cout << "����ģʽ���Է���" << std::endl; 
	return 0;
}

/*��Ԫ������������������������ʹ��ʱ�ٷſ�
TEST(test_singleton_pattern_getInstance, isSameAddress)
{
	ASSERT_EQ(&creational_pattern::singleton_pattern::getInstance(), &creational_pattern::singleton_pattern::getInstance());
}

TEST(test_singleton_pattern_testFun, runSuceess)
{
	ASSERT_EQ(creational_pattern::singleton_pattern::getInstance().testFun(), 0);
}
*/