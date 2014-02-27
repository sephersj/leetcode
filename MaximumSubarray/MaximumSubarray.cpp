//============================================================================
// Find the contiguous subarray within an array (containing at least one
// number) which has the largest sum.
//
// For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
// the contiguous subarray [4,1,2,1] has the largest sum = 6.
//
// Complexity:
// Greedy O(n) time
// Divide and Conquer O(nlog(n)) time
//============================================================================

#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        return maxSubArray2(A, n);
    }

    int maxSubArray1(int A[], int n) {
        int sum = 0, res = INT_MIN;
        for (int i = 0; i < n; i++) {
            sum = max(sum + A[i], A[i]);
            res = max(res, sum);
        }
        return res;
    }

    int maxSubArray2(int A[], int n) {
        return maxSubArrayHelper1(A, 0, n - 1);
    }

    int maxSubArrayHelper1(int A[], int l, int u) {
        if (l > u) return INT_MIN;
        int m = l + (u - l) / 2;
        int sum = 0, lmax = 0, rmax = 0;
        for (int i = m - 1; i >= l; i--) sum += A[i], lmax = max(lmax, sum);
        sum = 0;
        for (int i = m + 1; i <= u; i++) sum += A[i], rmax = max(rmax, sum);
        return max(A[m] + lmax + rmax, max(maxSubArrayHelper1(A, l, m - 1), maxSubArrayHelper1(A, m + 1, u)));
    }
};

int main() {
    Solution sol;

    {
        int p0[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
        int p1 = sol.maxSubArray(p0, sizeof(p0) / sizeof(int));
        cout << p1 << endl;
    }

    {
        int p0[] = { -2, -1 };
        int p1 = sol.maxSubArray(p0, sizeof(p0) / sizeof(int));
        cout << p1 << endl;
    }

    return 0;
}