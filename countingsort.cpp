#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int arr[] = {2, 2, 2, 3, 2, 2, 3, 4, 4, 5, 5, 3, 2, 3, 2, 5};
	const int len = sizeof(arr)/sizeof(int);

	int l = *min_element(arr, arr+len);
	int r = *max_element(arr, arr+len);
	const int size = r-l+1;

	int freq[size];
	memset(freq, 0, (size)*sizeof(int));

	for(auto &u : arr) ++freq[u-l];
	for(int i=0;i<size;++i) freq[i] = i? freq[i] + freq[i-1] : freq[i];

	int sorted[len];
	for(int i=len-1;i>=0;--i)
	{
		int &index = freq[arr[i]-l];
		sorted[index-1] = arr[i];
		--index;
	}

	for(auto &u : sorted) printf("%d\n", u);
	return 0;
}

