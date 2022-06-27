#include <bits/stdc++.h>
using namespace std;

char pref[1010];
int seatUp = 0, seatDown = 0, like = 0;

void upDown(int &policy, char val)
{
	if(pref[0] != val)
		++policy;
	for(int i = 1 + (pref[1] == pref[0]);pref[i]; ++i)
		if(pref[i] != val)
			policy += 2;
}
void likeToFind()
{
	for(int i = 1;pref[i];++i)
		if(pref[i] != pref[i-1])
			++like;
}
void solve()
{
	upDown(seatUp, 'U');
	upDown(seatDown, 'D');
	likeToFind();
}
int main()
{
	scanf("%s", pref);
	solve();
	printf("%d\n%d\n%d\n", seatUp, seatDown, like);
	return 0;
}

