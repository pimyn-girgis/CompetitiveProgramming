#include <bits/stdc++.h>
using namespace std;

#define birth tuple<int, int, int, string>
int main()
{
	birth young = make_tuple(0, 0, 0, string(" "));
	birth old = make_tuple(1e9, 1e9, 1e9, string(" "));
	birth input = make_tuple(0, 0, 0, string(" "));;
	char in[20];

	int n;
	scanf("%d", &n);
	for(int i=0;i<n;++i)
	{
		scanf("%s %d %d %d", in, &get<2>(input), &get<1>(input), &get<0>(input));
		get<3>(input) = in;
		old = min(old , input);
		young = max(young , input);
	}
	printf("%s\n%s\n", get<3>(young).c_str(), get<3>(old).c_str());
	return 0;
}



