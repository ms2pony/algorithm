//问题描述：
//假设你有一个数组，其中第i个元素是股票在第i天的价格。
//你有一次买入和卖出的机会。(只有买入了股票以后才能卖出)。请你设计一个算法来计算可以获得的最大收益。

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int minn = prices[0];
		int ans = 0;
		for (int i = 0; i < prices.size(); i++) {
			minn = min(minn, prices[i]);
			ans = max(ans, prices[i] - minn);
		}
		return ans;
	}
};