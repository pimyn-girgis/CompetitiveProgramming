#include <bits/stdc++.h>
using namespace std;

char in[10000];
string arr[100];
int ind = 0;
int maxLen;

void solve()
{
	for(int i=0;i<ind;++i) reverse(arr[i].begin(), arr[i].end());
	sort(begin(arr), begin(arr)+ind);
	for(int i=0;i<ind;++i) reverse(arr[i].begin(), arr[i].end());
	for(int i=0;i<ind;++i)
	{
		for(int j=arr[i].size();j<maxLen;++j) 
			printf(" ");
		printf("%s", arr[i].c_str());
	}
}

void init()
{
	maxLen = 0;
	ind = 0;
}

int main() 
{
	while(fgets(in, 10000, stdin))
	{
		if(*in == '\n') solve(), init(), printf("\n");
		else arr[ind++] = in;
		maxLen = max(int(strlen(in)), maxLen);
	}
	solve();
	return 0;
}
