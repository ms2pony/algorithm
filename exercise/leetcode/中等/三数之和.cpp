#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
using namespace std;
class Solution
{
public:
    /**
     * @brief 使用双指针和排序的方法，使用for循环实现
     * 1. 设三元组的元素的值分别为a,b,c，且a<b<c
     *
     * @param nums 类型为vector<int>
     * @return vector<vector<int>>
     * @require
     */
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res; //所有满足条件的三元组的集合
        vector<int> e;           //临时存放候选三元组的集合
        int i, j, k = 0;
        int preA = INT_MAX, preB = INT_MAX;
        int c = 0;

        //为了减少重复选择的可能性
        sort(nums.begin(), nums.end());

        for (i = 0; i < nums.size(); i++)
        {
            //这次遍历的元素不能等于上次遍历的元素，这是为了避免重复选择三元组
            if (nums[i] == preA)
                continue;
            preA = nums[i]; //下一次枚举时preA就代表上一次枚举的元素

            e.push_back(nums[i]);
            int record = nums.size() - 1; //记录k循环从哪里开始，双指针实现的手段
            //该循环嵌套两层循环，但这两层实质上是并列的，复杂度为O(n)，是双指针的实现
            for (j = i + 1; j < nums.size(); j++)
            {
                //这次遍历的元素不能等于上次遍历的元素，同前面的`if (nums[i] == preA)`等代码段
                if (nums[j] == preB)
                    continue;
                preB = nums[j];

                e.push_back(nums[j]);
                c = -(e[0] + e[1]);
                for (k = record; k > j; k--)
                {
                    //遍历到nums[k] <= c就可以知道此时的a,b没有满足条件的c
                    if (nums[k] <= c)
                    {
                        if (nums[k] == c)
                        {
                            e.push_back(nums[k]);
                            res.push_back(e);
                            e.pop_back(); //吐出来，我要找下一个满足条件的三元组了
                        }
                        else
                            record = k; //不需要从头开始即record=nums.size() - 1，只需要record = k

                        break; //找到一个c就可以停止了，因为a,b确定后，c是唯一的
                    }
                }
                e.pop_back(); //吐出来，我要找下一个满足条件的三元组了
                if (k == j)
                    break;
            }
            e.pop_back(); //同上面的`e.pop_back()`
        }
        return res;
    }
};

int main()
{
    vector<int> input = {-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4};
    Solution sln = Solution();
    vector<vector<int>> res = sln.threeSum(input);
    cout << "finish" << endl;
}