## 溢出问题

```c++
//可能会超过mid表示范围，发生溢出
mid=(right+left)/2
//这种方式求中位数不会发生溢出
mid=(right-left)/2
```
