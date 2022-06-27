#include <bits/stdc++.h>
using namespace std;

int main()
{
	int cap, stations, left, entered, stay, count = 0;
	bool possible = 1;
	scanf("%d %d", &cap, &stations);
	while(stations--)
	{
		scanf("%d %d %d", &left, &entered, &stay);
		if(left > count)
			possible = 0;
		count += (entered - left);
		if(count > cap
		|| count < 0
		|| stay && count < cap)
			possible = 0;
	}
	if(count != 0)
		possible = 0;
	printf("%s", possible? "possible" : "impossible");
	return 0;
}

