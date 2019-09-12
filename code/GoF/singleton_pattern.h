#pragma once
/*
单例模式讲解
*/
#include <iostream>
#include <assert.h>
namespace creational_pattern
{
	class singleton_pattern final
	{
	public:
		
		virtual ~singleton_pattern() noexcept;
		static singleton_pattern& getInstance();
		int testFun();

	private:
		singleton_pattern() = default;
		singleton_pattern(const singleton_pattern& sp) = delete;
		singleton_pattern& operator= (const singleton_pattern& sp) = delete;
		singleton_pattern(const singleton_pattern&& sp) = delete;
		singleton_pattern& operator= (const singleton_pattern&& sp) = delete;
	};	
}


