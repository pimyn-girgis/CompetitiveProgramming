#include <bits/stdc++.h>
using namespace std;

char mat[11][11];
char trans[11][11];
char matCopy[11][11];
int num = 0;
int m;

void output(const char *ans) {printf("Pattern %d was %s.\n", ++num, ans);}

void init()
{
	memset(mat, 0, sizeof(mat));
	memset(trans, 0, sizeof(trans));
}

bool vertical()
{
	for(int i=0;i<m;++i)
		if(strcmp(mat[i], trans[m-i-1]))
			return 0;
	return 1;
}

int rotate(int rot = 0)
{
	if(++rot == 4) return 0;

	char rotated[11][11];
	memset(rotated, 0, sizeof(rotated));

	for(int i=0;i<m;++i)
		for(int j=0;j<m;++j)
			rotated[j][m-i-1] = matCopy[i][j];
		
	memcpy(matCopy, rotated, sizeof(rotated));
	return !memcmp(rotated, trans, sizeof(mat))? 90*rot : rotate(rot);
}

int comb()
{
	for(int i=0;i<m;++i)
		strcpy(matCopy[i], mat[m-i-1]);

	return rotate();
}

void solve()
{
	int rot;
	char out[50];

	if(!memcmp(mat, trans, sizeof(mat)))
		strcpy(out, "preserved");
	else if((rot = rotate()))
		sprintf(out, "rotated %d degrees", rot);
	else if(vertical())
		strcpy(out, "reflected vertically");
	else if((rot = comb()))
		sprintf(out, "reflected vertically and rotated %d degrees", rot);
	else
		strcpy(out, "improperly transformed");

	output(out);
}

int main()
{
	while(scanf("%d", &m) != EOF)
	{
		init();
		for(int i=0;i<m;++i) scanf("%s %s", mat[i], trans[i]);
		memcpy(matCopy, mat, sizeof(mat));
		solve();
	}
}