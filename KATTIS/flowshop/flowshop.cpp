#include <bits/stdc++.h>
using namespace std;

int arr[1005][1005];
int n, m;

void input()
{
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			scanf("%d", &arr[i][j]);
}

void output(){for(int i=0;i<n;++i) printf(n-i-1? "%d " : "%d\n", arr[i][m-1]);}

void solve()
{
	for(int i=0;i<m;++i) arr[0][i] = i? arr[0][i-1] + arr[0][i] : arr[0][i];

	for(int j=0;j<m;++j)
		for(int i=1;i<n;++i)
			arr[i][j] += j? max(arr[i][j-1], arr[i-1][j]) : arr[i-1][j];
}

int main() 
{
	scanf("%d %d", &n, &m);
	input();
	solve();
	output();
	return 0;
}