//============================================================================
// Given a string containing just the characters '(' and ')', find the length
// of the longest valid (well-formed) parentheses substring.
//
// For "(()", the longest valid parentheses substring is "()", which has
// length = 2.
//
// Another example is ")()())", where the longest valid parentheses substring
// is "()()", which has length = 4.
//
// Complexity:
// Stack based, O(n) time, O(n) space
// Two Scans, O(n) time, O(1) space
//============================================================================

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        return longestValidParentheses2(s);
    }

    int longestValidParentheses1(string & s) {
        stack<int> stk;
        int res = 0, last = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') stk.push(i);
            else if (stk.empty()) last = i;
            else {
                stk.pop();
                res = max(res, i - (stk.empty() ? last : stk.top()));
            }
        }
        return res;
    }

    int longestValidParentheses2(string & s) {
        int N = s.size();
        return max(longestValidParenthesesHelper(s, '(', 0, N, 1),
            longestValidParenthesesHelper(s, ')', N - 1, -1, -1));
    }

    int longestValidParenthesesHelper(string & s, char c, int start, int end, int step) {
        int res = 0, k = 0, l = 0;
        for (int i = start; i != end; i += step) {
            if (s[i] == c) k++, l++;
            else k--, l++;
            if (k == 0) res = max(res, l);
            else if (k < 0) k = 0, l = 0;
        }
        return res;
    }
};


int main() {
    Solution sol;
    cout << sol.longestValidParentheses("(()") << endl;
    cout << sol.longestValidParentheses("()()") << endl;
    cout << sol.longestValidParentheses("()(()") << endl;
    cout << sol.longestValidParentheses("(()()") << endl;
    cout << sol.longestValidParentheses("())()") << endl;
    cout << sol.longestValidParentheses(")()()") << endl;
    return 0;
}