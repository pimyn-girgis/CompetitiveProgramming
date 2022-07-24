//https://open.kattis.com/problems/magicsequence
#include <stdio.h>
#include <string.h>
#include <vector>
#include <array>

// lb = log_2(base). For example, if you want to use a base of 16, set lb to 4.
#define lb 8

std::vector<int> v;
std::array<std::vector<int>, 1<<lb> buckets;

void radix()
{
	for (int mask = (1 << lb) - 1, shift = 0; mask; mask <<= lb, shift += lb)
	{
		for (const int x : v) buckets[(x & mask) >> shift].push_back(x);
		
		int idx = 0;
		for (auto& b : buckets)
		{
			memcpy(&v[idx], &b[0], b.size() * sizeof(int));
			idx += b.size();
			b.clear();
		}
	}
}

typedef long long int ll;

int main() {
	int TC; scanf("%d", &TC);
	while (TC--) {

		ll n, a, b, c, x, y;
		scanf("%lld%lld%lld%lld%lld%lld", &n, &a, &b, &c, &x, &y);
		
		v.clear();
		v.push_back(a);
		while(--n) v.push_back((v.back()*b + a)%c);
		
		radix();
		
		ll hash = 0LL;
		for (const auto r : v) hash = (hash * x + r) % y;
		
		printf("%llu\n", hash);
	}
	return 0;
}
