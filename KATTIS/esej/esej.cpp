//https://open.kattis.com/problems/esej
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	char word[] = "abcdefghij";
	int num = max(b/2 + 1, a);

	while(num--) printf("%s%c", word, num? ' ' : '\n'), next_permutation(word, word + 10);

	return 0;
}
