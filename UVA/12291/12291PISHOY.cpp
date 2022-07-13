#include <bits/stdc++.h>
using namespace std;

bool large[10][10];
bool small[10][10];
bool composed[21][21];
bool test[21][21];
int m, n;

bool translate(const int dim, const int x, const int y, bool dest[][21], bool src[][10])
{
	for (int i = 0; i < dim; ++i)
		for (int j = 0; j < dim; ++j){
			if (!src[i][j]) continue;
			auto & c = dest[i+x][j+y];
			if (c) return false;
			c = 1;
		}
	return true;
}

void print(bool a[][22]) {
	for (int i = 0; i < 22; ++i)
	for (int j = 0; j < 22; ++j)
	printf("%c%s", a[i][j] ? '1' : '0', j == 21 ? "\n" : "");
}

bool match() {
	for (int x = 0; x < m; ++x)
	for (int y = 0; y < m; ++y)
	{
		memset(test, 0, sizeof(test));
		translate(n, x, y, test, large);
		if (!memcmp(test, composed, sizeof(test))) return true;
	}
	return false;
}
bool solve()
{
	for (int u = 0; u <= n; ++u)
	for (int v = 0; v <= n; ++v)
	for (int x = 0; x <= n; x++)
	for (int y = 0; y <= n; y++)
	{
		// Place a copy of the small shape with the bottom left corner at (0, 0)
		// and another copy with the bottom left corner at (x, y),
		// and see if this gives you the large shape.
		memset(composed, 0, sizeof(composed));
		translate(m, u, v, composed, small);
		if (!translate(m, x, y, composed, small)) continue;
		if (match()) return 1;
	}
	return 0;
}

bool input()
{
	int l = 0;
	char input[11];
	for(int i=0;i<n;++i)
	{
		scanf("%s", input);
		for(int j=0;j<n;++j)
			l += (large[i][j] = input[j] == '*');
	}

	int s = 0;
	for(int i=0;i<m;++i)
	{
		scanf("%s", input);
		for(int j=0;j<m;++j)
			s += (small[i][j] = input[j] == '*');
	}

	return s * 2 == l;
}

void init()
{
	memset(large, 0, sizeof(large));
	memset(small, 0, sizeof(small));
	memset(composed, 0, sizeof(composed));
}

int main()
{
	while(scanf("%d %d", &n, &m) && (m || n))
	{
		init();
		printf("%d\n", input() && solve());
	}
	return 0;
}
