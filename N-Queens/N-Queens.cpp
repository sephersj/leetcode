//============================================================================
// N-Queens
//
// The n-queens puzzle is the problem of placing n queens on an n×n chessboard
// such that no two queens attack each other.
//
// Complexity:
// O(n^(n+2)) time
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        return solveNQueens2(n);
    }

    vector<vector<string> > solveNQueens1(int n) {
        vector<int> board(n, -1);
        vector<vector<string> > res;
        solveNQueensHelper1(board, 0, res);
        return res;
    }

    void solveNQueensHelper1(vector<int> & board, int row, vector<vector<string> > & res) {
        int N = board.size();
        if (row == N) {
            vector<string> path(N, string(N, '.'));
            for (int r = 0; r < N; r++) path[r][board[r]] = 'Q';
            res.push_back(path);
            return;
        }
        for (int col = 0; col < N; col++) {
            if (!isValid(board, row, col)) continue;
            board[row] = col;
            solveNQueensHelper1(board, row + 1, res);
        }
    }

    bool isValid(vector<int> & board, int row, int col) {
        for (int r = 0; r < row; r++) if (board[r] == col || abs(board[r] - col) == row - r) return false;
        return true;
    }

    vector<vector<string> > solveNQueens2(int n) {
        vector<int> board(n, -1);
        vector<vector<string> > res;
        solveNQueensHelper2(board, 0, 0, 0, 0, res);
        return res;
    }

    void solveNQueensHelper2(vector<int> & board, int row, int cur, int ld, int rd, vector<vector<string> > & res) {
        int N = board.size();
        int mask = (1 << N) - 1;
        if (cur == mask) {
            vector<string> sub(N, string(N, '.'));
            for (int r = 0; r < N; r++) {
                for (int c = 0; c < N; c++) {
                    if (board[r] & (1 << c)) sub[r][c] = 'Q';
                }
            }
            res.push_back(sub);
            return;
        }

        int cs = ~(cur | ld | rd) & mask;
        while (cs > 0) {
            int p = cs & -cs;
            cs -= p;
            board[row] = p;
            solveNQueensHelper2(board, row + 1, cur | p, (ld | p) << 1, (rd | p) >> 1, res);
        }
    }
};

int main() {
    Solution sol;
    int p0;

    {
        p0 = 4;
        auto p1 = sol.solveNQueens(p0);
        for (auto it1 : p1) {
            for (auto it2 : it1) cout << it2 << endl;
            cout << endl;
        }
    }

    return 0;
}