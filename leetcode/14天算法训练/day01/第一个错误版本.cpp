//参考：https://leetcode.cn/problems/first-bad-version/


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

//自己写的版本，代码冗余
class Solution1 {
public:
    int firstBadVersion(int n) {
        if(n==1)
            return 1;
        if (isBadVersion(1))
            return 1;
            
        long long start = 1, end = n;
        long long mid;
        mid = (start + end) / 2;

        while (end-start>1) {
            //错误版本
            if (isBadVersion(mid))
            {
                end=mid;
                mid = (start + end) / 2;
            }else{
                start=mid;
                mid = (start + end) / 2;
            }
            
        }
        return start+1;
    }
};

//官方版本，简洁
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) { // 循环直至区间左右端点相同
            int mid = left + (right - left) / 2; // 防止计算时溢出
            if (isBadVersion(mid)) {
                right = mid; // 答案在区间 [left, mid] 中
            } else {
                left = mid + 1; // 答案在区间 [mid+1, right] 中
            }
        }
        // 此时有 left == right，区间缩为一个点，即为答案
        return left;
    }
};