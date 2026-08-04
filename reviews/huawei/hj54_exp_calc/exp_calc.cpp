#include "exp_calc.h"

#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>

namespace AlgoCpp::Problem::Review::HJ54
{
namespace
{

class Parser
{
public:
	explicit Parser(const std::string_view expression) : m_Expression(expression) {}

	int Parse()
	{
		const int value = ParseExpression();
		SkipSpaces();
		if (m_Position != m_Expression.size()) throw std::invalid_argument("unexpected expression token");
		return value;
	}

private:
	int ParseExpression()
	{
		int value = ParseTerm();
		while (true) {
			SkipSpaces();
			if (Take('+')) value += ParseTerm();
			else if (Take('-')) value -= ParseTerm();
			else return value;
		}
	}

	int ParseTerm()
	{
		int value = ParseFactor();
		while (true) {
			SkipSpaces();
			if (Take('*')) value *= ParseFactor();
			else if (Take('/')) value /= ParseFactor();
			else return value;
		}
	}

	int ParseFactor()
	{
		SkipSpaces();
		if (Take('+')) return ParseFactor();
		if (Take('-')) return -ParseFactor();
		if (Take('(')) {
			const int value = ParseExpression();
			if (!Take(')')) throw std::invalid_argument("missing closing parenthesis");
			return value;
		}
		if (m_Position >= m_Expression.size() || !std::isdigit(static_cast<unsigned char>(m_Expression[m_Position]))) {
			throw std::invalid_argument("number expected");
		}
		int value = 0;
		while (m_Position < m_Expression.size() && std::isdigit(static_cast<unsigned char>(m_Expression[m_Position]))) {
			value = value * 10 + (m_Expression[m_Position++] - '0');
		}
		return value;
	}

	bool Take(const char expected)
	{
		SkipSpaces();
		if (m_Position >= m_Expression.size() || m_Expression[m_Position] != expected) return false;
		++m_Position;
		return true;
	}

	void SkipSpaces()
	{
		while (m_Position < m_Expression.size() && std::isspace(static_cast<unsigned char>(m_Expression[m_Position]))) ++m_Position;
	}

	std::string_view m_Expression;
	std::size_t m_Position = 0;
};

} // namespace

int EvaluateExpression(const std::string_view expression) { return Parser(expression).Parse(); }

void native_main()
{
	std::string expression;
	std::cin >> expression;
	std::cout << EvaluateExpression(expression);
}

} // namespace AlgoCpp::Problem::Review::HJ54
