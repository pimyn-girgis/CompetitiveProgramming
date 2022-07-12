#include <bits/stdc++.h>
using namespace std;

int r, c;
char arr[20][20];
char arrCopy[20][20];

bool comp(char a[], char b[])
{
	for(int i=0;i<r;++i)
		if(tolower(a[i]) < tolower(b[i]))
			return 1;
		else if(tolower(a[i]) > tolower(b[i]))
			return 0;
	return 0;
}

void solve()
{
	for(int i=0;i<r;++i)
		for(int j=0;j<c;++j)
			arrCopy[j][i] = arr[i][j], arrCopy[j][i+1] = 0;

	char *in[20];
	for(int i=0;i<c;++i)
		in[i] = arrCopy[i];

	stable_sort(in, in+c , comp);

	for(int i=0;i<r;++i, printf("\n"))
		for(int j=0;j<c;++j)
			printf("%c", in[j][i]);
}

int main()
{
	bool first = 1;
	while (scanf("%d %d", &r, &c) && (r || c))
	{
		if(!first) printf("\n"); else first = 0;
		for(int i=0;i<r;++i) scanf("%s", arr[i]);
		solve();
	}
	
	return 0;
}