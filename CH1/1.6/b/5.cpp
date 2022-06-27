#include <bits/stdc++.h>
using namespace std;

char a, b, c, d;
int count;
int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, 1, -1};

bool valid(int x, int y){return 'A' <= x && x <= 'H' && '1' <= y && y <= '8';}
bool SameColor() {return (a%2 == b%2) == (c%2 == d%2);}
bool SameDiagonal(char x, char y){return abs(c - x) == abs(d - y);}

void move(char x, char y)
{
	for(int i = 0; i < 4; ++i)
		for(x = a + dx[i], y = b + dy[i]; valid(x, y); x += dx[i], y += dy[i])
			if(SameDiagonal(x, y))
			{
				printf("2 %c %c %c %c %c %c\n", a, b, x, y, c, d);
				return;
			}
}

int main()
{
	int ts;
	scanf("%d", &ts);
	while(ts--)
	{
		scanf(" %c %c %c %c", &a, &b, &c, &d);
		if(!SameColor())
			printf("Impossible\n");
		else if(a == c && b == d)
			printf("0 %c %c\n", a, b);
		else if(SameDiagonal(a, b))
			printf("1 %c %c %c %c\n", a, b, c, d);
		else
			move(a, b);
	}
	return 0;
}

