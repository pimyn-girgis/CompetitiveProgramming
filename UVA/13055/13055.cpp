#include <bits/stdc++.h>
using namespace std;

stack <string> dream;

int main()
{
	char move[10], name[20];
	int n;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", move);
		char mv = move[0];
		if(mv == 'S')
			scanf("%s", name), dream.push(name);
		else if(mv == 'K' && dream.size())
			dream.pop();
		else if(mv == 'T')
			printf("%s\n", dream.size()? dream.top().c_str() : "Not in a dream");
	}
	return 0;
}
