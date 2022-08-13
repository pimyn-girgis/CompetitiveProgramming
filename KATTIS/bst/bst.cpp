//https://open.kattis.com/problems/bst
#include <bits/stdc++.h>
using namespace std;

struct node
{
	node *left;
	node *right;
	int val;
};

int insert(node *&cur, int input)
{
	if(cur)
		return 1 + insert(cur->val > input? cur->left : cur->right, input);

	cur = new node;

	cur->left = 0;
	cur->right = 0;
	cur->val = input;

	return 0;
}

int main() 
{
	int n;
	scanf("%d", &n);

	node *root = nullptr;

	long long unsigned int c = 0;
	while(n--)
	{
		int val;
		scanf("%d", &val);
		printf("%llu\n", c += insert(root, val));
	}

	return 0;
}
