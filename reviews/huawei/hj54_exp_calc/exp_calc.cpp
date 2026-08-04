#include "exp_calc.h"


void HJ54::native_main()
{
	std::string input;
	std::cin >> input;
	 
	std::stack<int> num_stack;
	std::stack<char> op_stack;
	op_stack.push('(');
	input += ')';

	bool op_flag = false;
	for (int i = 0; i < input.length(); ++i)
	{
		char& c = input[i];
		
		if (op_flag == true)
		{
			if (c == ')')
			{
				while (op_stack.top() != '(')
				{
					compute(num_stack, op_stack);
				}
				op_stack.pop(); // pop '('
			}
			else
			{
				while (compare_priority(op_stack.top(), c))
				{
					compute(num_stack, op_stack);
				}
				op_stack.push(c);

				op_flag = false;
			}
		}
		else
		{
			if (c == '(')
			{
				op_stack.push(c);
			}
			else
			{
				int start_pos = i;
				if (c == '-' || c == '+')
				{
					++i;
				}

				while (std::isdigit(input[i]))
				{
					++i;
				}

				std::string num_str = input.substr(start_pos, i - start_pos);
				int num = std::stoi(num_str);

				num_stack.push(num);

				op_flag = true;
				--i;
			}
		}
	}

	std::cout << num_stack.top() << std::endl;
}

void HJ54::compute(std::stack<int>& num_stack, std::stack<char>& op_stack)
{
	int num2 = num_stack.top();
	num_stack.pop();

	int num1 = num_stack.top();
	num_stack.pop();

	char op = op_stack.top();
	op_stack.pop();

	if (op == '+')
	{
		num_stack.push(num1 + num2);
	}
	else if (op == '-')
	{
		num_stack.push(num1 - num2);
	}
	else if (op == '*')
	{
		num_stack.push(num1 * num2);
	}
	else if (op == '/')
	{
		num_stack.push(num1 / num2);
	}
}

bool HJ54::compare_priority(char op1, char op2)
{
	if (op1 == '(')
		return false;

	if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/'))
		return false;

	return true;
}
