/*
问题：2n个人买票，n个人拿5块，n个人拿10块，票价是5块一张，每人买一张票，售票员手里没有零钱，问有多少种方法能让售票员顺利卖票
给定要给整数n，返回所求的方案个数

解法：这道题仍然跟括号合法的排列数类似，拿5块的记为1，拿10块的记为-1.
方法数为c(2n,n) - c(2n,n+1) = 1/n+1 * c(2n,n)
*/