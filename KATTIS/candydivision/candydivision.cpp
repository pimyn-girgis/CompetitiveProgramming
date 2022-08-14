//https://open.kattis.com/problems/candydivision
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() 
{
	set <ll> divisors;

	ll n;
	scanf("%lld", &n);

	for(ll i = 1; i * i <= n + 5; ++i)
		if(!(n % i))
			divisors.insert(i), divisors.insert(n / i);

	for(auto it = divisors.begin(); it != divisors.end(); ++it)
		printf("%lld%c", *it - 1, it == --divisors.end()? '\n' : ' ');

	return 0;
}
