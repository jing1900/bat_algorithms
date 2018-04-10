/*
平衡二叉树，又称AVL树，其具有如下性质
1，空树是平衡二叉树
2，如果一颗树不为空，并且其中所有的子树都满足左子树和右子树的高度差不超过1.

注意，这里是指所有的子树。

问题：给定一个头节点，判断这棵树是不是平衡二叉树


解法：
1，以后序遍历的方式遍历二叉树

2，在遍历左子树时搜集这两个信息，左子树是否为平衡二叉树，和左子树的高度LH

3，如果左子书不是平衡二叉树，直接返回。若是，则继续遍历右子树，也同样搜集这两个信息，
如果右非，返回false，若是，则比较两者的高度，差值大于1，则返回false，否则返回true

这道题的代码着实精妙，需要仔细研读
*/

#include<bits/stdc++.h>
using namespace std;
struct treenode
{
    int val;
    struct treenode *right,*left;
    treenode(int x):val(x),right(NULL),left(NULL){}
};
class CheckBalance
{
public:
    bool check(treenode *root)
    {
        int depth = 0;//统计树深
        return isbalance(root,depth);
    }

    bool isbalance(treenode *root, int &depth)
    {
        if(!root)
        {
            depth = 0;
            return true;
        }
        int left = 0,right = 0,differ = 0;//当前节点左子树树深，右子树树深，树高度差。
        if(isbalance(root->left,left)&&isbalance(root->right,right))//左右子树都是平衡的才需要额外判断，否则，直接返回false
        {
            differ = left -right;
            depth = (left>right?left:right)+1;//统计一颗子树的树深
            if(differ<=1 && differ>=-1)//判断左右两边相差是否小于等于1
                return true;
        }
        return false;
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
    //string str="1!2!4!#!#!5!#!#!3!6!#!#!7!#!#!";
    string str="1!#!3!4!#!#!#!";
    //建树，反序列化
    DeSerialize d;
    treenode *root =NULL;
    queue<int> q = d.string2strArr(str);
    d.deSerialize(q,root);

    CheckBalance c;
    if(c.check(root))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}
