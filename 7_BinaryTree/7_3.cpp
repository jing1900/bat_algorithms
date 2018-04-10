/*
问题：二叉树的序列化和反序列化。
给定头结点head，并且已知二叉树节点值类型为32位整形。

解法：
用先序遍历对二叉树进行序列化和反序列化

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
/*
序列化时，先假设序列化结果为str，初始时str为空串
先序遍历二叉树，如果遇到空节点，就在str末尾加上“#！”
遇到不为空的节点，就在末尾加上“节点值！”
加叹号是为了防止歧义
*/
class Serialize//序列化
{
public:
    string tree2string(treenode *root)
    {
        string res = "";
        if(!root)
            return res;
        serialize(root,res);
        return res;
    }
    string int2str(int x)//将整数转为“21!”的形式
    {
        if(x == 0)
            return "0!";
        string res = "";
        vector<char> v;
        //先得到x的从个位到高位的值，放入v
        while(x>0)
        {
            v.push_back(char(x%10+48));//char(1+48),可以转为字符形式的1
            x = x/10;
        }
        //反序，即从高位到低位将数字字符加入res
        vector<char>::reverse_iterator iter;
        for(iter = v.rbegin();iter!=v.rend();iter++)
            res+=*iter;
        res+="!";
        return res;
    }
    void serialize(treenode *root,string &res)
    {

        if(!root)
        {
            res += "#!";
            return;
        }
        res+=int2str(root->val);
        serialize(root->left,res);
        serialize(root->right,res);
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

class PrintTree//按层打印
{
public:
    vector<vector<int> > solution(treenode *root)
    {

        vector<vector<int> > res;
        if(!root)//处理特殊情况
            return res;

        queue<treenode *> q;
        q.push(root);

        treenode *last = root;
        treenode *nlast = NULL;
        treenode *p = NULL;

        vector<int> r;//可以放外面
        while(!q.empty())
        {

            p = q.front();//这里是front
            q.pop();

            if(p->left)
            {
                q.push(p->left);
                nlast = p->left;

            }
            if(p->right)
            {
                q.push(p->right);
                nlast = p->right;
            }
            r.push_back(p->val);
            if(p == last)
            {
                last = nlast;
                res.push_back(r);
                r.clear();//清空vector r
            }
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

    //按层打印
    cout<<"二叉树层次遍历结果:"<<endl;
    PrintTree p;
    vector<vector<int> > res = p.solution(root);
    for(vector<vector<int> >::iterator iter = res.begin();iter!=res.end();iter++)
    {
        vector<int> temp = *iter;
        for(vector<int>::iterator it = temp.begin();it!=temp.end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    //序列化
    cout<<"二叉树序列化结果:"<<endl;
    Serialize s;
    string str1 = "";
    s.serialize(root,str1);
    cout<<str1<<endl;


    return 0;
}