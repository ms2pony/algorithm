// sort函数中的compare函数如何自定义，规则如下：
//  sort函数根据comp函数的返回值，对comp函数的两个参数排序。
//  如果comp返回true，排序为“参数1”“参数2”，否则排序为“参数2”“参数1”。
//  想要升序排列，则return parameter1<parameter2
//  想要降序排列，则return parameter1>parameter2

#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <algorithm>
#include <sstream>

/*
题目描述
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

思路：自定义比较器，若a+b>b+a则a>b，即”3”+”23”>”23”+”3”则3>23，并且我们希望在排序的时候将23排在3的前面，也就是升序排列。
*/

class Solution
{
public:
	static bool compare(const string &s1, const string &s2)
	{
		string ab = s1 + s2;
		string ba = s2 + s1;
		return ab < ba; //升序排序，并且用ab<ba代表s1<s2
	}

	string PrintMinNumber(vector<int> numbers)
	{
		string result;
		if (numbers.size() <= 0)
			return result;

		vector<string> num2str;
		for (int i = 0; i < numbers.size(); i++)
		{
			stringstream ss;
			ss << numbers[i];
			string s = ss.str();
			num2str.push_back(s);
		}
		sort(num2str.begin(), num2str.end(), compare);
		for (int i = 0; i < num2str.size(); i++)
		{
			result.append(num2str[i]);
		}
		return result;
	}
};