//============================================================================
// The gray code is a binary numeral system where two successive values differ
// in only one bit.
//
// Given a non-negative integer n representing the total number of bits in the
// code, print the sequence of gray code. A gray code sequence must begin with
// 0.
//
// For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
//
// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2
//
// Complexity:
// O(2^n) time
//============================================================================

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        return grayCode1(n);
    }

    vector<int> grayCode1(int n) {
        vector<int> res;
        res.reserve(1 << n);
        res.push_back(0);
        for (int i = 0; i < n; i++) {
            int m = res.size();
            for (int j = m - 1; j >= 0; j--) {
                res.push_back(res[j] | (1 << i));
            }
        }
        return res;
    }

    vector<int> grayCode2(int n) {
        vector<int> res;
        res.reserve(1 << n);
        for (int i = 0; i < (1 << n); i++) res.push_back(i ^ (i >> 1));
        return res;
    }
};

int main() {

    Solution sol;
    int p0;
    vector<int> p1;

    {
        p0 = 2;
        p1 = sol.grayCode(p0);
        for (auto it : p1) cout << it << endl;
    }

    return 0;
}