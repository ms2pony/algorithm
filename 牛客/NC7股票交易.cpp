//����������
//��������һ�����飬���е�i��Ԫ���ǹ�Ʊ�ڵ�i��ļ۸�
//����һ������������Ļ��ᡣ(ֻ�������˹�Ʊ�Ժ��������)���������һ���㷨��������Ի�õ�������档

#include <iostream>
#include <algorithm>
#include<vector>
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