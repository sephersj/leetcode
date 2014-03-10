//============================================================================
// NextPermutation
// Implement next permutation, which rearranges numbers into the
// lexicographically next greater permutation of numbers.
//
// If such arrangement is not possible, it must rearrange it as the lowest
// possible order (ie, sorted in ascending order).
//
// The replacement must be in-place, do not allocate extra memory.
//
// Here are some examples. Inputs are in the left-hand column and its
// corresponding outputs are in the right-hand column.
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1
//
// Complexity
// O(n) time
//============================================================================

#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int N = num.size();
        if (N < 2) return;
        int i = N - 1;
        while (i > 0 && num[i - 1] >= num[i]) i--;
        reverse(begin(num) + i, end(num));
        if (i > 0) {
            int j = i;
            i--;
            while (num[j] <= num[i]) j++;
            swap(num[i], num[j]);
        }
    }
};

int main() {
    Solution sol;
    vector<int> num;

    {
        num = { 1, 2, 3 };
        sol.nextPermutation(num);
        for (auto it : num) cout << it << " ";
        cout << endl;
    }

    {
        num = { 3, 2, 1 };
        sol.nextPermutation(num);
        for (auto it : num) cout << it << " ";
        cout << endl;
    }

    {
        num = { 1, 1, 5 };
        sol.nextPermutation(num);
        for (auto it : num) cout << it << " ";
        cout << endl;
    }

    return 0;
}