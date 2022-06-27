#include <bits/stdc++.h>
using namespace std;

int bits, bytes[200];
int Count, output;
long long unsigned int values[200];
char var[200][25], str[100], ram[200][200];

void toDecimal(int x)
{
	for(int i = strlen(ram[x]) - 1, k = 0;i >= 0; --i, ++k)
		if(ram[x][i] == '1') values[x] |= 1ULL << k;
}

void input()
{
	for(int i = 0; i < Count; ++i)
		scanf("%s%d", var[i], bytes + i);
		
	if(!Count) return;
	
	for(int i = 0; i < Count; ++i)
	{
		for(int j = 0; j < bytes[i]; ++j)
		{
			scanf("%s", str);
			strcat(ram[i], str);
		}
		toDecimal(i);
	}
}

void init()
{
	memset(values, 0, sizeof(values));
	memset(ram, 0, sizeof(ram));
	memset(var, 0, sizeof(var));
}

int main()
{
	char name[25];
	while(scanf("%d %d", &bits, &Count) != EOF)
	{
		init();
		input();
		scanf("%d", &output);
		while(output--)
		{
			scanf("%s", name);
			bool found = 0;
			for(int i = 0; i < Count; ++i)
			{
				if(!strcmp(name, var[i]))
				{
					printf("%s=%llu\n", name, values[i]);
					found = 1;
				}
			}
			if(!found) printf("%s=\n", name);
		}
	}
	return 0;
}