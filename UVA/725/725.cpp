/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 00725 UVA
* Link    : https://onlinejudge.org/external/7/p725.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	int n = 1;

	while (n) {
		if(n == 1) scanf("%d", &n);
		bool flag = false;

		for (int fghij = 1234; fghij <= 98765 / n; ++fghij) {
			int abcde = fghij * n, taken = 0, temp;

			temp = abcde; while (temp) {taken |= 1L << (temp % 10); temp /= 10;}
			temp = fghij; while (temp) {taken |= 1L << (temp % 10); temp /= 10;}

			taken |= (abcde <= 9999) || (fghij <= 9999);

			if (taken + 1 == 1 << 10) {
				printf("%05d / %05d = %d\n", abcde, fghij, n);
				flag = true;
			}
		}

		if(!flag)
			printf("There are no solutions for %d.\n", n);

		scanf("%d", &n);
		if(n) printf("\n");
	}

	return 0;
}
