# 二分查找

## 前提

有序数组

## 关键代码讨论

### 二分查找伪代码模板

```c++
while(left<=right){
  mid=(left+right)/2;
  if(array[mid]==target) return result;
  else if(array[mid]<target) left=mid+1;
  else right=mid-1;
}
```

### 是否不会达到边界即跳不出循环

对于大多数编程语言，`(left+right)/2`是向下取整，向下取整的情况如下：

```c++
//跳不出循环的情况-1
while(left<=right){
  mid=(left+right)/2;
  if(array[mid]==target) return result;
  else if(array[mid]<target) left=mid; //left直接等于mid，会发生跳不出循环的情况
  else right=mid-1;
}
```

```c++
//跳不出循环的情况-2
while(left<=right){
  mid=(left+right)/2;
  if(array[mid]==target) return result;
  //left直接等于mid，会发生跳不出循环的情况
  else if(array[mid]<target) left=mid;
  else right=mid;
}
```

```c++
//跳得出循环的情况-1
while(left<=right){
  mid=(left+right)/2;
  if(array[mid]==target) return result;
  else if(array[mid]<target) left=mid+1;
  else right=mid; //(left+right)/2 只可能等于left而不可能等于right
}
```

```c++
//跳得出循环的情况-1的应用
while (left < right) {
    int mid = left + (right - left) / 2;
    if (isBadVersion(mid)) {
        right = mid;
    } else {
        left = mid + 1;
    }
}
```

### while 循环是否取等号的问题

参考：<https://leetcode.cn/problems/first-bad-version/solution/di-yi-ge-cuo-wu-de-ban-ben-by-leetcode-s-pf8h/> (评论区) k 有关 while 条件是否取等号的问题

1. 不取等号，循环结束条件是 low == high 由于 low == high，因此返回哪一个都可以，因为本题应该默认一定有错误的版本 因此直接返回 low 或者 high 即可，但是在 二分查找某个数值时，**不写等号还要判断 low 位置的元素是否等于目标数**

2. 取等号(之前使用二分查找时是根据区间是左闭右闭或左闭右开来判断是否要取等号的) 在这里说白了就是二分查找求左边界（收缩右边界即可）

## 递归

## 非递归

## 应用-第一个错误版本

## 应用-搜索插入位置

核心公式：

$nums [ pos -1]< target \leq nums [ pos ]$

### 寻找插入位置

参考：<https://leetcode.cn/problems/search-insert-position/solution/sou-suo-cha-ru-wei-zhi-by-leetcode-solution/> (力扣，视频加文字解析的文字部分) k 即如果不存在数组中的时候需要返回按顺序插入的位置，那我们还能用二分法么

插入位置$pos$成立条件为：

$nums [ pos -1]< target \leq nums [ pos ]$

不存在返回插入位置，存在返回数值的位置，两个情况合并得出最后的目标：「在一个有序数组中找第一个大于等于 target 的下标」。
