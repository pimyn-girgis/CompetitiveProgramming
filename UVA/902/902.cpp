#include <bits/stdc++.h>
using namespace std;

#define MAX int(1e5 + 5)

string input;

int main()
{
	cin.tie(NULL);
	int n;
	while(cin >> n >> input)
	{
		unordered_map <string, int> freq;
		int maxVal = 0;
		string password;

		for(int i = 0;i + n - 1 < input.size(); ++i)
		{
			string str = string(input, i, n);
			auto val = ++freq[str];
			if(maxVal < val) maxVal = val, password = str; 
		}
		printf("%s\n", password.c_str());
	}

	return 0;
}
