#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

//官方方法，原地解法，感觉比我的方法复杂了些
class Solution
{
public:
	string reverseWords(string s)
	{
		int n = s.length();
		int i = 0;
		while (i < n)
		{
			int start = i;
			while (i < n && s[i] != ' ')
			{
				i++;
			}

			int left = start, right = i - 1;
			while (left < right)
			{
				swap(s[left], s[right]);
				left++;
				right--;
			}

			while (i < n && s[i] == ' ')
			{
				i++;
			}
		}
	}
};

class Solution1
{
public:
	string reverseString(string s)
	{
		int n = s.length();
		int left = 0, right = n - 1 - 0;
		while (left <= right)
		{
			swap(s[left], s[right]);
			left++;
			right--;
		}
		return s;
	}
	string reverseWords(string s)
	{
		s += " ";
		int pos = 0;
		string s1;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ' ')
			{
				s1 = s.substr(pos, i - pos);
				s1 = reverseString(s1);
				s.replace(pos, i - pos, s1);
				pos = i + 1;
			}
		}
		return s.substr(0, s.length() - 1);
	}
};

//int main()
//{
//	Solution sln = Solution();
//	string s = "Let's take LeetCode contest";
//	cout << sln.reverseWords(s);
//}