#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x = 3;
	int &y = x;
	y++;
	printf("%d %d", x, y);
	return 0;
}

