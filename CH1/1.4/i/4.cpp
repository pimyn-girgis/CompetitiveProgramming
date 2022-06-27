#include <bits/stdc++.h>
using namespace std;

int t;
int in[10010], l[10010] , r[10010] , sum, val;
char s[10010];
bool up;

void prep(int x)
{
	l[0] = s[0] == '\\' ? in[0] : -1e9;
	r[x - 1] = s[x-1] == '/' ? in[x-1]: -1e9; 
	for(int i = 1; s[i] ; ++i)
		l[i] = s[i] == '\\'? max(in[i], l[i-1]) : l[i-1];
	for(int i = x-1; i ; --i)
		r[i-1] = s[i-1] == '/'? max(in[i-1], r[i]) : r[i];
}
int main()
{
	scanf("%d", &t);
	while(t--)
	{
	sum = 0;
	scanf("%s", s);
	in[0] = 0;
	up = s[0] == '/';
	for(int i = 1; s[i] ; ++i)
	{
		if(s[i] == '\\')
		{
			in[i] = !up? in[i-1] - 1 : in[i-1];
			up = 0;
		}
		else if(s[i] == '/')
		{
			in[i] = up && s[i-1] != '_'? in[i-1] + 1 : in[i-1];
			up = 1;
		}
		else if(s[i] == '_')
		{
			in[i] = up? in[i-1] + 1 : in[i-1];
			up = 0;
		}
	}
	prep(strlen(s));
	for(int i = 0; s[i] ; ++i)
	{
		val = min(l[i], r[i]);
		if(val >= in[i])
		{
			if(s[i] == '_')
				sum += 2 * (val - in[i] + 1);
			else
				sum += 2 * (val - in[i] + 0.5);
		}
	}
	printf("%d\n", sum/2);
	}
	return 0;
}

