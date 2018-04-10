/*
问题：
	给定彼此独立的两棵树，头节点分别为t1和t2，判断t1中是否有与t2树拓扑结构完全相同的子树。
 解题思路：
	普通解法是二叉树遍历与匹配问题，先遍历二叉树，找到与t2头节点相同的节点时，接下来看结构是否与t2对应，是的话返回true。这样的话，如果t1的大小为N，t2的大小为M的话，时间复杂度为O(N*M）
	但这道题的最优解可以做到O（M+N），这个题表面来看是二叉树问题，实际上是字符串问题。先对t1，序列化成字符串s1，t2也序列化为字符串2，然后判断str1是否包含str2即可。

*/
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<cstdlib>
using namespace std;
vector<char>::size_type n =0;
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){
	}
};
class IdenticalTree
{
public:
	//传入二叉树A，B的头节点，返回B是否在A中
	bool chktree(TreeNode *A,TreeNode *B)
	{
		//二叉树序列化
		string s1 = toString(A),s2 = toString(B);
		//字符串查找
		if(s1.find(s2)!=string::npos)
			return true;
		else
			return false;
	}
	//二叉树的序列化,传入二叉树的根节点，返回序列化后的字符串
	string toString(TreeNode* root)
	{
		string res;
		Serialize(root,res);
		return res;
	}
	//序列化过程,传引用
	void Serialize(TreeNode *root,string &res)
	{
		//如果根节点为空
		if(!root)
		{
			res+="#!";
			return;
		}
		//将根节点的值从int转为字符串
		res+=IntegertoStr((*root).val);
		//递归处理左右子树
		Serialize((*root).left,res);
		Serialize((*root).right,res);
	}
	
	//将整形转为字符串,用！做结束符
	string IntegertoStr(int m)
	{
		//如果m值为0
		if(!m)
			return "0!";
		string res;
		vector<int> temp;
		//将m逐位放入temp，从个位到高位
		while(m)
		{
			temp.push_back(m%10);
			m = m/10;
		}	
		//将temp的内容从高位到低位放入res。
		for(vector<int>::reverse_iterator riter = temp.rbegin();riter!=temp.rend();riter++)
			res.push_back(*riter+48);
		res.push_back('!');
		return res;
	}
};

//用于检验，将定义的字符串转为二叉树
class DeSerialize
{
public:
        //传入序列化向量，和待重建的二叉树头节点，头节点是引用的方式传递（可以直接修改其本身的值）
        void deserialize(vector<char> A,TreeNode* &head)
        {
                int i, j, value = 0;
                //代码最开始初始化了n，为0. 如果A.size = 0或者其第0个元素为#（即空）
                if(n>A.size()-1 || A[n] == '#')
                        //是一颗空的二叉树
                        return;
                i = j = n;
                //统计！之前的这个字符有多少位
                while(A[j] != '!')
                        j++;
                //在这个字符长度之内
                while(j>i)
                {
                        //从高位到地位，将该字符的每一位存入value
                        value = (A[i]-'0')+value*10;
                        i++;
                }
                //分配头结点内存,并给头结点对应元素赋值
                head = (TreeNode *)malloc(sizeof(TreeNode));
                (*head).val = value;
                (*head).right = (*head).left = NULL;
                //将索引往后挪
                n = i+1;
                //递归
                deserialize(A,(*head).left);
                deserialize(A,(*head).right);
        }
};


int main()
{
	//定义序列化的二叉树转为的字符数组
        char a[11] = {'1','2','!','3','!','#','!','#','!','#','!'};
	char b[11] ={'1','2','!','3','!','#','!'};
        //将字符数组转为序列化向量
        vector<char> va(a,a+11);
	vector<char> vb(b,b+7);
        //反序列化：将序列化向量转为二叉树
        DeSerialize d;
        TreeNode* A = NULL;
	TreeNode* B = NULL;
	d.deserialize(va,A);
	d.deserialize(vb,B);
	//测试
	IdenticalTree i;
	bool bl = i.chktree(A,B);
	cout<<bl<<endl;
}
