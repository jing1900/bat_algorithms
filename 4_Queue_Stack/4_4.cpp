/*		问题：
			一个栈中元素为整型，现想将该栈从顶到底按从大到小排序， 只许申请一个栈，除此之外可以申请新的变量，但不能申请额外的数据结构，如何完成排序。
		解题思路：
			将需要排序的栈记为stack，辅助的栈记为help。
			1，在stack上执行pop操作，弹出的元素记为current，如果current《=当前help栈顶元素，则直接压入help中。如果current》当前help栈顶元素，则先将current放一边，先将help中的元素逐渐弹出，并且重新压回到stack中，直到current《=当前help的栈顶元素，此时放入current
			2，最后，将help中的元素重新压回stack，即可完成从大到小的排序。


*/
#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
class StackSort
{
public:
	vector<int> stackSort(vector<int> v)
	{
		stack<int> s;
		//将传入的向量，逆序放入栈s
		for(vector<int>::reverse_iterator riter = v.rbegin();riter!=v.rend();riter++)
			s.push(*riter);
		//对栈进行排序
		stSort(s);
		//将排好序的内容存入向量res
		vector<int> res;
		while(!s.empty())
		{
			res.push_back(s.top());
			s.pop();
		}
		return res;
	}

	void stSort(stack<int> &s)
	{
		stack<int> help;
		// 在s上执行pop操作，弹出的元素记为current，如果current《=当前help栈顶元素，则直接压入help中。如果current》当前help栈顶元>素，则先将current放一边，先将help中的元素逐渐弹出，并且重新压回到stack中，直到current《=当前help的栈顶元素，此时放入current
		while(!s.empty())
		{
			int current = s.top();
			s.pop();
			if(help.empty()||current<=help.top())
				help.push(current);
			else
			{
				//如果help非空，且当前值大于help的栈顶元素时，就将help的栈顶元素压回s，
				while(!help.empty()&&current>help.top())
				{
					s.push(help.top());
					help.pop();
				}
				help.push(current);
			}
		}
		//将栈help里面的内容重新压回栈s
		while(!help.empty())
		{
			s.push(help.top());
			help.pop();
		}
	}
};
int main()
{
	int a[5] = {1,2,5,4,3};
	vector<int> v(a,a+5),res;
	StackSort S;
	res = S.stackSort(v);
	for(vector<int>::iterator iter = res.begin();iter != res.end();iter++)
		cout<<*iter<<" ";
	cout<<endl;
	return 0;
}
