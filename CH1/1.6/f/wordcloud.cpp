#include <bits/stdc++.h>
using namespace std;

//widthOfWord = ceil[(9/16)*charCount*fontSize.]
//fontSize = 8  +ceil[(40 * (numOfOccurances - 4))/(maxOccur - 4)]
//10 pt between two wors
int W, N, num = 0, ans, cmax, maxVal, occur[105], font[105], width[105];
char words[105][500];

void input(){for(int i = 0; i < N; ++i) scanf("%s %d", words[i], occur + i);}
int fontSize(char *word, int count){return 8 + ceil((40.0 * (count - 4))/(cmax-4));}
int widthSize(char *word, int index){return ceil((9.0/16.0) * strlen(word) * font[index]);}

void setFonts()
{
	cmax = *max_element(occur, occur + N);
	for(int i = 0;i < N; ++i)
	{
		font[i] = fontSize(words[i], occur[i]);
		width[i] = widthSize(words[i], i);
	}
}
void solve()
{
	int current = 0, height = 0;
	ans = 0;
	for(int i = 0; i < N; ++i)
	{
		if(current + width[i] > W)
		{
			ans += height;
			height = current = 0;
		}
		if(current + width[i] <= W)
		{
			current += width[i] + 10;
			height = max(height, font[i]);
		}
	}
	ans += height;
}
int main()
{
	while (scanf("%d %d", &W, &N) && W && N)
	{
		input();
		setFonts();
		solve();
		printf("CLOUD %d: %d\n", ++num, ans);
	}
	return 0;
}

