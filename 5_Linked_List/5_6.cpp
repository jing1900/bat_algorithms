/*
		问题：
			给定一个单链表的头结点head，链表中的每个节点保存一个整数，再给定一个值val，把所有等于val的节点删掉
		解题思路：
			我们把整个过程看做一个构造链表的过程，假设之前的链表的头是head，尾是tail。
			1，如果当前节点的值是val，就抛弃它，否则将其接到链表的末尾，如果有新的要接入，直接插到之前值和尾部之间即可，最后设置null为尾部
2，要注意特殊情况，和边界问题。
*/
#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
class RemoveGivenValue
{
public:
	//传入链表，和要删除的值，返回，删除掉指定值后的链表
	ListNode* remove(ListNode* head,int val)
	{
		if(!head)
			return head;
		ListNode *Head= NULL,*Tail = NULL,*p = head,*temp = NULL;
		while(p)
		{
			temp = (*p).next;
			//如果当前节点的值等于要删除的值，那么删除该节点
			if((*p).val == val)
				delete p;
			//否则，将该节点链接到一个新的链表
			else
			{
				//如果新的链表为空，那么头节点设置为p
				if(!Head)
					Head = p;
				else
					//加到链表尾部
					(*Tail).next = p;
				//将p设为新的Tail
				Tail = p;
				(*Tail).next = NULL;
			}
			//沿着next指针继续往下遍历链表
			p = temp;
		}
		return Head;
	}
	
};
//创建链表，打印链表
class CreateListNode
{
public:
	ListNode* Create(vector<int> A)
	{
		if(A.empty())
			return NULL;
		ListNode *Head=new ListNode(A[0]),*p=Head;
		for(vector<int>::iterator iter=A.begin()+1;iter!=A.end();iter++)
		{
			(*p).next=new ListNode(*iter);
			p=(*p).next;
		}
		return Head;
	}
	void Print(ListNode* Head)
	{
		ListNode *p=Head;
		while(p)
		{
			cout<<(*p).val<<" ";
			p=(*p).next;
		}
		cout<<endl;
	}
};
int main()
{
	int a[7]={1,2,3,4,3,2,1};
	vector<int> arr(a,a+7);
	CreateListNode C;
	ListNode *HeadA=C.Create(arr);
	RemoveGivenValue R;
	ListNode *head = R.remove(HeadA,2);
	C.Print(head);
	return 0;
}
