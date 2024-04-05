#include <iostream>
#include <vector>
using namespace std;

void printDiagonal(const vector<vector<int>>& vals, int row, int col) {
    int numRows = vals.size();
    if (numRows == 0) return; // Check for empty input

    while (row >= 0 && col < vals[row].size()) {
        cout << vals[row][col] << " ";
        // Move to the next element in the diagonal
        row--;
        col++;
    }
    cout << endl;
}

int main() {
    vector<vector<int>> vals = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    // Example: Start from the lower-left corner
    printDiagonal(vals, 3, 0); // Starting from row 3, col 0


    return 0;
}
