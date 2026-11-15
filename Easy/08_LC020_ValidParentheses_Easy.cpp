// LeetCode 20 - Valid Parentheses
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                brackets.push(ch);
            } else {
                if (brackets.empty()) {
                    return false;
                }

                char top = brackets.top();
                brackets.pop();

                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }

        return brackets.empty();
    }
};
