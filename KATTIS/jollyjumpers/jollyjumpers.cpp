//https://open.kattis.com/problems/jollyjumpers
#include <bits/stdc++.h>
using namespace std;
 
int n, arr[3000];
bool val[3000];
 
void input(){for(int i=0;i<n;++i) scanf("%d", arr+i);}
void init()	{memset(val, 0, sizeof(val));}
bool jolly()
{
	for(int i=1;i<n;++i)
	{
		int dif = abs(arr[i-1] - arr[i]);
		val[dif-1] |= dif < n;
	}
	return !(find(val, val+n-1, 0) - (val+n-1));
}
 
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		init();
		input();
		printf("%s", jolly()? "Jolly\n" : "Not jolly\n");
	}
	return 0;
}