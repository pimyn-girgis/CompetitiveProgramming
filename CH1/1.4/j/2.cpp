#include <bits/stdc++.h>
using namespace std;

int main()
{
	int l;
	bool plus;
	char cur, s[5];

	while(scanf("%d", &l))
	{
		if(!l)
			return 0;
		cur = 'x';
		plus = 1;
		while(--l)
		{
			scanf("%s", s);
			if(s[1] == 'o')
				continue;
			if((s[0] == '-' && cur == 'x') ||(cur == s[1] && s[0] == '+'))
				plus = !plus;
			if(cur == 'x')
				cur = s[1];
			else if(s[1] == cur)
				cur = 'x';
		}
		printf("%c%c\n", plus? '+' : '-', cur);
	}
	return 0;
}

