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
			//std::swap(value.p, this->p);//swap将内存赋给后者，前者变成空指针
			/*深拷贝*/
			value.p = new char;
			*(value.p) = *(this->p);
			return value;
		}
		char* p;
	};
}


