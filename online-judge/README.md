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


