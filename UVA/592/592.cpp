/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 592 UVA
* Link    : https://onlinejudge.org/external/5/592.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

int main()
{
	int n;
	int statements[50];
	int caseNo = 1;
	char input[100];

	while (scanf("%d\n", &n), n)
	{

		for(int i = 0; i < n; ++i)
		{
			fgets(input, sizeof(input), stdin);

			statements[0] = input[0];
		}

		printf("Conversation #%d\n", caseNo);
	}
	
	return 0;
}
