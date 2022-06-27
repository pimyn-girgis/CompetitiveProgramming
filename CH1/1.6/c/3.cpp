#include <bits/stdc++.h>
using namespace std;

int ts, c, w, len;
char guess[10];
bool taken[5];
char gen[6];
int ans;
void base()
{
	memset(taken, 0, sizeof(taken));
	int correct = 0, wrong = 0;
	for(int i = 0; i < len; ++i)
		if(guess[i] == gen[i])
			++correct, taken[i] = true;

	if (correct != c) return;

	for (int i = 0; i < len; ++i)
		if (guess[i] != gen[i])
			for (int j = 0; j < len; ++j)
				if (!taken[j] && gen[i] == guess[j]) {++wrong, taken[j] = true; break;}

	if (wrong == w) ++ans;
}

void rec(const int i)
{
  if (i == len) {
    base();
    return;
  }
  for (char c = '1'; c <= '9'; ++c) {
    gen[i] = c;
    rec(i + 1);
  }
}

int main()
{
	scanf("%d", &ts);
	while(ts--)
	{
		ans = 0;
		scanf("%s%d%d", guess, &c, &w);
		len = strlen(guess);
		rec(0);
		printf("%d\n", ans);
	}
	return 0;
}
