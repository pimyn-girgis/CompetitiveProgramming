#include <bits/stdc++.h>
using namespace std;

bool comp(char *a, char *b)
{
	for(int i=0;i<2;++i)
		if(a[i] < b[i])
			return 1;
		else if(a[i] > b[i])
			return 0;
	return 0;
}

char arr[205][25];
char *in[205];

int main() 
{
	int num;
	bool first = 1;
	while(scanf("%d", &num) && num)
	{
		if(!first)printf("\n"); else first = 0;
		for(int i=0;i<num;++i) scanf("%s", arr[i]);
		for(int i=0;i<num;++i) in[i] = arr[i];
		stable_sort(in, in+num, comp);
		for(int i=0;i<num;++i) printf("%s\n", in[i]);
	}
	return 0;
}
