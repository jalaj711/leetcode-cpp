#include<string>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        string levels[3] = {"Thousand", "Million", "Billion"};
        string tens[9] = {"Twenty", "Thirty", "Forty", "Fifty",
                          "Sixty", "Seventy", "Eighty", "Ninety"};
        string ones[20] = {
                "Zero",
                "One",
                "Two",
                "Three",
                "Four",
                "Five",
                "Six",
                "Seven",
                "Eight",
                "Nine",
                "Ten",
                "Eleven",
                "Twelve",
                "Thirteen",
                "Fourteen",
                "Fifteen",
                "Sixteen",
                "Seventeen",
                "Eighteen",
                "Nineteen"
        };
        if (num < 20) return ones[num];
        if (num < 100) return tens[num / 10 - 2] + ((num % 10) ? " " + ones[num % 10] : "");
        if (num < 1000) return ones[num / 100] + " Hundred" + ((num % 100) ? " " + numberToWords(num % 100) : "");

        int currentLevel = 2;
        int divisor = 1e9;
        string ans = "";
        while (num != 0) {
            if (num < 1000) {
                ans += numberToWords(num);
                break;
            }
            int divide = num / divisor;
            num = num % divisor;
            if (divide > 0) {
                ans += numberToWords(divide) + " " + levels[currentLevel] + (num ? " " : "");
            }
            divisor /= 1000;
            currentLevel--;
        }
        return ans;
    }
};