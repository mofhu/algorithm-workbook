3-2: float 的精度在多步计算后不足, 尽量用 double. 本题仅到 .3f 即有误差了.
5-1: 二维数组传值之后用两个 += 但是很诡异的只能 += 一次. 改为新建变量避免了这个问题.
eg-5-5: 这个 map 的黑科技厉害... 一个数据结构表示了嵌套的集合与子集. 学习.
eg-5-7: 序列既不是 set 也不是 pq, 而是 pq pop 出来的序列.
5-6: pair.first / .second; iterator++/-- 均可用, 但 +1 -1 不好用.

memset: `memset(a, 0, sizeof(a))` 注意: 只能初始化为 0 或 -1 !!(因 memset 逐字节进行) (不要把后两个变量写反...)

## io notes

刷题时考虑方便和稳定

可用的手段:

- cstdio: `scanf`, `printf`, `getchar`, `getline`
- iostream: `cin >>`, `cout <<`
- string
- stringstream

- getchar, getline, scanf("%c"): 会读入只剩换行符或空白的行(比如已经scanf读取过数字的行), 尽量不使用.
- `cin >> string` 就安全很多, 不会意外读入空行
- 数字用 `scanf("%d")` 等读入
- 读入整行时, `getline(cin, str)` 也可以(因 cin >> string 会被空格打断)
- 需要返回值时 scanf 比 cin 流更好用

eg-5-1: sort array s[n]: sort(s, s+n). sort(begin, end) 的序列中 end 不参与排序
即只排序 [begin, end). 这里的end 指向末尾元素的下个位置
ref: http://www.cplusplus.com/articles/NhA0RXSz/
