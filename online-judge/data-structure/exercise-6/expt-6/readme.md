## 1 插入排序
先列一下主要的tricky，之后再串起来；
- 需要有一个缓冲元素用来放要移动的数据
- 比较到符合条件之后要把前面的往前面搬运，一边比较一边搬运
- 从后往前比较
![[online-judge/data-structure/exercise-6/expt-6/insertion_sort_visualizer.html]]
大致上就是先从头开始取一个元素我们记为$m$，然后从后往前比较，直到遇到一个数$q$满足$q>m$


## 2 二分插入排序
![[binary_insertion_sort_visualizer.html]]
不明白就是，边比较边移动的性能不是更高吗，为什么要多此一举多做这么一步查找和移动分开？