#include "footbal_match_score.h"

void HJT01::native_main()
{
	// handle input
	std::vector<std::string> inputs;

	std::string tmp;
	while (std::getline(std::cin, tmp))
	{
		inputs.push_back(tmp);
	}

	// process
	auto rst = sort(inputs);

	// output
	std::stringstream s;
	for (auto& [teamname, score] : rst)
	{
		s << teamname << " " << score << ',';
	}

	auto output = s.str();
	output.erase(output.end() - 1);

	std::cout << output << std::endl;
}

std::vector<std::pair<std::string, int>> HJT01::sort(std::vector<std::string>& inputs)
{
	// sum scores
	std::unordered_map<std::string, int> scores;

	for (auto& input : inputs)
	{
		// "a-b 2:0"
		std::vector<std::string> soutput1; // "a-b" "2:0"
		std::vector<int> ioutput; // 2 0
		std::vector<std::string> soutput2; // a b

		spilt(input, ' ', soutput1);
		spilt(soutput1[1], ':', ioutput);
		spilt(soutput1[0], '-', soutput2);

		if (ioutput[0] == ioutput[1])
		{
			scores[soutput2[0]] += 1;
			scores[soutput2[1]] += 1;
		}
		else if (ioutput[0] > ioutput[1])
		{
			scores[soutput2[0]] += 3;
			scores[soutput2[1]] += 0;
		}
		else if (ioutput[0] < ioutput[1])
		{
			scores[soutput2[1]] += 3;
			scores[soutput2[0]] += 0;
		}
	}

	// sort
	std::vector<std::pair<std::string, int>> rst(scores.begin(), scores.end());

	std::sort(rst.begin(), rst.end(), [](std::pair<std::string, int>& a, std::pair<std::string, int>& b) -> bool {
		return a.second != b.second ? a.second > b.second : a.first < b.first;
		});

	return rst;
}
