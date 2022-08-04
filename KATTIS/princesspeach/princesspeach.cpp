//https://open.kattis.com/problems/princesspeach
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	bool found[105] = {0};

	int n, y;
	scanf("%d %d", &n, &y);

	int val;
	while(y--)
		scanf("%d", &val), found[val] = 1;

	int missed = 0;
	for(int i = 0; i < n; ++i)
		if(!found[i]) ++missed, printf("%d\n", i);

	printf("Mario got %d of the dangerous obstacles.\n", n - missed);

	return 0;
}
