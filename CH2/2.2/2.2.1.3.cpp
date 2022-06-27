#include <bits/stdc++.h>
using namespace std;

#define size 11
#define rangeBegin 7
#define rangeEnd 7
int S[size] = {0,9,8,1,1,7,1,6,1,1,1};
int SortedS[size];
int v = 11, a = 3, b = 7;

bool duplicate(){for(int i=0;i<size-1;++i)if(SortedS[i] == SortedS[i+1])return 1;return 0;}

bool abv()
{
	for(int i=0, j=size-1;i<j;)
	{
		a = SortedS[i]; b = SortedS[j];
		if(a+b == v) return 1;
		else if(a+b < v) ++i;
		else --j;
	}
	return 0;
}

void rangePrint(int a, int b)
{
	int *i = std::upper_bound(SortedS, SortedS+size, a - 1);
	if(*i <= b)
	{
		printf("Elements from %d to %d are: {", a, b);
		do printf("%d%s", *i, *i != b? ", " : "}\n"); while(*(i++) < b);
	}
	else printf("No elements exist in range [%d,%d]\n", a, b);
}

int longest()
{
	int con = 1, max = 1, index = 0;
	for(int i=0;i<size - 1;++i)
		if(S[i+1] >= S[i])
		{
			if(++con > max)
			max = con, index = i+2;
		}
		else con = 1;
	return max;
}

void maxOccur()
{
	int con = 0, max = 0, index;
	for(int i=0;i<size;++i)
	{
		if(SortedS[i] == SortedS[i+1])
			++con;
		else con = 0;
		if(con > max) max = con, index = i;
	}
	if(max > size/2 && !(size%2) || max >= size/2 && size%2) printf("The element that appears most is %d\n", SortedS[index]);
}

int main()
{
	memccpy(SortedS, S, size, sizeof(S));
	sort(SortedS, SortedS+size);
	printf("For array S with size %d with elements: {", size);
	for(int i = 0;i<size;++i) printf("%d%s",S[i], i != size-1?  ", " : "}\n");
	printf("There are %sduplicates\n", duplicate()? "" : "no ");
	if(abv()) printf("There are integers %d and %d that add up to %d\n", a, b, v);
	else printf("There are no digits that add up to %d\n", v);
	rangePrint(rangeBegin, rangeEnd);
	printf("The length of the longest increasing contiguous sub-array in S is: %d\n", longest());
	printf("The median valuse in S is: %d\n", S[size/2+1]);
	maxOccur();
	return 0;
}

