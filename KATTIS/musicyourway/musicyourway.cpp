#include <bits/stdc++.h>
using namespace std;

char atr[1000];
char atrCopy[1000];
char input[35];
vector <string> order;
vector<vector<string> > arr;
int sortVal;

bool comp(vector<string> x, vector<string> y)
{
	auto xval = x.begin()[sortVal], yval = y.begin()[sortVal];
	if(xval != yval) return xval < yval;
}

void tokenize()
{
	int i = 0;
	strcpy(atrCopy, atr);
	char *token = strtok(atrCopy, " \n");
	do
	{
		order.insert(order.begin() + i, token);
		token = strtok(0, " \n");
		++i;
	} while (token);
}

void output()
{
	printf("%s", atr);
	for(auto &u : arr)
	{
		for(auto &v : u)
			printf(v == *u.begin()? "%s" : " %s", v.c_str());
		printf("\n");
	}
}

int main() 
{
	fgets(atr, 1000, stdin);
	int num = 1 + count(atr, atr+strlen(atr), ' ');
	order.resize(num);
	tokenize();

	int count;
	scanf("%d", &count);
	arr.resize(count);

	for(auto &u : arr)
	{
		for(int i=0;i<num;++i)
		{
			scanf("%s", input);
			u.push_back(input);
		}
	}

	int sortCount;
	scanf("%d", &sortCount);

	while (sortCount--)
	{
		scanf("%s", input);
		sortVal = find(order.begin(), order.end(), input) - order.begin();
		stable_sort(arr.begin(), arr.end(), comp);
		output();
		if(sortCount) printf("\n");
	}

	return 0;
}
