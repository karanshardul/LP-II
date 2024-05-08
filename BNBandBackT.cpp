#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

bool isSafe(const vector<int>& board, int row, int col) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(i - row) == abs(board[i] - col)) {
            return false;
        }
    }
    return true;
}

void printBoard(const vector<int>& board) {
    int n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Backtracking method to solve N-Queens problem
bool solveNQueensBacktracking(vector<int>& board, int row) {
    int n = board.size();
    if (row == n) {
        printBoard(board);
        return true;
    }
    bool res = false;
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            res = solveNQueensBacktracking(board, row + 1) || res;
            board[row] = -1; // backtrack
        }
    }
    return res;
}

// Branch and Bound method to solve N-Queens problem
bool solveNQueensBranchAndBound(vector<int>& board, int row) {
    int n = board.size();
    if (row == n) {
        printBoard(board);
        return true;
    }
    bool res = false;
    // Heuristic: Try columns with fewer conflicts first
    vector<pair<int, int>> colConflicts; // Store column indices and their conflict counts
    for (int col = 0; col < n; col++) {
        int conflicts = 0;
        for (int i = 0; i < row; i++) {
            if (isSafe(board, row, col)) {
                conflicts++;
            }
        }
        colConflicts.push_back({col, conflicts});
    }
    // Sort columns based on conflicts (ascending order)
    sort(colConflicts.begin(), colConflicts.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    // Try columns with fewer conflicts first
    for (const auto& colConflict : colConflicts) {
        int col = colConflict.first;
        if (isSafe(board, row, col)) {
            board[row] = col;
            res = solveNQueensBranchAndBound(board, row + 1) || res;
            board[row] = -1; // backtrack
        }
    }
    return res;
}


int main() {
    int n;
    cout << "Enter the size of the chessboard: ";
    cin >> n;

    vector<int> board(n, -1);

    cout << "Solving using Backtracking:" << endl;
    if (!solveNQueensBacktracking(board, 0)) {
        cout << "No solution found." << endl;
    }

    cout << "Solving using Branch and Bound:" << endl;
    if (!solveNQueensBranchAndBound(board, 0)) {
        cout << "No solution found." << endl;
    }

    return 0;
}
