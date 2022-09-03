//详细问题描述以及解析参考：https://www.nowcoder.com/profile/483518733/myFollowings/detail/32581072
#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <algorithm>

//贪心决策1，去题目网站跑了，只过了2个实例，且代码也不怎么简洁
//也就是说solution1的代码既不能跑正确所有实例，代码也很晦涩难懂
int solution1()
{
	int n;
	cin >> n;
	getchar();
	string str;
	string str1 = "";
	cin >> str;

	//串中每个字符的价值
	vector<int> value(n);

	value[0] = 1;

	if (str[1] != str[0])
	{
		value[1] = 1;
	}
	else
	{
		value[1] = value[0 + 1];
	}

	str1 += str[0];

	char left = 0, right = 2; // left指当前字符的左边字符，pre2指当前字符右边字符
	// 0和n-1的字符不会被删除
	//选择一种贪心策略来删除s的字符串，使得修改后的字符串价值最大
	int i = 1;
	int jump = 0;
	while (i < n)
	{
		if (right == n)
			break;

		if (str[right] != str[i])
		{
			value[right] = 1;
		}
		else
		{
			value[right] = value[i] + 1;
		}

		//决策是否删除当前i所指向的字符
		if (str[right] == str[left] && value[left] + 1 >= value[right] + value[i])
		{
			//删掉当前i所指向的字符，也就是说left指针不增长，
			value[i] = 0;
			value[right] = value[left] + 1;
			right++;
			jump++;
		}
		else
		{
			right++;
			left += 1 + jump;
			jump = 0;
		}

		i++;
	}

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += value[i];
	}
	cout << sum;
}