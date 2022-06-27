#include <bits/stdc++.h>
using namespace std;

char in[100], fix[100];
int sum, Prev, val, frame;
bool roll;

int solve(int i, bool raw)
{
	if(isdigit(fix[i]))
	{
		Prev = fix[i] - '0';
		if(i > 0 && isdigit(fix[i-1]) && !raw)++frame, fix[i] = 'd';
		return Prev;
	}
	else if(fix[i] == 'X'){frame += !raw; return raw? 10 : 10 + solve(i+1, 1) + solve(i+2, 1);} //solve for i+1, i+2
	else if(fix[i] == '/'){frame += !raw; return raw? (10 - Prev) : 10 - Prev + solve(i+1, 1);} //-Prev + 10; solve for i+1
	return 0;
}
int main()
{
	while(fgets(in, 100, stdin))
	{
		if(in[0] == 'G')
			return 0;
		sum = frame = roll = 0;
		for(int i = 0, j = 0; in[i]; ++i)
			if(in[i] != ' ') fix[j++] = in[i], fix[j] = 0;
		for(int i = 0;fix[i] && frame < 10; ++i)
			sum += solve(i, 0);

		printf("%d\n", sum);
	}
}
