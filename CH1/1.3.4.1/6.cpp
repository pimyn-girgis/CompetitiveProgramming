#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
int n;
int v;
cout << "Enter number of elements.\n";
cin >> n;
vector<int> x;
for(int i(0); i < n; i++){
	cin >> v;
	x.push_back(v);
	}
bool found = 0;
int begin = 0, end = n-1;
cin >> v;
n = 0;
while(!found && end >= begin)
{
	++n;
	if(v == x[(end+begin)/2])
		found = 1;
	else if (v > x[(end+begin)/2])
		begin = (end+begin)/2 + 1;
	else
		end = (end+begin)/2 - 1;
}
if(found) cout << "Found";
else cout << "Not found";
cout << "\n" << n;
return 0;
}
