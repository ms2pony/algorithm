// 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

#include <iostream>
#include<vector>
using namespace std;
#include<algorithm>

//得到数组中的数平方后直接排序
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for(int num:nums){
            ans.push_back(num*num);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//使用双指针方法解题
//思路：
//1. 原数组是升序。若都是负数，则平方后为降序；若都是整数，则平方后都为升序
class Solution1 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        //要考虑原数组没有负数的情况
        int neg=-1;

        for(int i=0;i<n;i++){
            if (nums[i] < 0) {
                neg = i;
            } else {
                break;
            }
        }

        //下标0-neg都为负数
        // vector<int> ans1,ans2;
        vector<int> ans;
        int i=neg,j=neg+1;

        //利用归并排序的思想将两个有序数组合并为一个有序数组
        while(i>=0||j<n){
            if(i<0){
                ans.push_back(nums[j]*nums[j]);
                j++;
            }
            else if(j==n){
                ans.push_back(nums[i]*nums[i]);
                i--;
            }
            else if(nums[i] * nums[i] < nums[j] * nums[j]){
                ans.push_back(nums[i] * nums[i]);
                i--;
            }else {
                ans.push_back(nums[j] * nums[j]);
                ++j;
            }
        }

        return ans;

    }
};



class Solution2 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int neg;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0)
                neg=i-1;
                break;
        }
        //下标0-neg都为负数
        vector<int> ans1,ans2;
        vector<int> ans;

        for(int i=0;i<=neg;i++){
            ans1.push_back(nums[i]*nums[i]);
        }

        for(int i=neg+1;i<nums.size();i++){
            ans2.push_back(nums[i]*nums[i]);
        }

        //利用归并排序的思想将两个有序数组合并为一个有序数组
        int i=ans1.size()-1,j=0;
        while(i>=0&&j<nums.size()){
            if(ans1[i]>=ans2[j]){
                j++;
                ans.push_back(ans2[j]);
            }else{
                i--;
                ans.push_back(ans1[i]);
            }
        }

        if(i<0){
            for(int rest=j;rest<nums.size();rest++){
                ans.push_back(ans2[rest]);
            }
        }else{
            for(int rest=i;rest>=0;rest--){
                ans.push_back(ans1[rest]);
            }
        }

        return ans;

    }
};

