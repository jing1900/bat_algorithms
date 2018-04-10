/*问题：给定一个长度为N且没有重复元素的数组arr和一个整数M，实现函数等概率的打印arr中的M个数。

这里有个很好的等概率打印小技巧，首先从0-n-1中随机定位一个位置a，打印，并将其与n-1位置的数交换
然后从0-n-2里面做同样操作，直到打印m个数。
*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solution(vector<int> arr,int n,int m)
    {
        for(int i = 0;i<m;i++)//执行m次
        {
            int pos = rand()%(n-i);//rand()%n,生成0-n-1的随机数。
            cout<<arr[pos]<< " ";
            int temp = arr[n-1-i];
            arr[n-1-i] = arr[pos];
            arr[pos] = temp;
        }
        cout<<endl;

    }
};

int main()
{
    int n = 7;
    int m = 4;
    int a[n] = {1,2,4,5,6,7,9};
    vector<int> arr(a,a+n);
    Solution s;
    s.solution(arr,n,m);
    return 0;

}