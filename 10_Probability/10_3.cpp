/*问题：给定一个等概率随机产生1-5的随机函数，除此之外，不能使用任何额外的随机机制，请实现等概率产生1-7的随机函数
给定了一个可调用的Random5::random()方法，可以等概率生成1-5

结题思路：
1~5无法表示1~7，所以我们需要将1~5扩展，形成更大的长度以便容得下1~7

1.R() 函数可以产生 1~~5

2.R()-1 函数可以产生0~~4

3.( R()-1 )*5函数可以产生0、5、10、15、20

4.( R()-1 )*5+R()-1 函数便可以产生0~~24，

这个过程，生成的数如果大于20，则重新生成，直到获取到的数是0~20以内的，那么就相当于把21~~24这部分多出来的概率平摊到了0-20

5. 得到了可以容纳0~20的表达式，然后对其进行模7，0-6,7-13,14-20 模7结果一样，可以产生0~6的表达式

6.最后即对上述进行加1即可。

 C/C++ 中rand()和random()函数

int rand(void);

    返回一个随机数0 ~ pow(2, sizeof(int))-1
long int random(void);

    返回一个随机数0 ~ pow(2, sizeof(long int))-1

用下列公式即可得到指定范围[m,n]的随机数：

r = rand()%(n - m + 1) + m;

*/
#include<bits/stdc++.h>
using namespace std;
class Random5
{
public:
    static int random5()
    {
        return rand()%5+1;
    }
};

class Random7
{
public:
    int random5()
    {
        return Random5::random5();
    }

    int random7()
    {
        int num = (random5()-1)*5 + random5()-1;
        while(num>20)
            num = (random5()-1)*5 + random5()-1;
        num = num % 7 +1;
        return num;
    }
};

int main()
{

    Random7 r7;

    for(int i = 0; i< 50;i++)
    {
        cout<<r7.random7()<<" ";
    }

    cout<<endl;

    return 0;
}