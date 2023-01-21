/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : ##### UVA
* Link    : https://onlinejudge.org/external/###/p#####.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <cstdio>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>

using namespace std;

const int MAX = 10001;
unordered_set<int> primes;
int num_primes[MAX];

bool produces_prime(int i) { return primes.find(i) != primes.end(); }

bool is_prime(int n)
{
	for (int i = 2; i * i <= n; ++i) {
		if(n % i == 0)
			return false;
	}

	return true;
}

void preprocess()
{
	primes.reserve(MAX);

	for (int i = 0; i < MAX; ++i) {
		if (is_prime(i * i + i + 41)) {
			primes.emplace(i);
		}
	}

	num_primes[0] = 1;
	for (int i = 1; i < MAX; ++i) {
		num_primes[i] = num_primes[i - 1] + produces_prime(i);
	}
}


int main()
{
	int a, b;

	preprocess();

	while (scanf("%d %d", &a, &b) != EOF) {
		printf("%.2lf\n", 100.0 * (num_primes[b] - num_primes[a] + produces_prime(a))/(b - a + 1) + 1e-6);
	}

	return 0;
}
