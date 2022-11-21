/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 10935 UVA
* Link    : https://onlinejudge.org/external/109/p10935.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

int main()
{
		int n;

	while(scanf("%d", &n), n)
	{
		if(n == 1)
		{
			printf("Discarded cards:\nRemaining card: 1\n");;
			continue;
		}

		printf("Discarded cards: ");
		deque<int> deck;
		for(int i = 1; i <= n; ++i)
			deck.push_front(i);

		while(deck.size() != 2)
		{
			printf("%d, ", deck.back());
			deck.pop_back();
			deck.push_front(deck.back());
			deck.pop_back();
		}

		printf("%d\nRemaining card: %d\n", deck.back(), deck.front());
	}

	return 0;
}
