## 枚举元素，找出最小元素

```c++
int minVal = INT_MAX; //方法一，赋值常数
for (int j = i; j < n; j++)
{
    minVal = min(minVal, nums[j]);
}

int minVal = nums[i]; //方法二，访问一次数组
for (int j = i; j < n; j++)
{
    minVal = min(minVal, nums[j]);
}
```

方法一性能开销较小

## 双指针的实现

可以使用 for 循环，参考 [涉及双指针的代码](..\leetcode\中等\三数之和.cpp) k `for (j = i + 1; j < nums.size(); j++)`(这里使用二层嵌套 for 循环实现双指针)

## 链表增长实现的代码

```cpp
p->next = new ListNode(l1->val + carry);
p = p->next;

// p = p->next;
// p->next = new ListNode(l1->val + carry);
```

分析上面的代码：这两行的顺序决不能颠倒，注释的两行就是颠倒了，颠倒后无法增长链表

## int 转 double

示例如下：

```c++
double operate(int a, int b){
    return (a+b)/2.0;
    //return ((double)a+(double)b)/2;
}
```

解释：被注释掉的 line3`return ...`与 line2`return ...`等价，但是明显后者更简单
