#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;//向左移动的次数，与找到的0有关
        //遍历数组
        int i = 0, j = 0;

        if (n == 1 || n == 0)
            return;

        while (i < n) {
            if (nums[i] == 0 && i < n - 1) {
                count++;
                j = i + 1;
                while (nums[j] != 0 && j < n) {
                    swap(nums[j], nums[j - count]);
                    j++;
                }
                i = j - 1;
            }
            i++;
        }

    }
};

//int main()
//{
//	Solution sln = Solution();
//	vector<int> nums = {0, 1};
//	sln.moveZeroes(nums);
//}