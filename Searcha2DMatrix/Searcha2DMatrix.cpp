//============================================================================
// Search a 2D Matrix
// Write an efficient algorithm that searches for a value in an m x n matrix.
// This matrix has the following properties:
//
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// For example,
//
// Consider the following matrix:
//
// [
//  [1,   3,  5,  7],
//  [10, 11, 16, 20],
//  [23, 30, 34, 50]
// ]
// Given target = 3, return true.
// 
// Complexity:
// 2D Binary Search O(max(m,n)*log(max(m,n))) time
// Upper Right Linear Search O(m+n) time
// 1D Binary Search O(log(m*n)) time
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > & matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        return searchMatrix3(matrix, target);
    }

    bool searchMatrix1(vector<vector<int> > &matrix, int target) {
        int M = matrix.size(), N = matrix[0].size();
        return searchMatrixHelper1(matrix, target, 0, M - 1, 0, N - 1);
    }

    bool searchMatrixHelper1(vector<vector<int> > &matrix, int target, int upper, int lower, int left, int right) {
        if (upper > lower || left > right) return false;
        int row = upper, col = left + (right - left) / 2;
        for (; row <= lower; row++) {
            if (matrix[row][col] == target) return true;
            if (matrix[row][col] > target) break;
        }
        return searchMatrixHelper1(matrix, target, row, lower, left, col - 1) || searchMatrixHelper1(matrix, target, upper, row - 1, col + 1, right);
    }

    bool searchMatrix2(vector<vector<int> > & matrix, int target) {
        int M = matrix.size(), N = matrix[0].size();
        int i = 0, j = N - 1;
        while (i < M && j >= 0) {
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] < target) i++;
            else j--;
        }
        return false;
    }

    bool searchMatrix3(vector<vector<int> > & matrix, int target) {
        int M = matrix.size();
        int N = matrix[0].size();
        int l = 0, u = M*N - 1;
        while (l <= u) {
            int m = l + (u - l) / 2;
            if (matrix[m / N][m%N] == target) return true;
            if (matrix[m / N][m%N] < target) l = m + 1;
            else u = m - 1;
        }
        return false;
    }
};

int main() {
    Solution sol;

    {
        vector<vector<int> > p0 = {
            { 1, 3, 5, 7 },
            { 10, 11, 16, 20 },
            { 23, 30, 34, 50 }
        };
        cout << sol.searchMatrix(p0, 3) << endl;
    }

    return 0;
}
