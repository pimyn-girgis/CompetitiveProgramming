#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, n;
	scanf("%d", &t);
	string s;
	while(t--)
	{
		scanf("%d", &n);
		n = (n * 63 + 7492 )*5 - 498;
		s = to_string(n);
		printf("%c\n", s[s.size()-2]);
	}
	return 0;
}

