#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
using namespace std;
vector<char>::size_type n =0;
//定义数据结构，树节点
struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL)
		{
	}
};

//二叉树的序列化过程
class Serialize
{
public:
	//传入：二叉树的头结点和序列化后的向量，向量是引用的方式传递（可以直接修改其本身的值）
	void serialize(TreeNode* head, vector<char> &B)
	{
		//如果头节点为空
		if(!head)
		{
			B.push_back('#');
			B.push_back('!');
			return;
		}
		int value = head->val;
		//如果头结点值为空
		if(!value)
		{
			B.push_back('0');
			B.push_back('!');
			//递归求左子树和右子树
			serialize(head->left,B);
			serialize(head->right,B);
			return;
		}
		//处理当前根节点的值value
		int a = 0;
		//将value的值按位存，从个位到高位
		vector<int> A;
		while(value)
		{
			a = value%10;
			A.push_back(a);
			value /=10;	
		}
		//A非空的话,将A中元素从高位到个位push进B
		while(!A.empty())
		{
			a = A.back();
			A.pop_back();
			B.push_back('0'+a);
		}
		//根节点的值按位处理完之后，加！
		B.push_back('!');
		//递归处理根节点的左右子树
		serialize(head->left,B);
		serialize(head->right,B);
		return;
	}
};	

//二叉树的反序列化过程
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

class TreePrinter
{
public:
	//输入：二叉树的根节点（传值的方式），返回：二维向量
	vector<vector<int> > printTree(TreeNode* root)
	{	
		//返回的二维向量
		vector<vector<int> > res;
		//临时向量
		vector<int> temp;
		//存放树节点的队列
		queue<TreeNode*> que;
		que.push(root);
		//当前行的最右节点，下一行的最右节点（即队列中最新加入的元素），当前指向的节点
		TreeNode *last = root,*nLast = NULL,*Now = NULL;
		//如果队列非空
		while(!que.empty())
		{	
			//当前队头元素，要打印的，放入临时向量
			Now = que.front();
			cout<<Now->val;
			temp.push_back(Now->val);
			//如果当前节点有左孩子,让其左孩子入队，并将nlast指向这个最新加入队的元素
			if(Now->left)
			{
				que.push(Now->left);
				nLast = Now->left;
			}
			//如果当前节点有右孩子，
			if(Now->right)
			{
				que.push(Now->right);
				nLast = Now->right;
			}
			//如果当前节点就是当前行的最右节点
			if(Now == last)
			{
				//将临时向量里的这一行内存push入二维向量，并清空临时向量
				res.push_back(temp);
				temp.clear();
				//打印换行，并开始下一行的操作，让last=nlast
				cout<<endl;
				last = nLast;
			}
			//弹出当前队头元素
			que.pop();
		}
		return res;
	}
};

//主函数
int main()
{
	//定义序列化的二叉树转为的字符数组
	char a[11] = {'1','2','!','3','!','#','!','#','!','#','!'};
	//将字符数组转为序列化向量
	vector<char> sor(a,a+11);
	//反序列化：将序列化向量转为二叉树
	DeSerialize d;
	TreeNode* T = NULL;
	d.deserialize(sor,T);
	
	//序列化:将二叉树转为序列化向量
	Serialize c;
	vector<char> res;
	c.serialize(T,res);
	//cout<<'1';
	//打印序列化后的内容
	for(int i = 0; i !=res.size();i++)
		cout<<res[i]<<" ";
	cout<<endl;
	
	//宽度优先打印二叉树
	vector<vector<int> > res1;
        TreePrinter t;
	res1=t.printTree(T);
        for(vector<vector<int> >::iterator iter1=res1.begin();iter1!=res1.end();iter1++)
        {
                for(vector<int>::iterator iter2=(*iter1).begin();iter2!=(*iter1).end();iter2++)
                        cout<<*iter2<<" ";
                cout<<endl;
        }
        return 0;
}

