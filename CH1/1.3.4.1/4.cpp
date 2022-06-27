#include <iostream>
#include <set>
using namespace std;

int main()
{
	int n,y;
	cin >> n;
	set <int> x;
	for(int i = 0; i < n; i++)
	{
		cin >> y;
		x.insert(y);
	}
	for(set<int>::iterator i = x.begin(); i != x.end(); ++i)
	{
		cout << *i << " ";
	}
return 0;
}
