/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 1193 UVA
* Link    : https://onlinejudge.org/external/119/p1193.pdf
**************************************************************
* Approach: Use greedy method. For every point, calculate the
* range on the x axis that would be a solution to it. After
* that, keep going through the points (sorted by x) and minim-
* ze your range until you have no more points.
**************************************************************
*/

#include <set>
#include <utility>
#include <cmath>
#include <cstdio>
using namespace std;

typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int n, d;
set<pii> points;

pdd get_range(const set<pii>::iterator &pnt)
{
	pdd range;

	double diff = sqrt(d * d - pnt->second * pnt->second);
	range.first  = pnt->first - diff;
	range.second = pnt->first + diff;

	return range;
}

pdd min_range(const pdd &x, const pdd &y)
{
	return { max(x.first, y.first), min(x.second, y.second) };
}

int solve()
{
	int ret = 0;
	pdd range;

	while (!points.empty()) {

		++ret;
		range = get_range(points.begin());
		points.erase(points.begin());

		while (!points.empty()) {
			range = min_range(range, get_range(points.begin()));

			if(range.first > range.second)
				break;

			points.erase(points.begin());
		}

	}

	return ret;
}
int main()
{
	int caseNo = 1;

	while(scanf("%d %d", &n, &d), n && d) {
		bool flag = false;
		points.clear();

		int x, y;
		while(n--) {
			scanf("%d %d", &x, &y);
			if(y > d) flag = true;
			points.emplace(x, y);
		}

		printf("Case %d: %d\n", caseNo++, flag? -1 : solve());
	}

	return 0;
}
