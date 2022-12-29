#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> digitMap(char dig)
{
	vector<string> vec;
	switch (dig)
	{
	case '2':
		vec.push_back("a");
		vec.push_back("b");
		vec.push_back("c");
		break;
	case '3':
		vec.push_back("d");
		vec.push_back("e");
		vec.push_back("f");
		break;
	case '4':
		vec.push_back("g");
		vec.push_back("h");
		vec.push_back("i");
		break;
	case '5':
		vec.push_back("j");
		vec.push_back("k");
		vec.push_back("l");
		break;
	case '6':
		vec.push_back("m");
		vec.push_back("n");
		vec.push_back("o");
		break;
	case '7':
		vec.push_back("p");
		vec.push_back("q");
		vec.push_back("r");
		vec.push_back("s");
		break;
	case '8':
		vec.push_back("t");
		vec.push_back("u");
		vec.push_back("v");
		break;
	case '9':
		vec.push_back("w");
		vec.push_back("x");
		vec.push_back("y");
		vec.push_back("z");
		break;
	default:
		break;
	}
	return vec;
}

class Solution
{
public:
	vector<string> letterCombinations(string digits)
	{
		vector<string> ans;
		vector<string> cr;
		vector<string> dig;
		if (digits.length() == 0)
			return ans;
		vector<string> ans1 = digitMap(digits[digits.length() - 1]);
		for (int l = 0; l < ans1.size(); l++)
		{
			ans.push_back(ans1[l]);
		}
		for (int i = digits.length() - 2; i >= 0; i--)
		{
			cr = ans;
			ans.clear();
			dig = digitMap(digits[i]);
			for (int j = 0; j < cr.size(); j++)
			{
				for (int k = 0; k < dig.size(); k++)
				{
					ans.push_back(dig[k] + cr[j]);
				}
			}
		}
		return ans;
	}
};

int main()
{
	Solution *s = new Solution();
	s->letterCombinations("23");
	s->letterCombinations("");
	s->letterCombinations("9");
	return 0;
}
