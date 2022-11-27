/*
**************************************************************
* Author  : Bemen Girgis
* ID      : 900213066
* Contact : bemen@aucegypt.edu
**************************************************************
*/

#include <stdio.h>
#include <string.h>

int sudoku[9][9];

inline bool is_taken(int &val, int &taken) __attribute__((always_inline));
inline bool is_taken(int &val, int &taken)
{
    if(val && taken & (1 << val) )
        return true;

    taken |= (1 << val);
    return false;
}

bool is_col_valid(int col)
{
    int taken = 0;
    for(int i = 0; i < 9; ++i)
        if(is_taken(sudoku[i][col], taken))
            return false;
    
    return true;
}

bool is_row_valid(int row)
{
    int taken = 0;
    for(int i = 0; i < 9; ++i)
        if(is_taken(sudoku[row][i], taken))
            return false;

    return true;
}

bool is_box_valid(int row, int col)
{
    const int box_row = (row / 3) * 3;
    const int box_col = (col / 3) * 3;

    int taken = 0;
    for(int i = box_row; i < box_row + 3; ++i)
        for(int j = box_col; j < box_col + 3; ++j)
            if(is_taken(sudoku[i][j], taken))
                return false;
    
    return true;
}

bool is_valid(int row, int col) { return is_row_valid(row) && is_col_valid(col) && is_box_valid(row, col); }

bool solve(int row = 0, int col = 0)
{
    if(col == 9) ++row, col = 0;
    if(row == 9) return true;
    if(sudoku[row][col]) return solve(row, col + 1);

    int &cur = sudoku[row][col];
    for(cur = 1; cur <= 9; ++cur)
        if(is_valid(row, col) && solve(row, col + 1))
            return true;

    return sudoku[row][col] = 0;
}

void output_sudoku()
{
    for(int i = 0; i < 9; ++i)
    {
        if(!(i % 3)) printf(" -----------------------\n");

        for(int j = 0; j < 9; ++j)
        {
            if(!(j % 3)) printf("| ");
            printf("%d%s", sudoku[i][j], j == 9 - 1? " |\n" : " ");
        }

    }

    printf(" -----------------------\n");
}

int main()
{
    int temp[9][9] = 
    {
        {8, 0, 0,  0, 0, 0,  0, 0, 0},
        {0, 0, 3,  6, 0, 0,  0, 0, 0},
        {0, 7, 0,  0, 9, 0,  2, 0, 0},

        {0, 5, 0,  0, 0, 7,  0, 0, 0},
        {0, 0, 0,  0, 4, 5,  7, 0, 0},
        {0, 0, 0,  1, 0, 0,  0, 3, 0},

        {0, 0, 1,  0, 0, 0,  0, 6, 8},
        {0, 0, 8,  5, 0, 0,  0, 1, 0},
        {0, 9, 0,  0, 0, 0,  4, 0, 0}
    };
 
    for(int i = 0; i < 1000; ++i)
    {
        // memcpy(sudoku, temp, sizeof(sudoku));
        // solve();
    }

    return 0;
}