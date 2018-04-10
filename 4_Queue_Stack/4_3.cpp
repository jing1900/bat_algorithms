/*
		问题：
			实现一个栈的逆序，但只能用递归函数和这个栈本身的操作来实现，不能自己申请另外的数据结构。
		解题思路：
			首先实现一个递归函数，get(). 用来移除栈底的元素并返回。其思想是，
				1, 如果有元素1 ，2 ，3.第一层递归函数弹出栈顶元素1，然后将栈传入第二层递归函数。
				2，第二层递归函数弹出栈顶2，然后将栈传给第三层递归函数
				3，第三层递归函数弹出栈顶3，然后发现栈空了，就返回3做为第三层递归函数的结果
				4，第二层递归函数，得到第三层递归函数的返回值，然后将自身弹出的值压入原来的栈，并将第三层的递归函数返回值再传给第一层
				5，第一层同样的将自身的内容压入栈，并返回第三层的递归函数返回值作为整个函数的返回值。
			然后再实现一个递归函数，reverse（）。用于整体的逆序
				1，如果有元素1,2,3，第一层递归函数调用get方法，弹出并返回栈底元素3，此时栈变成【1,2】
				2，第二层递归函数同样调用get，返回2，此时栈变成【1】
				3，第三层函数调用get，返回1，此时栈空
				4，然后第三层栈空之后，将返回值压入栈，并将栈传给第二层
				5，第二层同样的将返回值压入栈，再将栈传给第一层
				6，第一层同样的将返回值压入栈，这样就得到了 3 2 1的逆序栈。
*/
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<stdlib.h>
using namespace std;
class ReverseStack
{
public:
	vector<int> reverseStack(vector<int> A,int n)
	{
		stack<int> sta;
		int i;
		//将向量A中的元素逆序放入栈sta，向量123变为栈（顶）123（底）
		for(i = n-1;i>=0;i--)
			sta.push(A[i]);
		//对栈sta进行逆序，栈123变为321
		rStack(sta);
		vector<int> res;
		//将逆序后的sta，里面的元素，依次放入新的向量res,321
		while(!sta.empty())
		{
			res.push_back(sta.top());
			sta.pop();
		}
		//返回逆序的向量res
		return res;
		
	}
	
	//stack整体的逆序
	void rStack(stack<int> &A)
	{
		if(A.empty())
			return;
		//获取栈底元素3，同时栈变为12
		int res1 = Get(A);
		//递归
		rStack(A);
		//递归到栈空，就将最后一次的递归返回值压入栈
		A.push(res1);
	}

	//get函数：移除栈底元素并返回
	int Get(stack<int> &A)
	{
		if(A.empty())
			exit(-1);
		//获取栈顶元素
		int res1= A.top();
		A.pop();
		//如果获取后栈为空，直接返回
		if(A.empty())
			return res1;
		//否则的话，递归
		else
		{
			//将上一层递归的结果作为返回值返回
			int res2 = Get(A);
			//并将自身弹出的元素压回栈
			A.push(res1);
			//返回上一层递归的结果
			return res2;
		}
	}
};

int main()
{
	int a[4] = {4,3,2,1};
	vector<int> arr(a,a+4),res;
	ReverseStack R;
	res = R.reverseStack(arr,4);
	for(vector<int>::iterator iter = res.begin();iter!=res.end();iter++)
		cout<<*iter<<" ";
	cout<<endl;
	return 0;
}
