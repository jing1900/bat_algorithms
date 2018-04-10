/*
		问题：
			编写一个类，只能用两个栈结构实现队列，支持队列的基本操作，add，poll，peek
		解题思路：
			队是先进先出，栈是先进后出。两个栈组合起来，刚好可以实现先进后出。
			一个栈作为压入栈，stackPush，压入时只往这个栈压.还有一个栈作为弹出栈，stackPop，只从这个栈里拿数据。我们只需将stackPush中的内容，一次性的倒入stackPop中即可（如果stackPop不为空，则不能倒数据）。

*/
#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<stdlib.h>
using namespace std;
class TwoStack2Queue
{
public:
	//定义两个栈，一个用来压入，一个用来弹出
	stack<int> stack_push,stack_pop;
	
	//传入一个向量和它的长度，根据其中每一位的正负分情况处理，返回一个处理过的向量
	vector<int> twoStack(vector<int> ope,int n)
	{
		vector<int> res;
		int i;
		for(i = 0; i < n;i++)
		{
			//如果向量中第i个元素大于等于0，则直接push入stack_push栈，
			if(ope[i]>=0)
				push(ope[i]);
				//res.push_back(pop());
			if(ope[i]<0)
				exit(-1);
		}
		//将push栈内容放入pop，并存入res
		res.push_back(pop());
		//将pop栈中的所有元素pop出，并存入res
		while(!stack_pop.empty())
		{
			res.push_back(pop());
		}
		//返回跟入栈顺序相同的向量
		return res;
	}

	//重定义push
	void push(int value)
	{
		stack_push.push(value);
	}

	//重定义pop
	int pop()
	{
		//倒入的前提，一次性倒入，pop栈为空
		if(stack_pop.empty())
			while(!stack_push.empty())
			{
				//这里用的是栈自带的函数
				stack_pop.push(stack_push.top());
				stack_push.pop();
			}
			//pop出栈顶元素
			int res = stack_pop.top();
			stack_pop.pop();
			
			return res;
	}
	
};
int main()
{
	int a[6] = {1,2,3,0,4,0};
	vector<int> arr(a,a+6);
	TwoStack2Queue T;
	vector<int> res = T.twoStack(arr,6);
	for(vector<int>::iterator iter = res.begin();iter!=res.end();iter++)
		cout<<*iter<<" ";
	cout<<endl;
	return 0;
}
