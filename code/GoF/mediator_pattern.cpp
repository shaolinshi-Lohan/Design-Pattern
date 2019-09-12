#include "mediator_pattern.h"
#include "gtest\gtest.h"

using namespace behavioral_pattern;

void doc_person::change()
{
	mediator->do_change(this);
}

void web_person::change()
{
	mediator->do_change(this);
}

void app_person::change()
{
	mediator->do_change(this);
}

/*
TEST(test_mediator_pattern_do_change, success_doc_change)
{
	doc_person doc;
	mediator_pattern* mediator = new concrete_mediator_pattern();
	doc.set_mediator_pattern(mediator);
	doc.change();
}

TEST(test_mediator_pattern_do_change, success_web_change)
{
	web_person web;
	mediator_pattern* mediator = new concrete_mediator_pattern();
	web.set_mediator_pattern(mediator);
	web.change();
}
*/