/*
		问题：
			实现一个特殊的栈，在实现栈的基础功能的基础上，再实现返回栈中最小元素的操作getmin。
			要求：
				1，pop，push，getMin操作的时间复杂度都为O（1）
				2，设计的栈类型可以使用现成的栈结构。
		解题思路：
			这里我们使用两个栈，一个栈是stackData（保存当前栈中的元素），一个栈是stackMin（保存每一步的最小值）
			方法1：
				举个例子，这里我们要依次压入3 4 5 1 2 1，
				1，对于stackData，每步正常压入即可。但只有当前数小于等于stackmin的栈顶时，才将元素压入stackMin。
				2，弹出时，先在stackData中弹出栈顶元素，记为value，然后判断其与stackMin栈顶元素的大小比较，如果其等于stackmin的栈顶元素时，stackmin弹出栈顶元素。否则，stackmin不弹出
				这样一来，每步操作后，stackmin仍能同步记录栈内元素的最小值
			方法2：
				1，对于stackData，每步正常压入即可，如果当前元素小于stackMin的栈顶，将元素压入stackMin，否则，就重复压入stackmin的栈顶。
				2，弹出时两者同步弹出即可。
			两者的时间复杂度都为O（1），空间复杂度都为O（N），区别在于方案1里面压入稍省空间，弹出略费时间。方案2压入时略费空间，弹出稍省时间。

*/
#include<iostream>
#include<string>
#include<stack>//pop,top,push
using namespace std;
class QueryMinStack
{
public:
	//定义两个栈，一个是源栈，一个是最小值栈
	stack<int> source_stack,min_stack;
	//重新定义push函数，传入：要入栈的元素
	void push(int value)
	{
		//直接调用栈自身带的函数
		source_stack.push(value);
		//最小值栈为空或者当前值小于最小值栈栈顶元素
		if(min_stack.empty()||min_stack.top()>=value)
			min_stack.push(value);
		//否则就放入最小值栈的栈顶元素
		else
			min_stack.push(min_stack.top());
	}
	
	//重新定义pop函数，源栈和最小值栈都要同步pop出栈顶,这里直接调用栈本身的pop方法
	void pop()
	{
		source_stack.pop();
		min_stack.pop();
	}
	//重新定义top函数,返回栈顶元素
	int top()
	{
		return source_stack.top();
	}
	//定义min函数，返回栈中最小元素
	int min()
	{
		return min_stack.top();
	}
};

int main()
{
	QueryMinStack q;
	q.push(3);
	q.push(4);
	q.push(5);
	int c = q.min();
	cout<<c<<endl;
	return 0;
}
