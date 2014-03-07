//============================================================================
// Given n non-negative integers representing the histogram's bar height where
// the width of each bar is 1, find the area of largest rectangle in the
// histogram.
//
// For example,
// Given height = [2,1,5,6,2,3],
// return 10.
// 
// Complexity:
// Sorted Stack O(n)
//============================================================================

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if (height.empty()) return 0;
        height.push_back(0);
        stack<int> stk;
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!stk.empty() && height[stk.top()] >= height[i]) {
                int h = height[stk.top()];
                stk.pop();
                int w = stk.empty() ? i : i - stk.top() - 1;
                res = max(res, h*w);
            }
            stk.push(i);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> p0;

    {
        int a[] = { 2, 1, 5, 6, 2, 3 };
        p0.assign(begin(a), end(a));
        cout << sol.largestRectangleArea(p0) << endl;
    }

    return 0;
}
