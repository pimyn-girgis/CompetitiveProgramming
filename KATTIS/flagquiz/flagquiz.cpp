#include <bits/stdc++.h>
using namespace std;


string ans[105][105];
char in[5100];
int part = 0;
int n;
int Count[105][105];
int val[105];

void tokenize(int i)
{
	int k = -1;
	char *token = strtok(in, ",\n");
	while(token)
	{
		if(!i) ++part;
		ans[i][++k] = token;
		token = strtok(0, ",\n");
	}
}

void input()
{
	fgets(in, 1000, stdin);
	scanf("%d", &n);
	getchar();
	for(int i=0;i<n;++i)
	{
		fgets(in, 5100, stdin);
		tokenize(i);
	}
}

void solve()
{
	memset(Count, 0, sizeof(Count));
	for(int i=0;i<n;++i)
		for(int k=0;k<n;++k)
			for(int j=0;j<part;++j)
				Count[i][k] += (ans[i][j] != ans[k][j]);
	for(int i=0;i<n;++i)
		val[i] = *max_element(Count[i], Count[i]+n);
}

void output()
{
	int mini = *min_element(val, val+n);
	for(int i=0;i<n;++i)
		if(mini == val[i]) 
			for(int j=0;j<part;++j)
				printf("%s%c", ans[i][j].c_str(), part-j-1? ',' : '\n');
}

int main() 
{
	input();
	solve();
	output();
	return 0;
}
