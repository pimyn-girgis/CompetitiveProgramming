#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	swap(a[0], a[2]);
	swap(b[0], b[2]);
	printf("%s", max(a,b).c_str());
	return 0;
}

