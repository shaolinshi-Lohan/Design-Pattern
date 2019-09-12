#pragma once
/*观察者模式*/
/*以一个群聊案例*/
/*编程小技巧
1.声明和定义最好分别写在.h和.cpp文件，避免循环依赖
2.前向声明只能使用指针和应用的声明，不能初始化对象和调用方法
3.共同的方法最好集成在基类，避免代码冗余
4.代码是人看的，不要用很炫的技巧把自己坑了
5.virtual override static可以用在声明但不能用在定义
6.inline要用在定义开头，用在声明无效
7.避免转成基类截断，最好用智能指针或者boost库
8.小心类对象的重新生成，成员变量状态不一致，最好采用注入依赖而不是成员变量*/
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <functional>
# include<cstdlib>
namespace behavioral_pattern
{
	class member;
	class msg_info;

	class observer_pattern
	{
	public:
		virtual void add(std::shared_ptr<member> mem) = 0;
		virtual void del(std::shared_ptr<member> mem) = 0;
		virtual void notify(msg_info& msg) = 0;
	};

	class room_observer_pattern : public observer_pattern
	{
	public:
		virtual void add(std::shared_ptr<member> mem) override;
		virtual void del(std::shared_ptr<member> mem) override;
		virtual void notify(msg_info& msg);
	private:
		std::vector<std::shared_ptr<member>>list_mem{};
	};
}

namespace behavioral_pattern
{
	class msg_info
	{
	public:
		msg_info(std::string m, unsigned long i) :msg(m), id(i) {};
		std::string msg{};
		unsigned long id{ 0 };
	};

	class member
	{
	public:
		virtual void update();
		virtual void call_notify(std::shared_ptr<observer_pattern> room);
		virtual int get_id() = 0;
	protected:
	};

	class mom_member : public member
	{
	public:
		int get_id() override;
	};

	class son_member : public member
	{
	public:
		int get_id() override;
	};
}