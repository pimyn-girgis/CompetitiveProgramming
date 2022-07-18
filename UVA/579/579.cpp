#include <bits/stdc++.h>
using namespace std;

int main()
{
	int h, m;
	while (scanf("%d:%d", &h, &m) && (h || m))
	{
		float angle = 0, hour, minute;
		hour = h * 30 + m * 0.5;
		minute = m * 6;
		angle = abs(hour - minute);
		angle = min(angle, 360-angle);
		printf("%.3f\n", angle);
	}
	return 0;
}
