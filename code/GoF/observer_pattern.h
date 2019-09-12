#pragma once
/*�۲���ģʽ*/
/*��һ��Ⱥ�İ���*/
/*���С����
1.�����Ͷ�����÷ֱ�д��.h��.cpp�ļ�������ѭ������
2.ǰ������ֻ��ʹ��ָ���Ӧ�õ����������ܳ�ʼ������͵��÷���
3.��ͬ�ķ�����ü����ڻ��࣬�����������
4.�������˿��ģ���Ҫ�ú��ŵļ��ɰ��Լ�����
5.virtual override static���������������������ڶ���
6.inlineҪ���ڶ��忪ͷ������������Ч
7.����ת�ɻ���ضϣ����������ָ�����boost��
8.С���������������ɣ���Ա����״̬��һ�£���ò���ע�����������ǳ�Ա����*/
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