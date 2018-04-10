/*

蓄水池抽样算法，数据流长度N，水池大小k，
1，对于1-k个数据，直接放入
2，对于第i个数据(i>k),以k/i的概率决定是否放入。若是，则随机抽取k个数据中的一个丢弃，再放入
3，对于第i+1个数，重复执行步骤1or2

保证n个数据中的每个，都是以k/n的概率被选中的
*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> solution(vector<int> arr,int n,int k)//数据流，数据流长度，蓄水池容量
    {
        vector<int> res;
        for(int i = 0;i<n;i++)
        {
            if(i<k)
                res.push_back(arr[i]);
            else
            {
                int r = rand()%(i+1)+1;
                if(r<=k)//k/i的概率替换
                {
                    int pos = rand()%k;//从res的k个元素中随机选一个位置。
                    res[pos] = arr[i];
                }
            }
        }
        return res;
    }
};

int main()
{
    int n;
    cout<<"请输入数据流长度:"<<endl;
    cin>>n;

    vector<int> arr;
    cout<<"请输入数据流："<<endl;
    int t;
    for(int i = 0; i<n;i++)
    {
        cin>>t;
        arr.push_back(t);
    }
    int k;
    cout<<"请输入蓄水池长度:"<<endl;
    cin>>k;
    Solution s;
    vector<int> res = s.solution(arr,n,k);

    vector<int>::iterator iter;
    for(iter = res.begin();iter != res.end();iter++)
        cout<<*iter<<" ";
    cout<<endl;
    return 0;
}