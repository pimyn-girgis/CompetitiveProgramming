//https://open.kattis.com/problems/bungeebuilder
#include <bits/stdc++.h>
using namespace std;

#define MAX int(1e6 + 5)

int height[MAX];

int main() 
{
	int n;
	scanf("%d", &n);
	for(int i = 0;i < n;++i)
		scanf("%d", height+i);
	return 0;
}
