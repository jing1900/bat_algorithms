/*
二叉搜索树又称二叉排序数和二叉查找树。

其具有如下特征：每棵子树头节点的值都比格子左子树上的值大，但也都比各自右子数上的所有节点值小

因此，二叉搜索树按中序遍历得到的结果一定是从小到大的。反之，如果一个二叉树的中序遍历
是从小到大的，那它一定是二叉搜索树。

问题：一颗二叉树本来是二叉搜索树，但其中有两个节点交换了位置，使得这颗二叉树不再是二叉搜索树，
请找到这两个错误节点，并返回他们的值，

给定头节点root，其中二叉树中的节点各不相同，请返回两个调换了位置的值，其中小的在前。

拓展：判断一颗二叉树是否是二叉搜索树？

用非递归的中序遍历，遍历每个节点的值，如果一直比上一个节点大，那么是，否则不是。
*/

#include<bits/stdc++.h>
using namespace std;
struct treenode
{
    int val;
    struct treenode *right,*left;
    treenode(int x):val(x),right(NULL),left(NULL){}
};
class FindWrongNum
{
public:
    vector<int> findnum(treenode* root)
    {
        vector<int> res;

        //这里我用了一种最笨的方法来找递增数组中不满足的数，就是再拷贝一份，排序，再一一对比。
        vector<int> s;
        inorder(root,s);
        vector<int> temp(s);//拷贝一份s，排序，
        sort(temp.begin(),temp.end());
        vector<int>::iterator iter1,iter2;

        for(iter1 = s.begin(),iter2 = temp.begin();iter1!=s.end(),iter2!=temp.end();iter1++,iter2++)
        {
            if(*iter1!=*iter2)
                res.push_back(*iter1);
        }
        sort(res.begin(),res.end());
        return res;

    }
    void inorder(treenode *root,vector<int> &res)
    {
        if(!root)
            return;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }

};
/*
反序列化，
先将字符串，转为字符串数组，如"12!3！#！#！#！"->{"12!","3!","#!","#!","#!"},并放入队列中
然后按照先序遍历的顺序建立起整颗二叉树
*/
class DeSerialize
{
public:
    queue<int> string2strArr(string s)
    {
        queue<int> res;
        int b = 0;//每个！隔开的字符串的开始位置
        int l = 0;//该字符串持续长度
        for(int i = 0; i<s.size();i++)
        {
            if(s[i] != '!')
            {
                l++;
            }
            else
            {
                res.push(str2int(s.substr(b,l)));//开始位置和截取长度
                //cout<<str2int(s.substr(b,l))<<endl;
                b = i+1;
                l = 0;
            }
        }
        return res;
    }

    void deSerialize(queue<int> &s,treenode* &root)
    {
        if(s.front() == INT_MIN)//队空
        {
            s.pop();
            return;
        }


        root = new treenode(s.front());
        s.pop();
        deSerialize(s,root->left);
        deSerialize(s,root->right);
    }



    int str2int(string x)//给定字符串12，返回整数12
    {
        if(x == "#")//这里不能少了这个特殊字符的判定
            return INT_MIN;
        int res = 0;
        for(int i = 0;i<x.size();i++)
        {
            res+=int(x[i]-48)*pow(10,x.size()-1-i);
        }
        return res;
    }
};


int main()
{
    string str="4!2!7!#!#!3!#!#!6!5!#!#!1!#!#!";//1,7调换了位置
    //建树，反序列化
    DeSerialize d;
    treenode *root =NULL;
    queue<int> q = d.string2strArr(str);
    d.deSerialize(q,root);

    FindWrongNum f;
    vector<int> res = f.findnum(root);

    for(vector<int>::iterator iter = res.begin();iter!=res.end();iter++)
        cout<<*iter<<" ";
    cout<<endl;
    return 0;
}
