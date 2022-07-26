//https://open.kattis.com/problems/throwns
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	 int stack[105];
	 int top = -1;
	 char cmd[10];
	 int n, k, num, pos = 0;
	 scanf("%d %d", &n, &k);
	 while(k--)
	 {
	 	scanf("%s", cmd);
	 	if(cmd[0] == 'u')
	 	{
	 		scanf("%d", &num);
	 		while(num--)
	 			pos = (pos +  n - stack[top--]) % n;
	 	}
		else
		{
			num = atoi(cmd);
			num %= n;
			stack[++top] = num;
			pos = (pos + num + n) % n;
		}
	 }
	 printf("%d\n", pos);
	return 0;
}
