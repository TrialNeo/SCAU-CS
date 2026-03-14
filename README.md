# 华南农业大学 Online Judge答案
## 写在前面的话

我们OJ的地址是：https://xxx.scau.edu.cn/xxx8008 (为了防止学校被DDOS)

函数名可能有时候不是很规范，c题号这一类的，如果需要直接改成int main就行了，不碍事的。。

算法很重要是看清楚每一步在做什么，怎么将孤立的东西找出共通性从而相互联系起来。


## 题目提取JS
只要Description到输出样例（闭区间）
```javascript
let titles = document.getElementsByTagName("h1")
let pres = document.getElementsByTagName("pre")
let output = ""
for(let i = 0;i<pres.length;i++){
output += titles[i+2].innerText+ "\n\t"+pres[i].innerText+"\n"
}
console.log(output)
```



## 目录说明

| path_name            | description  |
| -------------------- | ------------ |
| [PREx](TextBook)         | 教材练习     |
| [exp-plus](exp-plus) | 进阶练习     |
| exp4-exp10           | 实验4-实验10 |


## 某些题目注释

这些是个人写的过程中的一些题目感觉到比较有意思的记录，可供参考。

### GCD

求最大公约数其实是一个二阶递推公式，其中：

```math
x_{n} = x_{n-2}\,\%\,x_{n-1}\quad(x_n \neq 0,n \geq 3)
```


所以可以用数列的方法来写[1029-求最大公约数.c](exp5/class/1029-求最大公约数.c) 


### 18048 自由落体的数学推导
[18048-自由落体.c](TextBook/5/18048-%E8%87%AA%E7%94%B1%E8%90%BD%E4%BD%93.c)

其实可以用数学来做感觉比较舒服一点

**假设第1次是第0次弹起后的，最后再减掉就行了。**
所以弹起高度就是

$$
100 \to 50 \to 25 \to 12.5 \to\dots
$$

很明显就是一个等比数列，让 $a_{n}$ 为第n次弹起后的高度 $n>1$

$$
a_{n} = 100\times \left(\frac{1}{2}\right)^{n}
$$

经过的距离呢注意假设”**假设第1次是第0次弹起后的，最后再减掉就行了**。“

| 0   | 200 | $+2\times100$ |
| --- | --- | ------------- |
| 1   | 300 | $+2\times50$  |
| 2   | 350 | $+2\times25$  |

$$
D_{n}+100 = 2a_{1} + 2a_{2} +\dots + 2a_{n} =2S_{n}
$$

根据等比数列和公式

$$
S_{n} = \frac{100\left( 1-\left( \frac{1}{2} \right)^{n} \right)}{1-\frac{1}{2}} =200\left( 1-\left( \frac{1}{2} \right)^{n} \right) = 200-200\left( \frac{1}{2} \right)^{n}
$$

代入

$$
D_{n} = 300-400\left( \frac{1}{2} \right)^{n}
$$
