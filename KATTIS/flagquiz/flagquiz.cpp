#include <bits/stdc++.h>
using namespace std;


string ans[105][105];
char in[5100];
int part = 0;
int n;
int Count[105];

void tokenize(int i)
{
	int k = -1;
	char *token = strtok(in, ",\n");
	while(token)
	{
		ans[i][++k] = token;
		token = strtok(0, ",\n");
		++part;
	}
}

void input()
{
	fgets(in, 1000, stdin);
	scanf("%d", &n);
	part = n;
	fflush(stdin);
	for(int i=0;i<n;++i)
	{
		fgets(in, 5100, stdin);
		tokenize(i);
	}
}

void solve()
{
	memset(Count, 0, sizeof(Count));
	part /= n;
	printf("%d", part);

	for(int j=0;j<part;++j)
		for(int i=0;i<n;++i)
			for(int k=0;k<n;++k)
					Count[i] += ans[i][j] == ans[k][j];
}

void output()
{
	int val = *max_element(Count, Count+n);
	for(int i=0;i<n;++i)
		if(Count[i] == val) 
			for(int j=0;j<part;++j)
				printf("%s%c%d", ans[i][j].c_str(), part-j-1? ',' : '\n', part-j-1);
}

int main() 
{
	input();
	solve();
	output();
	return 0;
}
