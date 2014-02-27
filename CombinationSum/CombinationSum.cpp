//============================================================================
// Given a set of candidate numbers (C) and a target number (T),
// find all unique combinations in C where the candidate numbers sums to T.
//
// The same repeated number may be chosen from C unlimited number of times.
//
// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … ,ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 2,3,6,7 and target 7,
// A solution set is:
// [7]
// [2, 2, 3]
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(begin(candidates), end(candidates));
        vector<int> path;
        vector<vector<int> > res;
        combinationSumHelper(candidates, target, 0, path, res);
        return res;
    }

    void combinationSumHelper(vector<int> &candidates, int target, int begin, vector<int> & path, vector<vector<int> > & res) {
        if (target <= 0) {
            if (target == 0) res.push_back(path);
            return;
        }

        for (int cur = begin; cur < candidates.size(); cur++) {
            path.push_back(candidates[cur]);
            combinationSumHelper(candidates, target - candidates[cur], cur, path, res);
            path.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<int> p0;
    int p1;
    vector<vector<int> > p2;

    {
        p0 = { 2, 3, 6, 7 };
        p1 = 7;
        p2 = sol.combinationSum(p0, p1);
        for (auto it1 : p2) {
            for (auto it2 : it1) cout << it2 << " ";
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}