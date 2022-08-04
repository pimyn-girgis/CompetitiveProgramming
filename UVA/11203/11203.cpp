#include <bits/stdc++.h>
using namespace std;

char in[55];

int main()
{
	int tc;
	scanf("%d", &tc);

	while(tc--)
	{
		int len;
		scanf("%s%n", in, &len);

		int count[3] = {0};
		bool correct = 1;

		for(int i = 0, index = 0; in[i] && correct; ++i)
		{
			if(in[i] == 'M' || in[i] == 'E')
			{
				++index;
				correct = index <= 2;
			}
			else if(in[i] == '?')
				++count[index];
			else
				correct = 0;
		}
		correct = all_of(count, count + 3, [](int i){return i;}) && correct && (count[0] + count[1] == count[2]);
		printf("%s\n", correct? "theorem" : "no-theorem");
	}
	return 0;
}
