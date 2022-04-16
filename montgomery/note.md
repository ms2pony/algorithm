# note

## 概述

蒙哥马利乘法避免了传统模乘运算中耗时的除法运算，传统的模乘算法的约减阶段需要试除
参考：[MMWT1985.pdf](ref\MMWT1985.pdf) (该论文十分精炼短小，分为蒙哥马利算法描述，多精度下的算法，硬件实现这三个部分)

计算 $c = z R^{-1} \bmod p$，蒙哥马利乘法的数学表达式为：

$$
c \leftarrow\left(z+\left(z p^{\prime} \bmod R\right) p\right) / R, \\
if\  c \geq p \ then\  c \leftarrow c-p,
$$

R 是 2 的 n 次幂，所以在计算机中只需要移位操作。全程没有除法的通俗原因是 $z$ 通过加一个数 $(z p^{\prime} \bmod R) \times p$，使其在移位(除 R)时不会发生数值损失。

## 多精度表示下的蒙哥马利算法的疑问解决
