#include <bits/stdc++.h>
using namespace std;

int main()
{
	string ans; int n, m;
	while(cin >> ans)
	{
		if(ans == "END")
			return 0;
		m = 2;
		n = ans.size();
		if(n == 1&& stoi(ans) == 1)
			m = 1;
		while(n > 1)
		{
			m++;
			n = log10(n) + 1;
		}
		printf("%d\n", m);
	}
	return 0;
}
