#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, ans = 0, num = 0; char str [6], a;
	map<char, int> m;
	while(1)
	{
		scanf("%d", &n);
		if(n < 0)
			break;
		scanf(" %c%s", &a, str);
		m.insert(pair<char, int>(a, 0));
		if(!strcmp("right", str) && m[a] != -1)
		{
			ans += (n + 20 * m[a]);
			++num;
			m[a] = -1;
		}
		else
			++m[a];
	}
	printf("%d %d", num, ans);
	return 0;
}

