//============================================================================
// Given an array of non-negative integers, you are initially positioned at
// the first index of the array.
//
// Each element in the array represents your maximum jump length at that
// position.
//
// Your goal is to reach the last index in the minimum number of jumps.
//
// For example:
// Given array A = [2,3,1,1,4]
//
// The minimum number of jumps to reach the last index is 2. (Jump 1 step
// from index 0 to 1, then 3 steps to the last index.)
//
// Complexity
// O(n)
//============================================================================

#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        int cur = 0, end = 0, step = 0;
        while (end < n - 1) {
            int tmp = end;
            for (; cur <= end; cur++) tmp = max(tmp, cur + A[cur]);
            end = tmp;
            step++;
        }
        return step;
    }
};

int main() {
    Solution sol;

    {
        int p0[] = { 2, 3, 1, 1, 4 };
        int p1 = sizeof(p0) / sizeof(p0[0]);
        cout << sol.jump(p0, p1) << endl;
    }

    return 0;
}
