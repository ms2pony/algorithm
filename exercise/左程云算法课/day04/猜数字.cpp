//需要掌握，暴力递归到动态规划的套路
#include <iostream>
#include <vector>
using namespace std;

int minGold(int n)
{
	return zuo(1, n);
}

// 目前锁定了，正确的数字，在L-R范围上，除了这个范围都不可能了
// 返回，永远最倒霉下，猜中数字，所需要的最少钱数
int zuo(int L, int R)
{
	//终止条件
	if (L == R)
	{
		return 0;
	}

	if (L == R - 1)
	{ // L,R 3,4 因为永远最倒霉，所以必然猜错，所以猜小的数花费最低
		return L;
	}

	// L...R 不止两个数
	int p1 = L + zuo(L + 1, R);
	int p2 = R + zuo(L, R - 1);

	int res = min(p1, p2);

	// L...R
	for (int i = L + 1; i < R; i++)
	{
		// i 猜的数字，每一个都试试
		// L... i ...R
		int left = zuo(L, i - 1);
		int right = zuo(i + 1, R);
		int cur = i + max(left, right);

		res = min(res, cur);
	}

	return res;
}

int minGold2(int n)
{
	// L 1~n
	// R 1~n
	vector<vector<int>> dp(n + 1, vector<int>(5));

	//因为初始化都是0，所以dp的对角线不用填
	for (int i = 1; i < n; i++)
	{
		dp[i][i + 1] = i;
	}

	for (int L = n - 2; L >= 1; L--)
	{
		for (int R = L + 2; R <= n; R++)
		{
			int res = min(L + dp[L + 1][R], R + dp[L][R - 1]);

			for (int i = L + 1; i < R; i++)
			{
				res = min(res, i + max(dp[L][i - 1], dp[i + 1][R]));
			}
			dp[L][R] = res;
		}
	}
	return dp[1][n];
}