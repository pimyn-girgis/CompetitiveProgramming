#include <bits/stdc++.h>
using namespace std;

#define printSet(n) puts(bitset<32>(n).to_string().c_str());

int main()
{
	int val;

	while (scanf("%d", &val) != EOF)
		printSet(val);

	return 0;
}

