#include <bits/stdc++.h>
using namespace std;

unordered_set<string> temp;
unordered_map<string, int> pos;
char word[10];
int ind = 0;

void init(int len, string str, char k)
{
	if(!len && temp.insert(str).second)
		pos.insert(make_pair(str, ++ind));

	for(int i = 0; i < len; ++i)
		for(char c = k + 1; c <= 'z'; ++c)
			init(len - 1, str + c, c);
}

int main()
{
	pos.reserve(180000);
	temp.reserve(int(1e7));
	for(int i = 1; i <= 5; ++i)
		init(i, "", 'a' - 1);

	while(scanf("%s", word) != EOF)
		printf("%d\n", pos[string(word)]);

	return 0;
}
