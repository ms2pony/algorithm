//参考：https://leetcode.cn/problems/search-insert-position/solution/sou-suo-cha-ru-wei-zhi-by-leetcode-solution/

//官方版本
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1, ans = n;
        while (left <= right) {
            int mid = ((right - left) >> 1) + left;
            if (target <= nums[mid]) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

//比官方更优版本
//解析：
// 不需要ans变量，最后直接返回left就可以了，
// 根据if的判断条件，left左边的值一直保持小于target，right右边的值一直保持大于等于target，而且left最终一定等于right+1，
// 这么一来，循环结束后，在left和right之间画一条竖线，
// 恰好可以把数组分为两部分：left左边的部分和right右边的部分，而且left左边的部分全部小于target，并以right结尾；
// right右边的部分全部大于等于target，并以left为首。所以最终答案一定在left的位置。
class Solution1 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]<target)
                l=mid+1;
            else r=mid-1;
        }
        return l;
    }
};