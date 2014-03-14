//============================================================================
// Sort Colors
// Given an array with n objects colored red, white or blue, sort them so that
// objects of the same color are adjacent, with the colors in the order red,
// white and blue.
//
// Here, we will use the integers 0, 1, and 2 to represent the color red,
// white, and blue respectively.
//
// Note:
// You are not suppose to use the library's sort function for this problem.
//
// Follow up:
// A rather straight forward solution is a two-pass algorithm using counting
// sort.
// First, iterate the array counting number of 0's, 1's, and 2's, then
// overwrite array with total number of 0's, then 1's and followed by 2's.
//
// Could you come up with an one-pass algorithm using only constant space?
//
// Insertion Sort, O(n^2) time, O(n*k) if array is already k sorted
// Quick Sort, O(nlog(n)) average, O(n^2) worse
// Merge Sort, O(nlog(n)) time, O(n) space
// Heap Sort, O(nlog(n)) time, O(1) space
// Counting Sort, O(n) time, o(1) space
//============================================================================

class Solution {
public:
    void sortColors(int A[], int n) {
        heapSort(A, n);
    }

    void insertionSort(int A[], int n) {
        for (int i = 0; i < n; i++) {
            int t = A[i], j = i;
            for (; j > 0 && A[j - 1] > t; j--) A[j] = A[j - 1];
            A[j] = t;
        }
    }

    void quickSort(int A[], int n) {
        quickSortHelper(A, 0, n - 1);
    }

    void quickSortHelper(int A[], int l, int u) {
        if (l >= u) return;
        swap(A[l], A[l + rand() % (u - l + 1)]);
        int i = l, j = u + 1;
        while (true) {
            do { i++; } while (i <= u && A[i] < A[l]);
            do { j--; } while (j >= l && A[j] > A[l]);
            if (i > j) break;
            swap(A[i], A[j]);
        }
        swap(A[l], A[j]);
        quickSortHelper(A, l, j - 1);
        quickSortHelper(A, j + 1, u);
    }

    void mergeSort(int A[], int n) {
        int * tmp = new int[n];
        mergeSortHelper(A, 0, n - 1, tmp);
        delete[] tmp;
    }

    void mergeSortHelper(int A[], int l, int u, int tmp[]) {
        if (l >= u) return;
        int m = l + (u - l) / 2;
        mergeSortHelper(A, l, m, tmp);
        mergeSortHelper(A, m + 1, u, tmp);
        for (int k = l; k <= u; k++) tmp[k] = A[k];
        int i = l, j = m + 1, k = l;
        while (i <= m || j <= u) A[k++] = (j > u || (i <= m && tmp[i] <= tmp[j])) ? tmp[i++] : tmp[j++];
    }

    void heapSort(int A[], int n) {
        for (int i = 2; i <= n; i++) {
            for (int j = i, p; (p = j / 2) > 0; j = p) {
                if (A[p - 1] >= A[j - 1]) break;
                swap(A[p - 1], A[j - 1]);
            }
        }
        for (int i = n; i >= 2; i--) {
            swap(A[0], A[i - 1]);
            for (int j = 1, c; (c = 2 * j) < i; j = c) {
                if (c + 1 < i && A[c] > A[c - 1]) c += 1;
                if (A[j - 1] > A[c - 1]) break;
                swap(A[j - 1], A[c - 1]);
            }
        }
    }

    void countingSort1(int A[], int n) {
        int tmp[3] = { 0 };
        for (int i = 0; i < n; i++) tmp[A[i]]++;
        int i = 0;
        for (int j = 0; j < 3; j++) while (tmp[j]--) A[i++] = j;
    }

    void countingSort2(int A[], int n) {
        int zero = -1, one = -1, two = -1;
        for (int i = 0; i < n; i++) {
            if (A[i] == 0) {
                A[++two] = 2;
                A[++one] = 1;
                A[++zero] = 0;
            }
            else if (A[i] == 1) {
                A[++two] = 2;
                A[++one] = 1;
            }
            else {
                A[++two] = 2;
            }
        }
    }
};

int main() {
    return 0;
}
