#include<string>
#include<iostream>
using namespace std;

void process(int* num, int tk, string *ans, string ch){
	while(*num >= tk){
		*num -= tk;
		*ans = *ans + ch;
	}
}

class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
	process(&num, 1000, &ans, "M");
	process(&num, 900, &ans, "CM");
	process(&num, 500, &ans, "D");
	process(&num, 400, &ans, "CD");
	process(&num, 100, &ans, "C");
	process(&num, 90, &ans, "XC");
	process(&num, 50, &ans, "L");
	process(&num, 40, &ans, "XL");
	process(&num, 10, &ans, "X");
	process(&num, 9, &ans, "IX");
	process(&num, 5, &ans, "V");
	process(&num, 4, &ans, "IV");
	process(&num, 1, &ans, "I");
	return ans;
    }
};

int main() {
	Solution* s = new Solution();
	cout << s -> intToRoman(34) << endl;
	cout << s -> intToRoman(1994) << endl;
	return 0;
}
