#include <bits/stdc++.h>
using namespace std;

bool solve_the_sudoku(vector<vector<int>> &sudoku);
bool isSafe(int row, int col, int val, vector<vector<int>> &sudoku);

int main()
{
    cout << "Lets start playing\t <-- Be remember if what to enter a empty number enter number 0 -->" << endl
         << endl;
    cout << "start entering the number" << endl;

    int element = 1;
    vector<vector<int>> sudoku(9, vector<int>(9));

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << "Enter element number " << element << " ";
            cin >> sudoku[i][j];
            element++;
        }
    }

    bool ans = solve_the_sudoku(sudoku);
    cout << endl
         << endl;

    if (ans)
    {
        cout << "\t\tYOUR DESIRED RESULT\t\t\n";

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << sudoku[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "\tTHERE IS NO POSSIBLE SOLUTION FOR SUDOKU\t\n";
    }

    return 0;
}
bool solve_the_sudoku(vector<vector<int>> &sudoku)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (sudoku[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(row, col, val, sudoku))
                    {
                        sudoku[row][col] = val;

                        bool if_valid_choice = solve_the_sudoku(sudoku);

                        if (if_valid_choice)
                        {
                            return true;
                        }
                        else
                        {
                            sudoku[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
bool isSafe(int row, int col, int val, vector<vector<int>> &sudoku)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[row][i] == val)
        {
            return false;
        }
        if (sudoku[i][col] == val)
        {
            return false;
        }
        if (sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }
    return true;
}
