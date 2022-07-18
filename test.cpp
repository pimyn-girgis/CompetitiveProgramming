#include <stdio.h>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <string.h>
#include <algorithm>

typedef std::pair<int, int> ii;

int incorrect[101][10];  // used to track time pentalty.
int correct[101][10];
bool submitted[101];

void init() {
	memset(incorrect, 0, sizeof(incorrect));
	memset(correct, 0, sizeof(correct));
	memset(submitted, 0, sizeof(submitted));
}

void read() {
	char input[100];
	int c, p, t; // contestant, problem, time
	char v; // verdict.
	while (std::fgets(input, 100, stdin) && *input && *input != '\n') {
		sscanf(input, "%d %d %d %c", &c, &p, &t, &v);
		submitted[c] = true;  // Record that contestant #c made a submission.
		if (correct[c][p]) continue; // Problem already solved.

		if (v == 'I') incorrect[c][p]++;
		else if (v == 'C') correct[c][p] = t + 20 * incorrect[c][p];
	}
}

void print() {
	std::map<int, std::set<ii>> board;
	for (int c = 1; c <= 100; ++c) {
		if (!submitted[c]) continue;

		int n = 0, t = 0;
		int* ac = correct[c];
		for (int p = 1; p <= 9; ++p)
			n += bool(ac[p]), t += ac[p];

		board[n].insert(ii(t, c));
	}
	
	for (auto iter = board.rbegin(); iter != board.rend(); ++iter)
	{
		const int n = iter->first;	// number of problems.
		for (const auto pair : iter->second)
		printf("%d %d %d\n", pair.second /*contestant*/, n, pair.first /*time*/);
	}
}
int main() {
	int TC; scanf("%d\n\n", &TC);
	while(TC--) {
		init();
		read();
		print();
		if (TC) printf("\n");
	}
	return 0;
}
