#include <bits/stdc++.h>
using namespace std;

int main()
{
	int ts, m, n;
	char piece;
	scanf("%d", &ts);
	while(ts--)
	{
		scanf(" %c%d%d", &piece, &m, &n);
		if(piece == 'r' || piece == 'Q')
			printf("%d\n", min(m, n));
		else if(piece == 'k')
			printf("%d\n", m*n/2);
		else
			printf("%d\n", ((m+1)/2) * ((n+1)/2));
			//pay attention to integer division in
			//last line. (m+1)*(n+1)/4 would have 
			//resulted in a WA.
	}
	return 0;
}
