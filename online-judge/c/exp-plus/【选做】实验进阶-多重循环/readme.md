## 11152 搬砖问题

### Description
一个大男人一次可以搬3块砖，一个大女人一次可以搬2块砖，两个小孩一次可以搬1块砖，现由键盘输入总人数n以及总砖数m，问有多少种不同的分配方案
正好n个人一次搬完所有的m块砖(无闲人且每人满负荷)，没有这样的方案则输出no

### 输入格式
n及m，以空格分隔
### 输出格式
方案数或no
### 输入样例
45 45

### 输出样例
4

### 分析

这是一个三元一次方程吗？？
$$
\left\{
\begin{matrix}
&3x+2y + 0.5z = m \\
&x+y+z=n
\end{matrix}
\right.
$$
换成矩阵
$$
\left[
\begin{matrix}
3&2&0.5&m\\
1&1&1&n \\
\end{matrix}
\right]
\sim
\left[
\begin{matrix}
5&3&0&2m-n\\
1&1&1&n \\
\end{matrix}
\right]
$$
直接遍历$x,y,z$就行了