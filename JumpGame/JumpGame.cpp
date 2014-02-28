//============================================================================
// Given an array of non-negative integers, you are initially positioned at
// the first index of the array.
//
// Each element in the array represents your maximum jump length at that
// position.
//
// Determine if you are able to reach the last index.
//
// For example:
// A = [2,3,1,1,4], return true.
//
// A = [3,2,1,0,4], return false.
//
// Complexity
// O(n)
//============================================================================

#include <algorithm>

using namespace std;


class Solution {
public:
    bool canJump(int A[], int n) {
        int cur = 0, end = 0;
        while (end < n - 1) {
            int tmp = end;
            for (; cur <= end; cur++) tmp = max(tmp, cur + A[cur]);
            if (tmp <= end) return false;
            end = tmp;
        }
        return true;
    }
};

int main() {
    Solution sol;

    {
        int p0[] = { 2, 3, 1, 1, 4 };
        int p1 = sizeof(p0) / sizeof(p0[0]);
        cout << sol.canJump(p0, p1) << endl;
    }

    {
        int p0[] = { 3, 2, 1, 0, 4 };
        int p1 = sizeof(p0) / sizeof(p0[0]);
        cout << sol.canJump(p0, p1) << endl;
    }

    return 0;
}