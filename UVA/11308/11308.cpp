#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int llu;
char title[100000], name[100000];

int main()
{
	llu t;
	scanf("%llu\n", &t);

	while(t--)
	{
		fgets(title, sizeof(title), stdin);

		llu m, n, b;
		scanf("%llu %llu %llu\n", &m, &n, &b);

		unordered_map <string, llu> price;
		price.reserve(int(1e5));
		
		llu val;
		char input[1000];
		while(m--)
			scanf("%s %llu\n", &input, &val), price[input] = val;

		map <llu, set<string> > binder;

		while(n--)
		{
			fgets(name, sizeof(name), stdin);

			llu k;
			scanf("%llu\n", &k);

			llu cost = 0;
			while(k--)
				scanf("%s %llu\n", input, &val), cost += val * price[input];

			if(cost <= b)
				binder[cost].insert(name);
		}

		transform(title, title + strlen(title), title, ::toupper);
		printf("%s", title);

		if(binder.size())
			for(auto &u : binder)
				for(auto &v : u.second)
					printf("%s", v.c_str());
		else
			printf("Too expensive!\n");
				
		printf("\n");
	}
	return 0;
}