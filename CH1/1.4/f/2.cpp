#include <bits/stdc++.h>
using namespace std;

int reduce(int x)
{
	int z = 0;
	while(x)
	{
		z += x%10;
		x /= 10;
	}
	if(z >= 10)
		 z = reduce(z);
	return z;
}
int num(string n1)
{
	int x = 0, z = 0;
	for(char c: n1)
		{
			if(isalpha(c))
			{
			if('a' <= c)
				c -= 96;
			else
				c -= 64;
			c = reduce(c);
			x += c;
			}
		}
	return reduce(x);
}

int main()
{
	string n1, n2;
	while(getline(cin, n1))
	{
		getline(cin, n2);
		printf("%.2f %c\n", 100*float(min(num(n1), num(n2)))/max(num(n1),num(n2)), '%');
	}
	return 0;
}

