#pragma once

#include <charconv>
#include <cctype>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace AlgoCpp::Template::Review::HuaweiIO
{

inline std::string_view Trim(const std::string_view input)
{
	std::size_t begin = 0;
	while (begin < input.size() && std::isspace(static_cast<unsigned char>(input[begin]))) ++begin;
	std::size_t end = input.size();
	while (end > begin && std::isspace(static_cast<unsigned char>(input[end - 1]))) --end;
	return input.substr(begin, end - begin);
}

inline std::vector<int> SplitIntegers(const std::string_view input, const char delimiter)
{
	std::vector<int> values;
	std::size_t begin = 0;
	while (begin <= input.size()) {
		const std::size_t end = input.find(delimiter, begin);
		const std::string_view token = Trim(input.substr(begin, end - begin));
		int value = 0;
		const auto result = std::from_chars(token.data(), token.data() + token.size(), value);
		if (result.ec != std::errc{} || result.ptr != token.data() + token.size()) {
			throw std::invalid_argument("invalid integer token");
		}
		values.push_back(value);
		if (end == std::string_view::npos) break;
		begin = end + 1;
	}
	return values;
}

inline std::string JoinIntegers(const std::vector<int>& values, const char delimiter)
{
	std::string output;
	for (std::size_t index = 0; index < values.size(); ++index) {
		if (index > 0) output.push_back(delimiter);
		output += std::to_string(values[index]);
	}
	return output;
}

} // namespace AlgoCpp::Template::Review::HuaweiIO
