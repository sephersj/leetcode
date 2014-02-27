//============================================================================
// Interleaving String
// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
// For example,
// Given:
// s1 = "aabcc",
// s2 = "dbbca",
//
// When s3 = "aadbbcbcac", return true.
// When s3 = "aadbbbaccc", return false.
//
// Complexity:
// O(n^2) time, O(n^2) space
//============================================================================

#include <iostream>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size();
        if (s3.size() != n1 + n2) return false;
        vector<vector<bool> > dp(n1 + 1, vector<bool>(n2 + 1, false));
        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                if (i == 0 && j == 0) dp[i][j] = true;
                else if (i != 0 && s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) dp[i][j] = true;
                else if (j != 0 && s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]) dp[i][j] = true;
            }
        }
        return dp[n1][n2];
    }
};

int main() {
    Solution sol;
    string p0, p1, p2;

    {
        p0 = "aabcc";
        p1 = "dbbca";
        p2 = "aadbbcbcac";
        cout << sol.isInterleave(p0, p1, p2) << "," << 1 << endl;
    }

    {
        p0 = "aabcc";
        p1 = "dbbca";
        p2 = "aadbbbaccc";
        cout << sol.isInterleave(p0, p1, p2) << "," << 0 << endl;
    }

    {
        p0 = "";
        p1 = "b";
        p2 = "b";
        cout << sol.isInterleave(p0, p1, p2) << "," << 1 << endl;
    }

    {
        p0 = "a";
        p1 = "";
        p2 = "a";
        cout << sol.isInterleave(p0, p1, p2) << "," << 1 << endl;
    }

    {
        p0 = "aa";
        p1 = "ab";
        p2 = "aaba";
        cout << sol.isInterleave(p0, p1, p2) << "," << 1 << endl;
    }

    {
        p0 = "aabc";
        p1 = "abad";
        p2 = "aabacbad";
        cout << sol.isInterleave(p0, p1, p2) << "," << 1 << endl;
    }

    return 0;
}