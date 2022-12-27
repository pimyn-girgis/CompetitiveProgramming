/*
**************************************************************
* Author  : Bemen Girgis
* ID      : 900213066
* Contact : bemen@aucegypt.edu
**************************************************************
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;


//instead of dividing by cols I'll divide by rows, makes code easier

bool is_valid(int x, const matrix &mat)
{
    return x >= 0 && x < mat.size(); //make sure your element is within bounds
}

pii find_peak_element(const matrix &mat, int st, int en)
{
    int mid = (st + en) / 2; //middle row
    auto max_ind = max_element(mat[mid].begin(), mat[mid].end()) - mat[mid].begin(); //index for maximum value in row
    auto max_val = mat[mid][max_ind]; //value at max_ind

    if(is_valid(mid + 1, mat) && max_val < mat[mid + 1][max_ind]) //if the element below max is greater than it, minimize your search range to the bottom part
        return find_peak_element(mat, mid + 1, en);
    if(is_valid(mid - 1, mat) && max_val < mat[mid + -1][max_ind]) //if the element above max is greater than it, minimize your search range to the top part
        return find_peak_element(mat, st + 1, mid);

    return make_pair(mid, max_ind); //otherwise, you reached a peak
}

pii find_peak_element(const matrix &mat)
{
    return find_peak_element(mat, 0, mat.size() - 1);
}

int main()
{
    matrix mat = {{10, 20, 15},
                  {21, 20 ,14},
                  { 7, 16, 32}};
    auto ans = find_peak_element(mat);
    printf("%d %d\n", ans.first, ans.second);

    return 0;
}