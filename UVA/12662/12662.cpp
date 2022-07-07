#include <bits/stdc++.h>
using namespace std;

string call[105];
string name[105];

void init(int n)
{
	int left = -1, right;
	for(int i=1;i<=n;++i)
	{
		if(name[i] != "?") //known
		{
			call[i] = name[i];
			left = i;
		}

		else
		{
			for(int j=i;j<=n;++j) //get index of closest known name on the right
			{
				if(name[j] != "?")
				{
					right = j;
					break;
				}
				else right = -1;
			}

			if(right-i == i-left && left != -1) //middle
			{
				call[i] = "middle of " + name[left] + " and " + name[right];
			}

			else if((right-i > i-left || right == -1) && left != -1) //left is closer or not right
			{
				for(int j=left;j<i;++j)
					call[i] += "right of ";
				call[i] += name[left];
			}

			else //right is closer
			{
				for(int j=right;j>i;--j)
					call[i] += "left of ";
				call[i] += name[right];
			}

		}
	}
}

void input(int n)
{
	char in[9];
	for(int i=1;i<=n;++i)
	{
		scanf("%s", in);
		name[i] = in;
	}
}

void solve()
{
	int q, val;
	scanf("%d", &q);
	for(int i=0;i<q;++i)
	{
		scanf("%d", &val);
		printf("%s\n", call[val].c_str());
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	input(n);
	init(n);
	solve();
	return 0;
}
