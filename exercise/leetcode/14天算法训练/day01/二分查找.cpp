#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        //双指针
        int start = 0, end = nums.size() - 1;
        int mid;
        mid = (start + end) / 2;
        while (end >= start) {
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
            {
                start = mid + 1;
                mid = (start + end) / 2;

            }
            else {
                end = mid - 1;
                mid = (start + end) / 2;
            }
        }
        return -1;
    }
};

// int main(){
//     Solution sln = Solution();
//     vector<int> nums = {-1,0,3,5,9,12};
//     int target=9;
//     int res=sln.search(nums,target);
//     cout << res << endl;
// }