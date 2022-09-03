#include <iostream>
#include<vector>
using namespace std;
#include<algorithm>
#include<numeric>

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> newArr(n);
        for(int i=0;i<n;i++){
            newArr[(i+k)%n]=nums[i];
        }
        nums.assign(newArr.begin(),newArr.end());
    }
};

//参考：https://leetcode.cn/problems/rotate-array/solution/xuan-zhuan-shu-zu-by-leetcode-solution-nipk/ (方法二)
class Solution1 {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        int count=gcd(k,n);
        for(int start=0;start<count;start++){
            int current=start;
            int prev=nums[start];
            do{
                int next=(current+k)%n;
                swap(nums[next],prev);
                current=next;
            }while(start!=current);
        }
    }
};

//空间复杂度为O(1)的方法
//采用两个局部翻转和一个全局翻转
class Solution2 {
public:
    void reverse(vector<int>& nums,int start,int end){
        while(start<end){
            swap(nums[start],nums[end]);
            start+=1;
            end-=1;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);
    }
};