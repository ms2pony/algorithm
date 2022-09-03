#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

class Solution
{
public:
	vector<int> twoSum(vector<int> &numbers, int target)
	{
		for (int i = 0; i < numbers.size(); i++)
		{
			//为了避免重复寻找，在寻找第二个数时，只在第一个数的右侧寻找。
			int low = i + 1, high = numbers.size() - 1;
			while (low <= high)
			{
				int mid = (high - low) / 2 + low;
				if (numbers[mid] == target - numbers[i])
				{
					return {i + 1, mid + 1};
				}
				else if (numbers[mid] > target - numbers[i])
				{
					high = mid - 1;
				}
				else
				{
					low = mid + 1;
				}
			}
			return {-1, -1};
		}
	}
};

class Solution1
{
public:
	int twoSearch(vector<int> &nums, int left, int right, int target, int res1)
	{
		int mid;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (nums[mid] == target && res1 != mid + 1)
				return mid + 1;
			else if (nums[mid] < target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return -1;
	}

	vector<int> twoSum(vector<int> &numbers, int target)
	{
		int n = numbers.size();
		vector<int> res(2);
		for (int i = 0; i < n; i++)
		{
			res[0] = i + 1;
			int a = target - numbers[i];
			res[1] = twoSearch(numbers, 0, n - 1, a, res[0]);
			if (res[1] == -1)
			{
				continue;
			}
			else
			{
				break;
			}
		}
		if (res[0] > res[1])
			swap(res[0], res[1]);
		return res;
	}
};