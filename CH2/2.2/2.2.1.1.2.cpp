#include <bits/stdc++.h>
using namespace std;

struct fraction{int num, denom;};
bool cmp(const fraction a, const fraction b){return a.num * b.denom < b.num * a.denom;}
int main()
{
	int N = 5;
	vector<fraction> arr(N);
	for(auto &u : arr) scanf("%d/%d", &u.num, &u.denom);
	sort(arr.begin(), arr.end(), cmp);
	for(auto &u : arr) printf("%d/%d ", u.num, u.denom);
	return 0;
}

