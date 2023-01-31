/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 222 UVA
* Link    : https://onlinejudge.org/external/2/p222.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;

double cap, mpg, cost, dist;
vector<pair<double, double>> station;

double solve(double miles, double fuel, int i = 0) {
	if (fuel * mpg + miles >= dist || i == station.size()) {
		return 0.0;
	}

	double next = (i + 1 == station.size())? dist : station[i + 1].first;
	double fuel_cons = (next - station[i].first) / mpg;

	if (mpg * fuel + miles < next) {
		return round(200.0 + (cap - fuel) * station[i].second + 1e-6) + solve(next, cap - fuel_cons, i + 1);
	}

	if (fuel > cap / 2.0){
		return solve(next, fuel - fuel_cons, i + 1);
	}

	return min(solve(next, fuel - fuel_cons, i + 1), round(200.0 + (cap - fuel) * station[i].second + 1e-6) + solve(next, cap - fuel_cons, i + 1));
}

int main() {

	int data_set = 0;
	while (scanf("%lf", &dist), dist >= 0) {
		station.clear();

		int station_count;
		scanf("%lf %lf %lf %d", &cap, &mpg, &cost, &station_count);

		double dist_to_station, price;
		while (station_count--) {
			scanf("%lf %lf", &dist_to_station, &price);

			if (!station.empty() && station.back().first == dist_to_station) {
				station.back().second = min(price, station.back().second);
			} else {
				station.emplace_back(dist_to_station, price);
			}
		}

		printf("Data Set #%d\nminimum cost = $%0.2lf\n", ++data_set, cost + solve(station.front().first, cap - station.front().first / mpg) / 100.0);
	}

	return 0;
}
