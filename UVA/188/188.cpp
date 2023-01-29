/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 188 UVA
* Link    : https://onlinejudge.org/external/1/p188.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

char input[1000];
char input_cp[1000];

vector<int> val;

int get_val(char *text) {
	int ans = 0;

	int len = strlen(text);
	for (int i = 0; i < len; ++i) {
		ans += int(text[len - i - 1] - 'a' + 1) << (5 * i);
	}

	return ans;
}

int solve(const int len) {
	int c = *min_element(val.begin(), val.end());

	label:
	for (int i = 0; i < len; ++i) {
		for (int j = i + 1; j < len; ++j) {
			if (c / val[i] % len == c / val[j] % len) {
				c = min((c / val[i] + 1) * val[i], (c / val[j] + 1) * val[j]);
				goto label;
			}
		}
	}

	return c;
}

int main() {
	while (fgets(input, sizeof(input), stdin)) {

		strcpy(input_cp, input);

		for (char *token = strtok(input, " \n"); token; token = strtok(0, " \n")) {
			val.push_back(get_val(token));
		}

		printf("%s", input_cp);
		printf("%d\n\n", solve(val.size()));

		val.clear();
	}

	return 0;
}

