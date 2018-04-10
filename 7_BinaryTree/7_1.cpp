/*
问题：递归实现二叉树的先序，中序，后序遍历，
*/
#include<bits/stdc++.h>
using namespace std;
struct treenode
{
    int val;
    struct treenode *left,*right;
    treenode(int x):val(x),left(NULL),right(NULL){
    }
};
class Solution//这里所有的遍历方法，时间复杂度都是O(N),空间复杂度为O(L),L为二叉树层数
{
public:
    //递归前序遍历
    void preOrder(treenode *root,vector<int> &arr)
    {
        if(!root)
            return;
        arr.push_back(root->val);
        preOrder(root->left,arr);
        preOrder(root->right,arr);
    }

    //递归中序
    void inOrder(treenode *root,vector<int> &arr)
    {
        if(!root)
            return;
        inOrder(root->left,arr);
        arr.push_back(root->val);
        inOrder(root->right,arr);
    }

    //递归后序
    void postOrder(treenode *root,vector<int> &arr)
    {
        if(!root)
            return;
        postOrder(root->left,arr);
        postOrder(root->right,arr);
        arr.push_back(root->val);
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
    string str="1!2!4!#!#!5!#!#!3!6!#!#!7!#!#!";
    //建树，反序列化
    DeSerialize d;
    treenode *root =NULL;
    queue<int> q = d.string2strArr(str);
    d.deSerialize(q,root);

    Solution s;
    //先序
    cout<<"先序遍历结果:";
    vector<int> arr;
    s.preOrder(root,arr);
    for(vector<int>::iterator iter = arr.begin();iter!=arr.end();iter++)
        cout<<*iter<<" ";
    cout<<endl;
    //中序
    cout<<"中序遍历结果:";
    vector<int> arr1;
    s.inOrder(root,arr1);
    for(vector<int>::iterator iter = arr1.begin();iter!=arr1.end();iter++)
        cout<<*iter<<" ";
    cout<<endl;
    //后序
    cout<<"后序遍历结果:";
    vector<int> arr2;
    s.postOrder(root,arr2);
    for(vector<int>::iterator iter = arr2.begin();iter!=arr2.end();iter++)
        cout<<*iter<<" ";
    cout<<endl;


    return 0;
}