/*
********************************************
* Authors : Michael Henein & Bemen Girgis
********************************************
*/

#include <stdio.h>
#include <algorithm>
#include <vector>

int max_profit(std::vector<int> prices)
{
	prices.push_back(0); //insert last element to calculate its best price

	for(int i = 0; i < prices.size(); ++i) //for every length
		for(int j = 1; j <= i; ++j)//check all possible prices
			prices[i] = std::max(prices[i], prices[i - j] + prices[j - 1]);//get the maximum price for the current length

	 return prices.back(); //return the answer
}

int main()
{
	std::vector<int> prices = {2, 5, 7, 8};
	printf("%d\n", max_profit(prices));

	return 0;
}
