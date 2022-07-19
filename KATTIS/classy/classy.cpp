#include <bits/stdc++.h>
using namespace std;

map<long long int, vector<string> >leader;
char name[35];
char str[100];
int Count;

void solve()
{
	int k = 0;
	int val;
	long long int ans = 0;
	char *token = strtok(str, "-");
	do
	{
		char fir = token[0];

		if(fir == 'u') val = 3;
		else if(fir == 'm') val = 2;
		else val = 1;

		ans += val *(pow(10, k++));

		token = strtok(0, "-");
	} while (token);

	while(ans < 1e9)
	{
		ans *= 10;
		ans += 2;
	}
	leader[ans].push_back(name);
}

int main() 
{
	int tc, len;
	scanf("%d", &tc);
	while(tc--)
	{
		leader.clear();
		scanf("%d", &Count);
		for(int i=0;i<Count;++i)
		{
			scanf("%s%n %s class", name, &len, str);
			name[len-2] = 0;
			solve();
		}
		for(auto u = leader.rbegin(); u != leader.rend(); ++u)
		{
			sort(u->second.begin(), u->second.end());

			for(auto n : u->second)
				printf("%s\n", n.c_str());
		}
		for(int i=0;i<30;++i) printf("=");
		printf("\n");
	}
	return 0;
}
