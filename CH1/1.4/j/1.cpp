#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, t; long long int sum = 0;
	scanf("%d%d", &n, &t);
	int *v = new int [n];
	bool *yes = new bool [n];
	for(int i = 0; i < n; ++i)
		scanf("%d", &v[i]);
	if(t==1)
		printf("7");
	else if(t==2)
	{
		if(v[0] > v[1])
			printf("Bigger");
		else if(v[0] == v[1])
			printf("Equal");
		else
			printf("Smaller");
	}
	else if(t==3)
	{
		sort(&v[0], &v[3]);
		printf("%d", v[1]);
	}
	else if(t==4)
	{
		for(int i = 0; i < n; ++i)
			sum += v[i];
		printf("%lld", sum);
	}
	else if(t==5)
	{
		for(int i = 0; i < n; ++i)
			sum += v[i]%2? 0 : v[i];
		printf("%lld", sum);
	}
	else if(t==6)
	{
		for(int i = 0; i < n; ++i)
		{
			v[i] %= 26;
			printf("%c", char(v[i] + 97));
		}
	}
	else if(t==7)
	{
		int i = 0;
		do
		{
			yes[i] = true;
			i = v[i];
		}while(i < n - 1 && !yes[i]);
		if(i == n - 1)
			printf("Done");
		else if(i >= n)
			printf("Out");
		else if(yes[i])
			printf("Cyclic");
	}
	return 0;
}

