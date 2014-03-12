//============================================================================
// Longest Consecutive Sequence
// Given an unsorted array of integers, find the length of the longest 
// consecutive elements sequence.
//
// For example,
// Given [100, 4, 200, 1, 3, 2],
// The longest consecutive elements sequence is [1, 2, 3, 4]. Return its 
// length: 4.
//
// Your algorithm should run in O(n) complexity.
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> tb;
        int res = 1;
        for (auto it : num) {
            if (tb.count(it)) continue;
            tb[it] = 1;
            if (tb.count(it - 1)) res = max(res, merge(tb, it - 1, it));
            if (tb.count(it + 1)) res = max(res, merge(tb, it, it + 1));
        }
        return res;
    }

    int merge(unordered_map<int, int> & tb, int l, int r) {
        int nl = l - tb[l] + 1;
        int nr = r + tb[r] - 1;
        return tb[nl] = tb[nr] = nr - nl + 1;
    }
};

int main() {
    vector<int> p0;

    Solution sol;
    {
        int a[] = { 100, 4, 200, 1, 3, 2 };
        p0.assign(begin(a), end(a));
        cout << sol.longestConsecutive(p0) << endl;
    }
    return 0;
}