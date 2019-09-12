#include "chain_responsibility.h"
#include "gtest\gtest.h"

using namespace behavioral_pattern;
/*

TEST(test_chain_responsibility_request, success_request_100)
{
	std::shared_ptr<chain_responsibility> father{ new father_chain_responsibility() };
	std::shared_ptr<chain_responsibility> mother{ new mother_chain_responsibility () };
	std::shared_ptr<chain_responsibility> bank  { new bank_chain_responsibility() };

	//创建职责链
	father.get()->set_chain_responsibility(mother);
	mother.get()->set_chain_responsibility(bank);

	father.get()->request(100);
}

TEST(test_chain_responsibility_request, success_request_10000)
{
	std::shared_ptr<chain_responsibility> father{ new father_chain_responsibility() };
	std::shared_ptr<chain_responsibility> mother{ new mother_chain_responsibility() };
	std::shared_ptr<chain_responsibility> bank{ new bank_chain_responsibility() };

	//创建职责链
	father.get()->set_chain_responsibility(mother);
	mother.get()->set_chain_responsibility(bank);

	father.get()->request(10000);
}
*/