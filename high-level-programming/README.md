# 个人物品管理程序

## 前言

本项目为转专业后的一次大的实验作业，高级语言程序设计，写出来放上 GitHub以供老师审批、后人参考，如有问题请题issue。

## 规范

个人物品管理程序（英文：Personal Belongings Management，为了方便，以后在项目和其他地方都简称为：PBM）

参照自己以往项目的文件命名规范[TrialNeo/Digghper: 后端开发的“毛胚房”，接入gorm+fiber+jwt+redis,实现web后端+scheduled job，“插件式”插拔开发，易拓展](https://github.com/TrialNeo/Digghper)README中的项目规范

文件开头需要有创建时间，创建人

**函数变量常量等**命名方式使用**下划线命名方法**，而且全小写，别用驼峰命名了（用习惯驼峰了，但是这里是c/cpp）。

由于c语言只能面向过程，限制特定对象的方法统一规范命名为：type_operation(&T,…..)

## 文件夹说明

2

| file_path | desc     |
| --------- | -------- |
| menu      | 菜单模块 |

## 数据相关

### 持久化存储

这点可以参考csv的文件格式，之前用pandas.read_csv其实还挺好用的

````txt
item,item
item2,item2
````

这个其实也不太好用，其实利用tlv更加适合计算机,t这里可以做一下精简只用一个字节来存

我们可以稍稍魔改一下，因为本身需要用到的类型也就string,unsigned long,bool这几个，顶天了也就用到一个字，但是另一个字不就浪费了吗，而且len一般是用两个字节的。

这可不行，可以在type这里拿一个字存一下下面的len是两个字节还是一个字节还是根本就用不上，这就是时间复杂度换空间复杂度了，但是毕竟是持久化存储嘛还是值得的。





## 登录方面

*这里要做一个小小的加密，不然让别人盗用密码就不好了









## 开发工具

CLion

cmake version 3.31.5

gcc version 14.2.0 (MinGW-W64 x86_64-ucrt-posix-seh, built by Brecht Sanders, r3) 



## 构建

### dev

其实CMakeLists已经写好了，每次最多写一个

```cmd
cmake --build .
PBM.exe
```



## 参考的资料

- Handbook of applied cryptography (Alfred Menezes, Paul van Oorschot etc.)
- [CMAKE学习——编译多个文件 & 多个目录_多文件夹编译cmake-CSDN博客](https://blog.csdn.net/dyyzlzc/article/details/105189374)
- [C语言下的清屏函数_#ifdef to gt checkdensityto fill = density to >0-CSDN博客](https://blog.csdn.net/lopper/article/details/5062960)
- [什么是TLV格式？TLV编码格式解析：一种灵活可扩展的自定义网络/串口/总线通信协议，数据表示方式在现代计算和通信系统中 - 掘金](https://juejin.cn/post/7499013941126168576)
- [TrialNeo/Digghper: 后端开发的“毛胚房”，接入gorm+fiber+jwt+redis,实现web后端+scheduled job，“插件式”插拔开发，易拓展](https://github.com/TrialNeo/Digghper)
- 
