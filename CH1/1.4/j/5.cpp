#include <bits/stdc++.h>
using namespace std;

int main()
{
	char com [6][4] = {"RBL", "RLB", "BRL", "BLR", "LRB", "LBR"};
	char arr[1000009];
	char three[4];
	scanf("%s", arr);
	for(int i = 0; arr[i] ; ++i)
	{
label:
		for(int k = 0; k < 3; ++k)
			three[k] = arr[i+k];
		for(int j = 0; j < 6; ++j)
			if(!strcmp(com[j], three))
			{
				printf("C");
				i += 3;
				goto label;
			}

		if(arr[i] == 'R')
			printf("S");
		else if(arr[i] == 'B')
			printf("K");
		else if(arr[i] == 'L')
			printf("H");
	}
	return 0;
}

