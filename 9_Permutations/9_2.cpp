/*
问题：求n个无差别的节点构成的二叉树有多少种不同的结构

解法：
假设n个无差别的节点构成的不同结构数为f(n)
当n=0时，只有空树一种可能，f(0)=1,
n =1 时，也只有一种可能,f(1) = 1;
n = 2,f(2) = 2;
n = 3,f(3) = 5
现在我们把n个节点排成一排，
如果把第一个节点当做头，那么左子树为空（1种方法），右子树为剩下的n-1个节点。（f(n-1种方法），此时方法数为f(0)×f(n-1)
如果第二个节点为头，那么左子树为1,(1种方法），右子树为剩下的n-2个节点，则方法数为f(1)×f(n-2)
以此类推，第n个节点为头，那么左子树为f(n-1),右子树为f(0),方法数为f(n-1)*f(0)

加起来就是f(0)*f(n-1)+f(1)*f(n-2)+f(2)*f(n-3)+...+f(n-1)*f(0) = 1/(n+1) * c(2n,n)

以上，就是卡特兰数的一个性质，如果f0 = 1，f1 = 1,f2 = 2,f3 = 5,
且f(n) = f(0)*f(n-1)+f(1)*f(n-2)+f(2)*f(n-3)+...+f(n-1)*f(0)
那么就可以化简为1/(n+1) * c(2n,n)

因此，结构数为1/(n+1)*c(2n,n)
*/