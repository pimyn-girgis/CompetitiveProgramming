#include <bits/stdc++.h>
using namespace std;

int N = 3;
typedef tuple<int, string, string> iss;
vector<iss> person(N);
bool cmp(const iss &a, const iss &b)
{
	auto &[ageA, lastA, firstA] = a;
	auto &[ageB, lastB, firstB] = b;
	if(ageA != ageB) return ageA < ageB;
	if(lastA != lastB) return lastA > lastB;
	return firstA < firstB;
}
void output(){for(auto u : person) printf("%d %s %s\n", get<0>(u), get<1>(u).c_str(), get<2>(u).c_str());}

int main()
{
	char in1[1000], in2[1000];
	for(auto &u : person) {scanf("%d %s %s", &get<0>(u), in1, in2); get<1>(u) = in1; get<2>(u) = in2;}
	sort(person.begin(), person.end(), cmp);
	output();
	return 0;
}

