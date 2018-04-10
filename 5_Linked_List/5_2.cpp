/*
		问题：
			给定一个链表中的节点node，但不给定整个链表的头结点，如何在链表中删除node，请事先这个函数，要求时间复杂度为O（1）。
		解题思路：
			如果是双链表还是比较容易的，节点可以通过pre和next节点，找到想要的节点，删掉这个节点，只需前后节点连接一下即可。
			对于单链表，比如有单向链表1-》2-》3，头节点时不可知的，只知道要删除的是节点2，这时我们只需将节点2的值变成节点3的值，然后删除节点3即可。但这种方法存在一个问题，就是没有办法删除最后一个节点，

*/

#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;
struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x):val(x),next(NULL) {}
};
class RemoveFromList
{
public:
	bool removeNode(ListNode* pNode)
	{
		//无法删除最后一个节点
		if((*pNode).next == NULL)
			return false;
		//pre指针指向要删除的节点，p指针指向要删除节点的下一个节点
		ListNode *p = (*pNode).next,*pre = pNode;
		//p非尾节点
		while((*p).next != NULL)
		{
			//将要删除的节点的下一个节点的值赋给当前要删除的节点
			(*pre).val = (*p).val;
			//将pre挪到原来p的位置
			pre = p;
			//原来的p挪到p的后一个节点，这里用while循环，是保证被删除节点后的每个节点都能往前挪一位。
			p = (*p).next;
		}
		//上面结束时，还需要对结尾处做个处理
		(*pre).val = (*p).val;
		(*pre).next = NULL;
		delete p;
		p = NULL;
		return true;
		
	}
	
};
int main()
{
	return 0;
}
