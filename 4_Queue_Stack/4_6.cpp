/*
		问题：
			给定一个没有重复元素的数组arr，写出生成这个数组的maxTree函数，要求如果数组长度为N，则时间复杂度为O（N），额外空间复杂度为O（N），maxTree的概念如下：
				1，maxtree是一颗二叉树，数组的每一个值对应一个二叉树节点
				2，包括maxtree在内且在其中的每一颗子树上，值最大的节点都是树的头
		解题思路：
			假设数组是 3 4 5 1 2，对每个元素，我们先列出一个表，分别来统计每个元素，左边第一个大的数，和右边第一个大的数
				左边第一个大的数				右边第一个大的数
				3->null				3->4
				4->null				4->5
				5->null				5->null
				1->5				1->2
				2->5				2->null
			构建规则：
				1，每个元素的父节点，是左边第一个比它大的数和右边第一个大的数中较小的那个。
				2，如果一个元素是整个数组的最大值，则作为树的头结点出现
				3，得到的二叉树为
								5
							4                      2
						3                                            1
				这里我们用栈来寻找每个元素左边第一个大的值和右边第一个大的值
				如有元素3 1 2
				3入栈时，栈空，可以直接入栈
				1入栈时，1<3,直接入栈，此时，1左边第一个大的数为3
				然后2入栈，1弹出，此时得到1右边第一个最大的数为2
				这样类似的，得到每个元素的左边第一个大的数和右边第一个大的值。
*/
#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;
class Array2MaxTree
{
public:
	vector<int> buildMaxTree(vector<int> v,int n)
	{
		stack<int> s;
		//左边第一个大的值
		vector<int> left,res;
		int i;
		//得到每个元素值的左边第一个大的数
		for(i = 0;i<n;i++)
		{
			//如果栈非空且当前元素大于栈顶，则弹出栈顶，直到当前元素的值小于栈顶，方可入栈
			while(!s.empty()&&v[s.top()]<=v[i])
				s.pop();
			//计算要入栈的i的左边第一个大的数，正常是当前的栈顶元素，否则的是-1
			if(s.empty())
				left.push_back(-1);
			else
				left.push_back(s.top());
			//i入栈，如果入栈前栈空，则左边第一个大的数为空，否则为入栈前的栈top
			s.push(i);
		}
		stack<int> st;
		vector<int> right(n,0);
		//得到每个元素值的右边第一个大的数，没有的话是-1
		for(i = n-1;i>=0;i--)
		{
			while(!st.empty()&&v[st.top()]<=v[i])
				st.pop();
			if(st.empty())
				right[i] = -1;
			else
				right[i] = st.top();
			st.push(i);
		}
		//res存放的是每个元素的父节点位置，取左右第一个最大值中较小的那个位置
		for(i = 0; i <n;i++)
		{
			//cout<<right[i]<<endl;
			//cout<<left[i]<<endl;
			//跟节点，
			if(right[i]==-1&&left[i] ==-1)
				res.push_back(-1);
			//选不为空的那个
			else if(right[i] == -1 || left[i] == -1)
				res.push_back(right[i]>left[i]?right[i]:left[i]);
			//选左右第一个最大值中较小的那个
			else
			{
				if(v[right[i]]>v[left[i]])
					res.push_back(left[i]);
				else
					res.push_back(right[i]);
			}
		}
		//res里存放的是传入向量元素的父节点坐标，比如原来向量为{3,1,4,2}，这里得到的res为2 0 -1 2，可以看到4的父节点为-1，即为根节点，3,2，对应的父节点都为2位置上的值，即4，然后1对应的父节点是0位置上的值，即3.
		return res;
	}
};
int main()
{
	int a[4] = {3,1,4,2};
	Array2MaxTree A;
	vector<int> v(a,a+4),res;
	res = A.buildMaxTree(v,4);
	for(vector<int> ::iterator iter = res.begin();iter!= res.end();iter++)
		cout<<*iter<<" ";
	cout<<endl;
	return 0;
}
