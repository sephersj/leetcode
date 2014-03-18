//============================================================================
// There are two sorted arrays A and B of size m and n respectively. Find the
// median of the two sorted arrays. The overall run time complexity should be
// O(log (m+n)).
//============================================================================

#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        return findMedianSortedArrays2(A, m, B, n);
    }

    double findMedianSortedArrays1(int A[], int m, int B[], int n) {
        int r1 = -1, r2 = -1, i = 0, j = 0;
        for (int k = (m + n) / 2; k >= 0; k--) {
            r1 = r2;
            if (j == n || (i < m && A[i] <= B[j])) r2 = A[i++];
            else r2 = B[j++];
        }
        if ((m + n) % 2) return (double)r2;
        return (r1 + r2) / 2.0;
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n, half = total / 2;
        if (total % 2) return findKth(A, m, B, n, half + 1);
        return (findKth(A, m, B, n, half) + findKth(A, m, B, n, half + 1)) / 2.0;
    }

    int findKth(int A[], int m, int B[], int n, int k) {
        if (m > n) return findKth(B, n, A, m, k);
        if (m == 0) return B[k - 1];
        if (k == 1) return min(A[0], B[0]);
        int l = min(k / 2, m), r = k - l;
        if (A[l - 1] < B[r - 1]) return findKth(A + l, m - l, B, n, k - l);
        else if (A[l - 1] > B[r - 1]) return findKth(A, m, B + r, n - r, k - r);
        return A[l - 1];
    }
};

int main() {
    Solution sol;

    {
        int p0[] = { 1, 12, 15, 26, 38 };
        int p1 = sizeof(p0) / sizeof(p0[0]);
        int p2[] = { 2, 13, 17, 30, 45 };
        int p3 = sizeof(p2) / sizeof(p2[0]);
        cout << sol.findMedianSortedArrays(p0, p1, p2, p3) << endl;
    }

    return 0;
}