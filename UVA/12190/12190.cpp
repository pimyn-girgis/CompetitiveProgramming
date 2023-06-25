/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 12190 UVA
* Link    : https://onlinejudge.org/external/121/p12190.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

const int cost_diff[] = {2, 1, 2, 2};
const int range[] = {100, 9900, 990000, INT_MAX / 7};
const int cost[] = {2, 3, 5, 7};

int price(int usage) {
  int price = 0;

  int i = 0;
  while (usage > 0) {
    price += usage * cost_diff[i];
    usage -= range[i++];
  }

  return price;
}

int usage(int price) {
  int usage = 0;

  int i = 0;
  while (price > 0) {
    int max_cost = range[i] * cost[i];
    usage += min(max_cost, price) / cost[i++];
    price -= max_cost;
  }

  return usage;
}

int main() {
  int a, b;

  while (scanf("%d%d", &a, &b), a) {
    int lo = 0, hi = usage(a) + 1;

    while (lo < hi) {
      int mid_usage = (lo + hi) / 2;
      int mid_price = price(mid_usage);
      int zer_usage = usage(mid_price + b);
      int cur_price = price(mid_usage + zer_usage);

      if (cur_price == a) {
        printf("%d\n", price(mid_usage));
        break;
      } else if (cur_price < a) {
        lo = mid_usage + 1;
      } else {
        hi = mid_usage;
      }
    }
  }
  return 0;
}
