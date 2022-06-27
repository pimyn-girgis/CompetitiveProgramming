// Special word
#include <iostream>
using namespace std;

int main()
{
	string x;
	getline(cin, x);
	for(int i = 0; i <= x.size() - 3; i++)
	{
		if((isblank(x[i-1]) || i == 0) && isalpha(x[i]) && isdigit(x[i+1]) && isdigit(x[i+2]) && (isblank(x[i+3]) || i == x.size()-3))
			for(int j = 0; j < 3; j++)
				x[i+j] = '*'; 
	}
cout << x;
}
