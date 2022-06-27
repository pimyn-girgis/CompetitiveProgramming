// Can only do up to 18446744073709551615
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long unsigned int x;
	cin >> x;
	cout << x << " is ";
	if(x % 2 == 0)
		{
		cout << "Composite";
		return 0;
		}
	long long unsigned int y = sqrt(x);
	for(int i = 3; i <= y; i += 2)
		if(x % i == 0)
			{
			cout << "Composite";
			return 0;	
			}
	cout << "Prime";
	return 0;
}
