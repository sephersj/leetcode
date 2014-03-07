//============================================================================
// Scramble String
// Given a string s1, we may represent it as a binary tree by partitioning it
// to two non-empty substrings recursively.
//
// Below is one possible representation of s1 = "great":
//
//    great
//   /    \
//  gr    eat
// / \    /  \
//g   r  e   at
//           / \
//          a   t
//To scramble the string, we may choose any non-leaf node and swap its two
// children.
//
//For example, if we choose the node "gr" and swap its two children, it
// produces a scrambled string "rgeat".
//
//    rgeat
//   /    \
//  rg    eat
// / \    /  \
//r   g  e   at
//           / \
//          a   t
//We say that "rgeat" is a scrambled string of "great".
//
//Similarly, if we continue to swap the children of nodes "eat" and "at", it
// produces a scrambled string "rgtae".
//
//    rgtae
//   /    \
//  rg    tae
// / \    /  \
//r   g  ta  e
//       / \
//      t   a
//We say that "rgtae" is a scrambled string of "great".
//
//Given two strings s1 and s2 of the same length, determine if s2 is a
// scrambled string of s1.
//
// Complexity:
// O(n^3) time, O(n^3) space
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        return isScramble1(s1, s2);
    }

    bool isScramble1(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        int N = s1.size();
        vector<vector<vector<int> > > memo(N + 1, vector<vector<int> >(N + 1, vector<int>(N + 1, -1)));
        return isScrambleHelper1(s1, s2, 0, 0, N, memo);
    }

    bool isScrambleHelper1(string & s1, string & s2, int i, int j, int l, vector<vector<vector<int> > > & memo) {
        if (memo[i][j][l] != -1) return memo[i][j][l];
        if (l == 1) return memo[i][j][l] = (s1[i] == s2[j]);
        for (int k = 1; k < l; k++) {
            if ((isScrambleHelper1(s1, s2, i, j, k, memo) && isScrambleHelper1(s1, s2, i + k, j + k, l - k, memo)) ||
                isScrambleHelper1(s1, s2, i, j + l - k, k, memo) && isScrambleHelper1(s1, s2, i + k, j, l - k, memo)) return memo[i][j][l] = true;
        }
        return memo[i][j][l] = false;
    }

    bool isScramble2(string & s1, string & s2) {
        if (s1.size() != s2.size()) return false;
        int N = s1.size();
        vector<vector<vector<bool> > > dp(N, vector<vector<bool> >(N, vector<bool>(N + 1, false)));
        for (int l = 1; l <= N; l++) {
            for (int i = 0; i <= N - l; i++) {
                for (int j = 0; j <= N - l; j++) {
                    if (l == 1) {
                        if (s1[i] == s2[j]) dp[i][j][l] = true;
                        continue;
                    }
                    for (int k = 1; k < l; k++) {
                        if (dp[i][j][k] && dp[i + k][j + k][l - k]) dp[i][j][l] = true;
                        if (dp[i][j + l - k][k] && dp[i + k][j][l - k]) dp[i][j][l] = true;
                        if (dp[i][j][k]) break;
                    }
                }
            }
        }
        return dp[0][0][N];
    }
};

int main() {

    Solution sol;
    cout << sol.isScramble("rgtae", "great") << endl;

    return 0;
}