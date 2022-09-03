//用两个指针表示某个字符串的左右边界
//枚举出所有左边界可能的情况，每个情况计算出最长子串
//选取所有情况的最长字符串中最长的，即是满足题意的最长子串
#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include <unordered_set>

class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		//哈希集合，记录每个字符串是否出现过
		unordered_set<char> occ;
		int n = s.size();
		// 右指针，初始值为-1，相当于我们在字符串的左边界的左侧，还没有开始移动
		int rk = -1, ans = 0;
		// 枚举左指针的位置，初始值隐形地表示为-1
		for (int i = 0; i < n; i++)
		{
			if (i != 0)
			{
				//左指针向右移动一格，移除一格字符
				occ.erase(s[i - 1]);
			}
			while (rk + 1 < n && !occ.count(s[rk + 1]))
			{
				// 不断移动右指针
				occ.insert(s[rk + 1]);
				rk++;
			}

			ans = max(ans, rk - i + 1);
		}
		return ans;
	}
};