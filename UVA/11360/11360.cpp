#include <bits/stdc++.h>
using namespace std;

int n;
int mat[11][11];

void row(int a, int b){swap(mat[a-1], mat[b-1]);}

void col(int a, int b)
{
	for(int i=0;i<n;++i)
		swap(mat[i][a-1], mat[i][b-1]);
}

void add(int val)
{
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			mat[i][j] = (mat[i][j] + val + 10)%10;
}

void trans()
{
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			swap(mat[i][j], mat[j][i]);
}

void eval(char move)
{
	int a, b;
	if(move == 'i') add(1);
	else if(move == 'd') add(-1);
	else if(move == 't') trans();
	else
	{
		scanf("%d %d", &a, &b);
		if(move == 'r') row(a, b);
		else col(a, b);
	}
}

void output(int test)
{
	printf("Case #%d\n", test);
	for(int i=0;i<n;++i, printf("\n"))
		for(int j=0;j<n;++j)
			printf("%d", mat[i][j]);
	printf("\n");
}

int main()
{
	char move[20], input[15];
	int ts, operations;
	scanf("%d", &ts);
	
	for(int test=1;test<=ts;++test)
	{
		scanf("%d", &n);
		for(int i=0;i<n;++i)
		{
			scanf("%s", input);
			for(int j=0;input[j];++j)
				mat[i][j] = input[j] - '0';
		}

		scanf("%d", &operations);
		while(operations--)
		{
			scanf("%s", move);
			eval(move[0]);
		}

		output(test);
	}
	return 0;
}

