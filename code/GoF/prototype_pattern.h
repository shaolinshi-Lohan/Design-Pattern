#pragma once
#include<utility>
namespace creational_pattern
{
	class prototype_pattern
	{
	public:
		prototype_pattern clone()
		{
			prototype_pattern value;
			//std::swap(value.p, this->p);//swap���ڴ渳�����ߣ�ǰ�߱�ɿ�ָ��
			/*���*/
			value.p = new char;
			*(value.p) = *(this->p);
			return value;
		}
		char* p;
	};
}


