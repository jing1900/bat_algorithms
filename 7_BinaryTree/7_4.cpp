/*
问题：非递归方式实现二叉树的先序中序后序遍历
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
    /*
    非递归前序遍历

    首先申请一个栈
    然后将头结点压入栈
    每次出栈栈顶元素并打印，
    然后如果栈顶元素有右孩子，则入栈
    如果有左孩子，则入栈
    */
    void preOrder(treenode *root,vector<int> &arr)
    {
        if(!root)
            return;
        stack<treenode*> s;
        s.push(root);
        treenode *p = NULL;
        while(!s.empty())
        {
            p = s.top();
            arr.push_back(p->val);
            s.pop();
            if(p->right)
                s.push(p->right);
            if(p->left)
                s.push(p->left);
        }
    }

    /*
    非递归中序：

    先申请一个栈，然后定义一个cur指针，初始化为头节点，
    然后把cur入栈，然后不断让cur= cur.left,将cur入栈
    当cur为空时，此时从stack弹出一个节点，记为node，打印node，并让cur = node.right,然后继续重复步骤2
    当栈为空且cur为空，过程结束
    */
    void inOrder(treenode *root, vector<int> &arr)
    {
        if(!root)
            return;
        stack<treenode *> s;
        treenode *cur = root;

        while(!s.empty() || cur!=NULL)
        {
            while(cur!=NULL)
            {
                s.push(cur);
                cur = cur->left;
            }

            cur = s.top();
            arr.push_back(cur->val);
            s.pop();
            cur = cur->right;

        }
    }

    /*
    非递归后序遍历

    方法1：用两个栈
    首先申请一个栈s1，然后将头结点压入s1，
    从s1中弹出的节点记为cur，然后将cur的左右孩子依次入栈，
    整个过程中，从s1弹出的节点都放入s2，
    不断重复上述过程，直到s1为空，
    然后从s2中弹出并打印即可
    */
    void postOrder(treenode *root, vector<int> &res)
    {
        if(!root)
            return;
        stack<treenode *> s1;
        stack<treenode *> s2;
        s1.push(root);
        treenode *p = NULL;
        while(!s1.empty())
        {
            p = s1.top();
            s1.pop();
            s2.push(p);
            if(p->left)
                s1.push(p->left);
            if(p->right)
                s1.push(p->right);
        }
        while(!s2.empty())
        {
            p = s2.top();
            s2.pop();
            res.push_back(p->val);
        }
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