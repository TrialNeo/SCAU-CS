## 1 hash_search
这个题目有定义一个 **hash map**即
$$
	h(k) = 3k\mod\,len  
$$
然后线性散列再探测的公式是
$$
	h(k,i) = \left[h(k) + i\right]\mod{len}
$$
直接对着实现就行了