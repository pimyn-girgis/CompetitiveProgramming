#include <bits/stdc++.h>
using namespace std;

vector <int> five(5);
int main() 
{
	int ans = 0;
	for(auto &u : five) scanf("%d", &u);
label:
	for(int i=0;i<4;++i)
	{
		if(five[i] > five[i+1])
		{
			swap(five[i], five[i+1]);
			for(int k=0;k<5;++k) printf(k? " %d" : "%d", five[k]);
			printf("\n");
		}
	}
	if(!is_sorted(five.begin(), five.end())) goto label;
	return 0;
}
