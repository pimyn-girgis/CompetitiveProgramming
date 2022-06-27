#include <bits/stdc++.h>
using namespace std;

int top;

int main()
{
	int t, sum;
	char str[10005];
	scanf("%d", &t);
	while(t--)
	{
		stack <int> s;
		sum = 0;
		scanf("%s", str);
		for(int i = 0; str[i]; ++i)
		{
			if(str[i] == '\\')
				s.push(i);
			else if(str[i] == '/' && !s.empty())
			{
				sum += i - s.top();
				s.pop();
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}

