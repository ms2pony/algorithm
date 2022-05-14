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
     * @brief 中间切法v0.2，不适用于：
     * 1. [0,0,0,0,0]，[-1,0,0,0,0,0,1]；[1, 9, 10, 11],[-1, 2, 3, 4]
     * 2. [1, 3, 10, 11]，[-1, 2, 4, 9]；筛选时会超过中位数左边的数的数量
     *
     * @param nums1
     * @param nums2
     * @return double
     * @require
     */
    double findMedianSortedArrays1(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        int index1 = 0, index2 = 0;     // nums1[index1:m]表示当前还在nums中的元素，同理nums2
        int mid1 = 0, mid2 = 0;         //每次中间切的位置
        int leftNums = 0, leftGoal = 0; // leftNums达到leftGoal时，则划分结束，但m+n的奇偶性影响leftGoal
        bool isodd = false;

        if ((m + n) % 2 == 0)
        {
            leftGoal = (m + n) / 2 - 1;
            isodd = false;
        }
        else
        {
            leftGoal = (m + n) / 2;
            isodd = true;
        }

        /**
         * mid1和mid2其中一个在某些情况下一直不变，导致无法找出中位数
         * 而且while循环没有对划分处理时其中一个变为空进行处理
         */
        while (leftNums != leftGoal)
        {
            if (m == 0)
            {
                if (isodd)
                    return nums2[leftNums - m];
                else
                    return (nums2[leftNums - m] + nums2[leftNums - m + 1]) / 2.0;
            }
            if (n == 0)
            {
                if (isodd)
                    return nums1[leftNums - n];
                else
                    return (nums1[leftNums - n] + nums1[leftNums - n + 1]) / 2.0;
            }

            // m-index1为nums1[index1:m]的总数count1(不包括nums1[m])，使用index1+count1/2-1表示mid1，同理mid2
            mid1 = index1 == m - 1 ? m - 1 : index1 + (m - index1) / 2 - 1;
            mid2 = index2 == n - 1 ? n - 1 : index2 + (n - index2) / 2 - 1;
            if (nums1[mid1] <= nums2[mid2])
            {
                leftNums += mid1 - index1 + 1;
                index1 = mid1 + 1;
            }
            else
            {
                leftNums += mid2 - index2 + 1;
                index2 = mid2 + 1;
            }
        }

        if (isodd)
            return min(nums1[index1], nums2[index2]);
        else //偶数真的很难处理
        {
            //需要分别处理筛选后的nums1和nums2的前2个数，一共4个数
            //设nums1的为a1,a2，nums2的为b1,b2;
            int a1 = nums1[index1], b1 = nums2[index2];
            // INT_MAX表示不可能取到
            int a2 = index1 == m - 1 ? INT_MAX : nums1[index1 + 1], b2 = index2 == n - 1 ? INT_MAX : nums2[index2 + 1];
            if (a1 <= b1)
            {
                if (a2 <= b1)
                    return (a1 + a2) / 2.0;
                else
                    return (a1 + b1) / 2.0;
            }
            else
            {
                if (a1 <= b2)
                    return (a1 + b1) / 2.0;
                else
                    return (b2 + b1) / 2.0;
            }
        }
    }
    /**
     * @brief 中间切法v0.1，不适用于：
     * 1. [0,0,0,0,0]，[-1,0,0,0,0,0,1]
     * 2. [1, 4, 9]，[-1, 2, 3] 对m+n为偶数的情况处理不当
     * 3. [1, 3, 10, 11]，[-1, 2, 4, 9] 筛选时会超过中位数左边的数的数量
     *
     * @param nums1
     * @param nums2
     * @return double
     * @require
     */
    double findMedianSortedArrays2(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        int index1 = 0, index2 = 0;     // nums1[index1:m]表示当前还在nums中的元素，同理nums2
        int mid1 = 0, mid2 = 0;         //每次中间切的位置
        int leftNums = 0, leftGoal = 0; // leftNums达到leftGoal时，则划分结束，但m+n的奇偶性影响leftGoal
        bool isodd = false;

        if ((m + n) % 2 == 0)
        {
            leftGoal = (m + n) / 2 - 1;
            isodd = false;
        }
        else
        {
            leftGoal = (m + n) / 2;
            isodd = true;
        }

        //这个if语句一点都不聪明，只能处理刚开始nums1或nums2为空的情况，后面划分时其中一个nums为空则又要重写代码进行处理
        if (m == 0 || n == 0)
        {
            if (isodd)
            {
                return m == 0 ? (double)nums2[n / 2] : (double)nums1[m / 2];
            }
            else
            {
                return m == 0 ? ((double)nums2[n / 2] + (double)nums2[n / 2 - 1]) / 2 : ((double)nums1[m / 2] + (double)nums1[m / 2 - 1]) / 2;
            }
        }

        /**
         * mid1和mid2其中一个在某些情况下一直不变，导致无法找出中位数
         * 而且while循环没有对划分处理时其中一个变为空进行处理
         */
        while (leftNums != leftGoal)
        {
            // m-index1为nums1[index1:m]的总数count1(不包括nums1[m])，使用index1+count1/2表示mid1，同理mid2
            mid1 = (m - index1) / 2 == 0 ? index1 : index1 + (m - index1) / 2 - 1;
            mid2 = (n - index2) / 2 == 0 ? index2 : index2 + (n - index2) / 2 - 1;
            if (nums1[mid1] <= nums2[mid2])
            {
                leftNums += mid1 - index1 + 1;
                index1 = mid1 + 1;
            }
            else
            {
                leftNums += mid2 - index2 + 1;
                index2 = mid2 + 1;
            }
        }

        if (isodd)
        {
            if (nums1[index1] <= nums2[index2])
                return nums1[index1];
            else
                return nums2[index2];
        }
        else // m+n为偶数时，这部分代码有bug
        {
            return ((double)nums1[index1] + (double)nums2[index2]) / 2; //这种进制转换是真的低级
        }
    }

    /**
     * @brief 固定左边数切法，需要配合findMedianSortedArrays函数
     *
     * @param nums1
     * @param nums2
     * @param k
     * @return int
     * @require
     */
    int getKthElement(const vector<int> &nums1, const vector<int> &nums2, int k)
    {
        /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
         * 这里的 "/" 表示整除
         * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
         * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
         * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
         * 这样 pivot 本身最大也只能是第 k-1 小的元素
         * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
         * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
         * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
         */

        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;

        while (true)
        {
            // 边界情况
            if (index1 == m)
            {
                return nums2[index2 + k - 1];
            }
            if (index2 == n)
            {
                return nums1[index1 + k - 1];
            }
            if (k == 1)
            {
                return min(nums1[index1], nums2[index2]);
            }

            // 正常情况
            int newIndex1 = min(index1 + k / 2 - 1, m - 1); //不存在k/2-1为-1的情况，因为前面的代码会处理k=1的情况
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if (pivot1 <= pivot2)
            {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else
            {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1)
        {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
        else
        {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }
};

// int main()
// {
//     vector<int> nums1 = {1, 3, 10, 11};
//     vector<int> nums2 = {-1, 2, 4, 9};

//     Solution sln = Solution();
//     double res = sln.findMedianSortedArrays1(nums1, nums2);
//     cout << res << endl;
// }