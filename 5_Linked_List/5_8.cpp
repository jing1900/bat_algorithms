/*
		问题：
			一个链表结构中，每个节点不仅含有一条指向下一个节点的next指针，同时还有一条rand指针，rand指针可能指向任何一个链表中的节点，请复制这种含有rand指针节点的链表。
		解题思路：
			这里我们介绍一种不适用其他数据结构的方法，
			1，如果链表为空，或长度为0，则直接返回空
			2，假设有链表1-》2-》3-》null，其中1的rand到3,2的rand1,3的ran2
			3，首先从链表的头结点开始，根据next指针往下遍历，同时拷贝当前的节点，拷贝的节点rand指向null，拷贝的节点被放在当前节点和下一个节点之间。
			4，再在新的链表中，遍历一下所有节点，但在遍历的过程中，同时拿到两个节点，比如先拿到1和1的复制，然后根据1的rand找到3，然后3的下一个节点就是3的拷贝，因此，可以成功的将1的拷贝的rand指针指向3的拷贝。
			5，然后再拿到2和2的拷贝，通过2的rand指针找到1，同样的，2的拷贝的rand就可以指向1的拷贝。
			6，继续遍历，同理，可以找到3的复制的rand指针指向2的拷贝。
			7，然后将这个大的链表分流成123和1拷贝2拷贝3拷贝即可。

*/
#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
struct RandomListNode
{
	int val;
	struct RandomListNode *next,*random;
	RandomListNode(int x):val(x),next(NULL),random(NULL){} 
};
class CopyComplexList
{public:
	RandomListNode *Clone(RandomListNode* head)
	{
		//如果头结点为空
		if(!head)
			return head;
		//p用来遍历链表
		RandomListNode *p = head,*temp = NULL,*New = NULL;
		//复制每个节点，并插入（理不清就画图）
		while(p)
		{
			temp = (*p).next;
			//用p节点的值新建一个节点。p的复制
			New = new RandomListNode((*p).val);
			//将新copy的节点插入p和p的下一个节点之间
			(*New).next = (*p).next;
			(*p).next = New;
			//继续遍历p
			p = temp;
		}
		//根据原节点的random指针，获取copy节点的random指针
		p = head,New = (*p).next;
		while(p)
		{
			if((*p).random)
				(*New).random = (*(*p).random).next;
			//继续下一对元素和它的拷贝
			p = (*New).next;
			if(p)
				New = (*p).next;
		}
		//分离拷贝和源节点
		p = head,New = (*p).next;
		//拷贝链表的头节点
		RandomListNode* NHead = New;
		while((*New).next)
		{
			temp = (*New).next;
			(*p).next = (*New).next;
			(*New).next = (*temp).next;
			//继续往下走
			p = temp;
			New = (*p).next;
		}
		//设置尾节点
		(*p).next = NULL;
		return NHead;
	}
};
int main()
{
	return 0;
}
























