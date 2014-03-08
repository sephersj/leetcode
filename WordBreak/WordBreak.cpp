//============================================================================
// Given a string s and a dictionary of words dict, determine if s can be 
// segmented into a space-separated sequence of one or more dictionary words.
//
// For example, given
// s = "leetcode",
// dict = ["leet", "code"].
//
// Return true because "leetcode" can be segmented as "leet code".
//
// Complexity:
// O(n^2) time, O(n) space
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.empty()) return false;
        int N = s.size();
        vector<bool> dp(N + 1, false);
        dp[0] = true;
        for (int j = 1; j <= N; j++) {
            for (int i = 0; i < j; i++) {
                if (dict.count(s.substr(i, j - i)) && dp[i]) {
                    dp[j] = true;
                    break;
                }
            }
        }
        return dp[N];
    }
};

int main() {
    Solution sol;
    unordered_set<string> dict = { "leet", "code" };
    cout << sol.wordBreak("leetcode", dict) << endl;
    return 0;
}