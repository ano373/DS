#include <iostream>
#include <vector>

using namespace std;

const int N = 8;  // number of queens and size of the chessboard

// function to check if a queen can be placed at position (row, col)
bool isValid(vector<int>& queens, int row, int col)
{
    // check if a queen is placed on the same column or diagonal
    for (int r = 0; r < row; r++)
        if (queens[r] == col || queens[r] - r == col - row || queens[r] + r == col + row)
            return false;

    return true;
}

// function to solve the n-queens problem
bool solve(vector<int>& queens, int row)
{
    // base case: all queens are placed
    if (row == N)
        return true;

    // try to place a queen in each column of the current row
    for (int col = 0; col < N; col++)
    {
        // check if it is safe to place a queen at position (row, col)
        if (isValid(queens, row, col))
        {
            // place a queen at position (row, col) and move to the next row
            queens[row] = col;
            if (solve(queens, row + 1))
                return true;
        }
    }

    // backtrack: remove the queen from position (row, col) and try other columns
    queens[row] = -1;
    return false;
}

int main()
{
    // vector to store the positions of the queens
    vector<int> queens(N, -1);

    // solve the n-queens problem
    if (solve(queens, 0))
    {
        // print the positions of the queens
        for (int i = 0; i < N; i++)
            cout << queens[i] << " ";
        cout << endl;
    }
   
