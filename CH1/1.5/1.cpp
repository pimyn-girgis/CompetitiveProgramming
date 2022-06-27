#include <bits/stdc++.h>
using namespace std;

int main()
{
	FILE * ptr;
	int d = 0, vow = 0, con = 0, s = 0, h = 0, seven = 0;
	bool yes = 0, dash = 0, cs= 0;
	char in[35], out[310]="\0", vowels[6] = "aeiou", large[35] = "aaaaaa", small[35] = "zzzzzz", ref[35] = "\0", one;
ptr = fopen("text.txt", "r");

	while(fgets(in, 30, ptr))
	{
		if(!strcmp(".......\n", in))
				break;
		for(int i = 0; in[i]; ++i)
		{
			if(isupper(in[i]))
				in[i] = tolower(in[i]);
			else if(in[i] == '-')
				in[i] = '\0';
			else if(in[i] == '\n')
				in[i] = ' ';
		}
		strcat(out, in);
	}

	int k = 0;
	for(int i = 0; out[i]; ++i)
	{
		if(isdigit(out[i]) || isalpha(out[i]))
		{
			ref[k] = out[i];
			ref[++k] = '\0';
		}

		if(isspace(out[i]))
		{
			if(!strcmp("cs3233", ref))
				cs = 1;
			for(int j = 0; j < large[j] && ref[j]; ++j)
				if(large[j] < ref[j])
				{
					strcpy(large, ref);
					break;
				}
				else if(large[j] > ref[j])
					break;
			for(int j = 0;small[j] && ref[j]; ++j)
				if(small[j] > ref[j])
				{
					strcpy(small, ref);
					break;
				}
				else if(small[j] < ref[j])
					break;
			k = 0;
			strcpy(ref, "\0");
		}

		if(isdigit(out[i]))
				++d;
		else if(isalpha(out[i]))
		{
			yes = 0;
			for(int j = 0; j < 5; ++j)
				{
					if(out[i] == vowels[j])
					{
						++vow;
						yes = 1;
					}
				}
			if(!yes)
				++con;
		}
	
	}
	while((one = fgetc(ptr))!= EOF)
	{
		if(one == 's')
			++s;
		else if(one == 'h')
			++h;
		else if(one == '7')
			++seven;
	}
	printf("%s\n%d %d %d\n%s %s\n%d\n%d %d %d", out, d, vow, con, small, large, cs, s, h, seven);
	return 0;
}
