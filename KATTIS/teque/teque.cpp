//https://open.kattis.com/problems/teque
#include <bits/stdc++.h>
using namespace std;

deque <int> tequeBack;
deque <int> tequeFront;

void balance()
{
	while(tequeBack.size() < tequeFront.size() - 1)
		tequeBack.push_front(tequeFront.back()), tequeFront.pop_back();

	while(tequeBack.size() > tequeFront.size())
		tequeFront.push_back(tequeBack.front()), tequeBack.pop_front();
}

int main() 
{

	int n, val;
	char cmd[20], mv;

	scanf("%d", &n);
	while (n--)
	{
		scanf("%s %d", cmd, &val);
		mv = cmd[0];
		if(mv == 'g')
			printf("%d\n", val < tequeFront.size()? tequeFront[val] : tequeBack[val - tequeFront.size()]);
		else
		{
			mv = cmd[5];
			if(mv == 'b') tequeBack.push_back(val);
			else if(mv == 'f') tequeFront.push_front(val);
			else tequeFront.push_back(val);

			balance();
		}
	}
	
	return 0;
}
