/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* problem : 
**************************************************************
*/
 
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int g[] = {1, 2};
	int g_size = sizeof(g) / sizeof(int);
	int s[] = {1, 2, 3};
	int s_size = sizeof(s) / sizeof(int); 

	sort(s, s + s_size);
	sort(g, g + g_size);

	int i, j;
	for(i = 0, j = 0; i < s_size && j < g_size; ++j)
		if(g[i] <= s[j])
			++i;
	
	printf("%d\n", i);

    return 0;
}
