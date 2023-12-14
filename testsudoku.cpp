#include <bits/stdc++.h>
using namespace std;

#define N 9

int sudokuGrid[N][N];
int solutionCount = 0;
vector<pair<int, int>> emptyCells;
int emptyCellCount;

bool isValid(int row, int col, int num) {
    for (int i = 0; i < N; ++i) {
        if (sudokuGrid[row][i] == num || sudokuGrid[i][col] == num) {
            return false;
        }
    }

    int startRow = row / 3 * 3;
    int startCol = col / 3 * 3;
    int endRow = startRow + 3;
    int endCol = startCol + 3;
    for (int i = startRow; i < endRow; ++i) {
        for (int j = startCol; j < endCol; ++j) {
            if (sudokuGrid[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

void solveSudoku(int cellIndex) {
    if (cellIndex == emptyCellCount) {
        ++solutionCount;
        return;
    }
    int row = emptyCells[cellIndex].first;
    int col = emptyCells[cellIndex].second;
    for (int num = 1; num <= N; ++num) {
        if (isValid(row, col, num)) {
            sudokuGrid[row][col] = num;
            solveSudoku(cellIndex + 1);
            sudokuGrid[row][col] = 0;
        }
    }
}

void readData() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int cellValue;
            cin >> cellValue;

            if (cellValue != 0) {
                sudokuGrid[i][j] = cellValue;
            } else {
                emptyCells.push_back({i,j});
            }
        }
    }
    emptyCellCount = emptyCells.size();
}

int main() {
    readData();
    solveSudoku(0);

    cout << solutionCount << endl;

    return 0;
}