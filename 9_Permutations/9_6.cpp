/*
问题：
六个人排成一排，要求甲乙不相邻，甲丙也不相邻，求多少种排法？


首先六个人的全排有6！，
然后计算甲乙相邻的概率。甲乙or乙甲，2*5！
然后计算甲丙相邻的概率，也是2*5！
上面有重叠的地方，就是乙甲丙or丙甲乙相邻出现的情况，这种情况将三者看做一个整体，有2*4！种
因此 6！-2*5！-2*5！+2*4！种

A（也是他的编号）是一个孤傲的人，在一个n个人的队列中，它跟编号为b，c的人有矛盾，所以他不会yu其
站在相邻的位置，问满足A要求的队列有多少种
给定人数n和三个人的标号a，b，c，求返回所求答案
*/