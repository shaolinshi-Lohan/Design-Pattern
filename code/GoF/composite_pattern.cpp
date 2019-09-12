#include "composite_pattern.h"


#include "gtest\gtest.h"
/*以文件树为案例
type[1] id[10001]
type[2] id[10002]
----type[1] id[20001]
----type[2] id[20002]
--------type[1] id[30001]
type[1] id[10003]
*/

/*
using namespace structural_pattern;
TEST(test_composite_pattern_add_composite, success_add_show)
{
	composite_pattern* c00 = new folder_composite_pattern(2, 00000);
	composite_pattern* c11 = new file_composite_pattern(1, 10001);
	composite_pattern* c12 = new folder_composite_pattern(2, 10002);
	composite_pattern* c21 = new file_composite_pattern(1, 20001);
	composite_pattern* c22 = new folder_composite_pattern(2, 20002);
	composite_pattern* c31 = new file_composite_pattern(1, 30001);
	composite_pattern* c13 = new file_composite_pattern(1, 10003);

	c22->add_composite(c31);
	c12->add_composite(c21);
	c12->add_composite(c22);
	c00->add_composite(c11);
	c00->add_composite(c12);
	c00->add_composite(c13);

	c00->get_status();
}
*/