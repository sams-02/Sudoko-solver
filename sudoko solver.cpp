// Sudoku Solver in C++


#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// Check if it's safe to put num in mat[row][col]
bool isSafe(vector<vector<int>> &mat, int row, int col, int num) {
    for (int x = 0; x < 9; x++)
        if (mat[row][x] == num || mat[x][col] == num)
            return false;

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (mat[startRow + i][startCol + j] == num)
                return false;

    return true;
}

// Recursive function to solve Sudoku
bool solveSudokuRec(vector<vector<int>> &mat, int row, int col) {
    if (row == 8 && col == 9)
        return true;
    if (col == 9) {
        row++;
        col = 0;
    }
    if (mat[row][col] != 0)
        return solveSudokuRec(mat, row, col + 1);

    for (int num = 1; num <= 9; num++) {
        if (isSafe(mat, row, col, num)) {
            mat[row][col] = num;
            if (solveSudokuRec(mat, row, col + 1))
                return true;
            mat[row][col] = 0;
        }
    }
    return false;
}

void solveSudoku(vector<vector<int>> &mat) {
    solveSudokuRec(mat, 0, 0);
}

int main() {
    vector<vector<vector<int>>> puzzles = {
        {
            {3, 0, 6, 5, 0, 8, 4, 0, 0},
            {5, 2, 0, 0, 0, 0, 0, 0, 0},
            {0, 8, 7, 0, 0, 0, 0, 3, 1},
            {0, 0, 3, 0, 1, 0, 0, 8, 0},
            {9, 0, 0, 8, 6, 3, 0, 0, 5},
            {0, 5, 0, 0, 9, 0, 6, 0, 0},
            {1, 3, 0, 0, 0, 0, 2, 5, 0},
            {0, 0, 0, 0, 0, 0, 0, 7, 4},
            {0, 0, 5, 2, 0, 6, 3, 0, 0}
        },
        {
            {0, 0, 0, 2, 6, 0, 7, 0, 1},
            {6, 8, 0, 0, 7, 0, 0, 9, 0},
            {1, 9, 0, 0, 0, 4, 5, 0, 0},
            {8, 2, 0, 1, 0, 0, 0, 4, 0},
            {0, 0, 4, 6, 0, 2, 9, 0, 0},
            {0, 5, 0, 0, 0, 3, 0, 2, 8},
            {0, 0, 9, 3, 0, 0, 0, 7, 4},
            {0, 4, 0, 0, 5, 0, 0, 3, 6},
            {7, 0, 3, 0, 1, 8, 0, 0, 0}
        },
        {
            {0, 2, 0, 6, 0, 8, 0, 0, 0},
            {5, 8, 0, 0, 0, 9, 7, 0, 0},
            {0, 0, 0, 0, 4, 0, 0, 0, 0},
            {3, 7, 0, 0, 0, 0, 5, 0, 0},
            {6, 0, 0, 0, 0, 0, 0, 0, 4},
            {0, 0, 8, 0, 0, 0, 0, 1, 3},
            {0, 0, 0, 0, 2, 0, 0, 0, 0},
            {0, 0, 9, 8, 0, 0, 0, 3, 6},
            {0, 0, 0, 3, 0, 6, 0, 9, 0}
        },
        {
            {0, 0, 0, 0, 0, 0, 2, 0, 0},
            {0, 8, 0, 0, 0, 7, 0, 9, 0},
            {6, 0, 2, 0, 0, 0, 5, 0, 0},
            {0, 7, 0, 0, 6, 0, 0, 0, 0},
            {0, 0, 0, 9, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 2, 0, 0, 4, 0},
            {0, 0, 5, 0, 0, 0, 6, 0, 3},
            {0, 9, 0, 4, 0, 0, 0, 7, 0},
            {0, 0, 6, 0, 0, 0, 0, 0, 0}
        },
        {
            {1, 0, 0, 4, 8, 9, 0, 0, 6},
            {7, 3, 0, 0, 0, 0, 0, 4, 0},
            {0, 0, 0, 0, 0, 1, 2, 9, 5},
            {0, 0, 7, 1, 2, 0, 6, 0, 0},
            {5, 0, 0, 7, 0, 3, 0, 0, 8},
            {0, 0, 6, 0, 9, 5, 7, 0, 0},
            {9, 1, 4, 6, 0, 0, 0, 0, 0},
            {0, 2, 0, 0, 0, 0, 0, 3, 7},
            {8, 0, 0, 5, 1, 2, 0, 0, 4}
        }
    };

    cout << "Welcome to Sudoku Solver!\n";
    cout << "Do you want to (1) solve a default puzzle or (2) create a new one? Enter 1 or 2: ";
    int mode;
    cin >> mode;

    vector<vector<int>> mat(9, vector<int>(9, 0));
    if (mode == 1) {
        cout << "Choose a Sudoku puzzle to solve (1-5):\n";
        for (int k = 0; k < puzzles.size(); ++k) {
            cout << "Puzzle " << k + 1 << ":\n";
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j)
                    cout << puzzles[k][i][j] << " ";
                cout << endl;
            }
            cout << endl;
        }
        int choice;
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        if (choice < 1 || choice > 5) {
            cout << "Invalid choice." << endl;
            return 1;
        }
        mat = puzzles[choice - 1];
        solveSudoku(mat);
        cout << "\nSolved Sudoku:\n";
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat.size(); j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    } else if (mode == 2) {
        cout << "Enter your Sudoku puzzle row by row (9 numbers per row, separated by spaces, use 0 for empty cells):\n";
        bool valid = true;
        for (int i = 0; i < 9; ++i) {
            string line;
            getline(cin >> ws, line); // ws to skip any leading whitespace
            stringstream ss(line);
            int val, count = 0;
            while (ss >> val) {
                if (val < 0 || val > 9) valid = false;
                if (count < 9) mat[i][count] = val;
                count++;
            }
            if (count != 9) valid = false;
        }
        if (!valid) {
            cout << "Invalid Sudoku puzzle! Please enter exactly 9 numbers (0-9) per row.\n";
            return 1;
        }
        char solveNow;
        cout << "Do you want to solve this puzzle now? (y/n): ";
        cin >> solveNow;
        if (solveNow == 'y' || solveNow == 'Y') {
            solveSudoku(mat);
            cout << "\nSolved Sudoku:\n";
            for (int i = 0; i < mat.size(); i++) {
                for (int j = 0; j < mat.size(); j++)
                    cout << mat[i][j] << " ";
                cout << endl;
            }
        } else {
            cout << "Puzzle creation finished. Exiting.\n";
        }
    } else {
        cout << "Invalid option.\n";
        return 1;
    }

    cout << "\nThanks for using the Sudoku Solver!\n";
    return 0;
}
