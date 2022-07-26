//https://open.kattis.com/problems/pairingsocks
#include <bits/stdc++.h>
using namespace std;

stack<int> org;
stack<int> aux;
int arr[200005];

int main() 
{
	int n, count = 0;
	scanf("%d", &n);
	n *= 2;
	for(int i = 0;i < n;++i)
		scanf("%d", arr+i);
	for(int i = n - 1;i >= 0;--i)
		org.push(arr[i]);
	while(org.size())
	{
		while(org.size() && aux.size() && org.top() == aux.top()) org.pop(), aux.pop(), ++count;
		if(org.empty()) break;
		aux.push(org.top());
		org.pop();
		++count;
	}
	if(aux.empty())
		printf("%d\n", count);
	else
		printf("impossible\n");
	return 0;
}