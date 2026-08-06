#include "implement_queue_using_stacks.h"

namespace AlgoCpp::Problem::DataStructure::LC232
{

	// Implement the public interface declared in implement_queue_using_stacks.h.

	MyQueue::MyQueue() {}

	void MyQueue::push(int x)
	{ 
		m_InStack.push(x);
	}

	int MyQueue::pop()
	{
		// if out empty, in to out
		if (m_OutStack.empty())
		{
			InToOut();
		}
		// pop out
		int rst = m_OutStack.top();
		m_OutStack.pop();
		return rst;
	}

	int MyQueue::peek()
	{
		// if out empty, in to out
		if (m_OutStack.empty())
		{
			InToOut();
		}
		// get top
		return m_OutStack.top();
	}

	bool MyQueue::empty()
	{
		return m_InStack.empty() && m_OutStack.empty();
	}

	void MyQueue::InToOut()
	{
		while (!m_InStack.empty())
		{
			m_OutStack.push(m_InStack.top());
			m_InStack.pop();
		}
	}

} // namespace AlgoCpp::Problem::DataStructure::LC232
