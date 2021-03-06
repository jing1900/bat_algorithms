/*
问题：n个数进出栈的顺序有多少种？假设栈的容量无限大
给定一个整数n，请返回所求的进出栈的顺序个数，保证结果在int范围内（这种情况通常要mod1000000007）

解法：首先，要出栈必须先进栈，因此这道题的解法和9_8很类似，我们把进栈记为1，出栈记为-1
那么方法数为c(2n,n)-c(2n,n+1) = 1/(n+1)*c(2n,n)
*/