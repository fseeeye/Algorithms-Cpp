// refs : https://leetcode.cn/problems/implement-queue-using-stacks/
#pragma once

#include <bits/stdc++.h>

namespace AlgoCpp::Problem::DataStructure::LC232
{
	class MyQueue
	{
	public:
		MyQueue();

		void push(int x);

		int pop();

		int peek();

		bool empty();
	private:
		void InToOut();
	private:
		std::stack<int> m_InStack;
		std::stack<int> m_OutStack;
	};

} // namespace AlgoCpp::Problem::DataStructure::LC232
