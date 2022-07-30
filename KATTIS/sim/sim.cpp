//https://open.kattis.com/problems/PROBLEM_NAME
#include <bits/stdc++.h>
using namespace std;

#define MAX int(1e6 + 5)
char in[MAX];

int main() 
{
	int tc;
	scanf("%d ", &tc);

	while(tc--)
	{
		list <char> out;
		auto it = out.begin();
		fgets(in, MAX, stdin);
		for(int i = 0;in[i + 1];++i) //in[i+1] for '\n'
		{
			char c = in[i];

			if(c == '[')
				it = out.begin();
			else if(c == ']')
				it = out.end();
			else if(c == '<')
				{
					if(it != out.begin())
						it = out.erase(--it);
				}
			else
				out.insert(it, c);
		}
		for(auto &u : out)
			printf("%c", u);
		printf("\n");
	}
	return 0;
}
