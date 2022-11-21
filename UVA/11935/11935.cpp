/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : ##### UVA
* Link    : https://onlinejudge.org/external/###/p#####.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

char input[100];
int main()
{
	int distance, consumption, current_gas = 0;
	while(scanf("%d ", &distance) != EOF)
	{
		const char fc[] = "Fuel consumption";
		fgets(input, sizeof(input), stdin);

		if(input[0] == 'F')
			consumption = atoi(input + sizeof(fc)), printf("%d\n", consumption);
	}
	
	return 0;
}
