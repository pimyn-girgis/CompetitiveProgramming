#include <bits/stdc++.h>
using namespace std;

string punc;

int main()
{
	punc.reserve(255);
	for(int i = 0; i < 256; ++i)
		if(ispunct(i) || isdigit(i) || isspace(i))
			punc += i;

	int tc;
	scanf("%d", &tc);
	
	vector <string> doc;
	unordered_set <string> words;
	unordered_map <string, int> freq;
	doc.reserve(1e5 + 5); words.reserve(1e5 + 5); freq.reserve(1e5 + 5);
	for(int caseNo = 1; caseNo <= tc; ++caseNo)
	{
		doc.clear(); words.clear(); freq.clear();
		char input[155];
		int num = 0;

		while (fgets(input, sizeof(input), stdin), strcmp(input, "END\n"))
			for(char *token = strtok(input, punc.c_str()); token; token = strtok(0, punc.c_str()))
				doc.push_back(token), words.insert(token);

		int begin = 0, end = 1e9;
		int p = 0, q = 0;

		while(q < doc.size())
		{
			while(freq.size() < words.size() && q < doc.size())
				++freq[doc[q++]];

			while(freq.size() == words.size() && p < doc.size())
				if(!(--freq[doc[p++]]))
					freq.erase(doc[p-1]);

			if(q - p < end - begin)
				end = q , begin = p;
		}

		printf("Document %d: %d %d\n", caseNo, begin, end);
	}

	return 0;
}