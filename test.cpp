#include <cstdio>
#include <queue>

std::vector <int> maxHeap;

void printGreaterThan(int x, int index)
{
	if(maxHeap[index] <= x)
		return;

	const int firstChild = index << 1;
	const int secondChild = firstChild + 1;

	if(firstChild < maxHeap.size())
		printGreaterThan(x, firstChild);
	if(secondChild < maxHeap.size())
		printGreaterThan(x, secondChild);

	printf("%d\n", maxHeap[index]);
}

int main()
{
	int val = 100;

	maxHeap.push_back(0);

	while(val--)
		maxHeap.push_back(val + 1);

	printGreaterThan(90, 1);

	return 0;
}