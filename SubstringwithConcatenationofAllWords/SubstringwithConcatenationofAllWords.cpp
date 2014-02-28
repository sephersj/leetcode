//============================================================================
// Substring with Concatenation of All Words
// You are given a string, S, and a list of words, L, that are all of the
// same length. Find all starting indices of substring(s) in S that is a
// concatenation of each word in L exactly once and without any intervening
// characters.
//
// For example, given:
// S: "barfoothefoobarman"
// L: ["foo", "bar"]
//
// You should return the indices: [0,9].
// (order does not matter).
//
// Complexity:
// Brute Force O(M*N) time, O(K*M) space
// Sliding Window O(K*N) time, O(K*M) space
//============================================================================

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        return findSubstring2(S, L);
    }

    vector<int> findSubstring1(string S, vector<string> &L) {
        vector<int> res;
        if (S.empty() || L.empty() || L[0].empty()) return res;
        int N = S.size(), M = L.size(), K = L[0].size();
        unordered_map<string, int> toFind, hasFound;
        for (string & str : L) toFind[str]++;
        for (int i = 0; i <= N - M*K; i++) {
            hasFound.clear();
            int j = 0;
            for (; j < M; j++) {
                string sub = S.substr(i + j*K, K);
                if (!toFind.count(sub)) break;
                hasFound[sub]++;
                if (hasFound[sub] > toFind[sub]) break;
            }
            if (j == M) res.push_back(i);
        }
        return res;
    }

    vector<int> findSubstring2(string S, vector<string> &L) {
        vector<int> res;
        if (S.empty() || L.empty() || L[0].empty()) return res;
        unordered_map<string, int> toFind, hasFound;
        for (auto & str : L) toFind[str]++;
        int N = S.size(), M = L.size(), K = L[0].size();
        for (int k = 0; k < K; k++) {
            hasFound.clear();
            int cnt = 0;
            for (int begin = k, end = k; end < N; end += K) {
                if (!toFind.count(S.substr(end, K))) hasFound.clear(), cnt = 0, begin = end + K;
                else if (hasFound[S.substr(end, K)] < toFind[S.substr(end, K)]) hasFound[S.substr(end, K)]++, cnt++;
                else {
                    while (S.substr(begin, K) != S.substr(end, K)) hasFound[S.substr(begin, K)]--, cnt--, begin += K;
                    begin += K;
                }
                if (cnt == M) res.push_back(begin);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string p0;
    vector<string> p1;

    {
        p0 = "barfoothefoobarman";
        string a[] = {"foo", "bar"};
        p1.assign(begin(a), end(a));
        auto p2 = sol.findSubstring(p0, p1);
        for (auto it : p2) cout << it << " ";
        cout << endl;
    }

    return 0;
}
