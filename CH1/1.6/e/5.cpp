#include <bits/stdc++.h>
using namespace std;

char arr[2][5][5] = {"A#", "C#", "D#", "F#", "G#",
					 "Bb", "Db", "Eb", "Gb", "Ab"};
int main()
{
	int count = 0;
	bool found;
	char note[5], tonality[10];
	while(scanf("%s %s", note, tonality) != EOF)
	{
		found = 0;
		for(int i = 0; i < 2; ++i)
			for(int j = 0; j < 5; ++j)
				if(!strcmp(note, arr[i][j]))
					{
						strcpy(note, arr[!i][j]);
						found = 1;
						goto label;
					}
label:
	printf("Case %d: ", ++count);
	if(found) printf("%s %s\n", note, tonality);
	else printf("UNIQUE\n");
	}
	return 0;
}

