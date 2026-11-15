// LeetCode 224 - Basic Calculator
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> values;
        int result = 0;
        int number = 0;
        int sign = 1;

        for (int i = 0; i < static_cast<int>(s.size()); i++) {
            char ch = s[i];

            if (ch >= '0' && ch <= '9') {
                number = number * 10 + (ch - '0');
            } else if (ch == '+') {
                result += sign * number;
                number = 0;
                sign = 1;
            } else if (ch == '-') {
                result += sign * number;
                number = 0;
                sign = -1;
            } else if (ch == '(') {
                values.push(result);
                values.push(sign);
                result = 0;
                sign = 1;
            } else if (ch == ')') {
                result += sign * number;
                number = 0;

                result *= values.top();
                values.pop();

                result += values.top();
                values.pop();
            }
        }

        return result + sign * number;
    }
};
