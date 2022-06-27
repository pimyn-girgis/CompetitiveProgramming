#include <bits/stdc++.h>
using namespace std;

short int board[30][30];
int ts, w, h, n, x, y, p[2];
char val[40];
bool one, two;

void fill(int num)
{
    p[num-1] = 0;
    for(int i = 0; i < h; ++i)
        {
            scanf("%s", val);
            for(int j = 0; j < w; ++j)
                if(val[j] == '#')
                {
                    board[i][j] += num;
                    ++p[num-1];
                }
        }
}

void solve()
{
    for(int i = 0; i < h; ++i)
        for(int j = 0; j < w; ++j)
            if(board[i][j] == 2)
                one = 0;
            else if(board[i][j] == 1)
                two = 0;
            else if(board[i][j] == 3)
                one = two = 0;
}
int main()
{
    scanf("%d", &ts);
    while(ts--)
    {
        memset(board, 0, sizeof(board));
        one = two = 1;
        scanf("%d %d %d", &w, &h, &n);
        fill(1); fill(2);
        bool turn = 0;
        while(n--)
        {
            scanf("%d %d", &x, &y);
            y = h - y - 1;
            if(turn && (board[y][x] == 1 || board[y][x] == 3)){--board[y][x]; --p[0]; turn = p[0];}
            else if(!turn && board[y][x] > 1){board[y][x] -= 2; --p[1]; turn = !p[1];}
            else turn = !turn;
        }
        solve();
        if(one && two || !one && !two)
            printf("draw\n");
        else
            printf("player %s wins\n", one? "one" : "two");
    }
    return 0;
}