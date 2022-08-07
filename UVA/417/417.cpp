#include <bits/stdc++.h>
using namespace std;

unordered_set<string> temp;
unordered_map<string, int> pos;
auto it = pos.begin();

int ind = 0;
void init(int len, string str, char k)
{
	if(!len && temp.insert(str).second)
		pos.insert(make_pair(str, ++ind));

	for(int i = 0; i < len; ++i)
		for(char c = k + 1; c <= 'z'; ++c)
			init(len - 1, str + c, c);
}

char word[10];

int main()
{
	for(int i = 1; i <= 5; ++i)
		init(i, "", 'a' - 1);

	while(scanf("%s", word) != EOF)
		printf("%d\n", pos[string(word)]);

	return 0;
}
