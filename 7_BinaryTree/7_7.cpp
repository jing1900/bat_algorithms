/*
什么是满二叉树？

满二叉树除了最后一层的节点无任何子节点外，剩下的每一层上的节点都有两个子节点。
如果其层数为L，节点数为N，那么N = 2^L-1; L = log2(n-1)

完全二叉树是指，除了最后一层之外，其他每一层的节点数都是满的，如果最后一层也满了，及时满二叉树，也是完全儿茶素。
最后一层如果不满，缺少的节点也都集中在左边，也是完全二叉树

问题：给定一个二叉树头节点head，判断是否为完全二叉树。

解法：
1,按照层次遍历的顺序
2，如果当前节点有右孩子，没有左孩子，则直接返回false
3，如果当前节点不是左右孩子都有，那么之后的节点必须都为叶子节点
4，遍历过程中如果不返回false，遍历结束后返回true。
*/
#include<bits/stdc++.h>
using namespace std;
struct treenode
{
    int val;
    struct treenode *right,*left;
    treenode(int x):val(x),right(NULL),left(NULL){}
};
class CheckFullTree
{
public:
    bool checkFullTree(treenode *root)
    {
        if(!root)//特殊情况判断
            return true;
        queue<treenode*> q;
        q.push(root);
        treenode *now = NULL;
        while(!q.empty())
        {
            now = q.front();
            q.pop();
            if(now->left == NULL &&now->right!=NULL)//2中的情况
                return false;
            if(now->left)
                q.push(now->left);
            if(now->right)
                q.push(now->right);

            if(!(now->left) || !(now->right))//3中的情况，没有左子树or没有右子数
                break;//break掉，判断队列中剩下的元素是否都是叶子节点
        }
        while(!q.empty())
        {
            now = q.front();
            q.pop();
            if(now->left || now->right)//非叶子节点
            {
                return false;
            }
        }

        return true;

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

    //判断是否为完全二叉树
    CheckFullTree c;
    if(c.checkFullTree(root))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}