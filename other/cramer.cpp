/*
**************************************************************
* Author  : Bemen Girgis
* ID      : 900213066
* Contact : bemen@aucegypt.edu
* problem : Cramer's Rule
**************************************************************
*/
 
#include <stdio.h>
#include <vector>
using std::vector;

typedef long double lf;
typedef vector<lf> vf;
typedef vector<vf> matrix;

vf solve_system(matrix &system, vf &const_column)
{
    vf var_column(const_column.size());
    return var_column;
}

int main()
{
    int n;
    scanf("%d", &n);

    matrix system(n, vf(n));
    vf const_column(n);

    lf val;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j <= n; ++j)
            {
                scanf("%LF", &val);
                j == n? const_column[i] = val : system[i][j] = val;
            }
    
    vf ans = solve_system(system, const_column);

    for(int i = 0; i < ans.size(); ++i)
        printf("%d%c", ans[i], i == n - 1? '\n' : ' ');

    return 0;
}