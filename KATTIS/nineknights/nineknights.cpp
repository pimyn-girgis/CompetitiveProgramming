#include <bits/stdc++.h>
using namespace std;

int x[8] = {-1, -1, 1, 1, -2, -2, 2, 2};
int y[8] = {2, -2, 2, -2, 1, -1, -1, 1};
bool board[6][6];

bool valid(int x){return x < 5 && x >= 0;}
bool valid(int x, int y){return valid(x) && valid(y);}

bool solve()
{
	for(int i=0;i<5;++i)	
		for(int j=0;j<5;++j)
			if(board[i][j])
				for(int k=0;k<8;++k)	
					if(valid(i+x[k], j+y[k]) && board[i+x[k]][j+y[k]])
						return 0;
	return 1;
}

int main() 
{
	char in;
	int val = 0;
	for(int i=0;i<5;++i)
		for(int j=0;j<6;++j)
		{
			scanf("%c", &in);
			val += board[i][j] = in == 'k';
		}
	printf("%s", solve() && val == 9? "valid\n" : "invalid\n");
	return 0;
}
