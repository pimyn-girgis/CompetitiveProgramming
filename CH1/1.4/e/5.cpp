#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x, y, n;
	scanf("%d%d%d", &x, &y, &n);
	for(int i = 1; i <= n;++i)
		if(!(i%x) && !(i%y))
			printf("FizzBuzz\n");
		else if(!(i%x))
			printf("Fizz\n");
		else if(!(i%y))
			printf("Buzz\n");
		else
			printf("%d\n", i);
	return 0;
}

