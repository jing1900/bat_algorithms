/*
		问题：
			给定一个链表的头节点head，再给定一个数num，请把链表调整成节点值小于num的都放在链表的左边，值等于num的节点都放在链表的中间，值大于num的节点，都放在链表的右边。
		解题思路：
			简单的思路，是将链表中的值都放在一个数组里，然后对数据中的元素做类似快排划分的过程。然后将数组中的元素重新串联。
			最优解：在遍历链表的过程中，将链表分为3个小链表，分别是值小于num的节点组成的链表，值等于num的节点组成的链表，和值大于num的节点组成的链表。最后再把这三条链表整体的连接起来

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
	ListNode(int x):val(x),next(NULL){}
};
class DivideList
{
public:
	//传入，链表头节点，和要划分的节点值，返回链表头节点
	ListNode* listDivide(ListNode * head,int val)
	{
		ListNode *smallHead = NULL,*smallTail = NULL,*bigHead = NULL,*bigTail=NULL,*p = head,*q = head;
		while(p)
		{
			q = p;
			//p沿着next往下遍历，当p处的元素值小于等于划分值
			if((*p).val<=val)
			{
				//如果小链表为空，则将其链表头尾都设为p
				if(!smallHead)
					smallHead = smallTail = p;
				//否则，将p加到小链表尾部，并将p设为链表尾部
				else
				{
					(*smallTail).next = p;
					smallTail = p;
				}
			}
			//p处的元素大于划分值
			else
			{
				//如果大链表为空，则将其链表头尾都设为p
				if(!bigHead)
					bigHead = bigTail = p;
				//否则，将p加到链表尾部，并将p设为链表尾部
				else
				{
					(*bigTail).next = p;
					bigTail = p;	
				}
			}
			//p沿着next继续往下走
			p = (*p).next;
			//？？
			(*q).next = NULL;
		}
		//如果小链表非空，则将其链表头设为整合后的链表头，
		if(smallHead)
		{
			head = smallHead;
			//如果大链表非空，整合到小链表的后边
			if(bigHead)
				(*smallTail).next = bigHead;
		}
		else
			if(bigHead)
				head = bigHead;
		return head;
	}
};
class CreateListNode
{
public:
	//根据向量创建链表。
	ListNode* create(vector<int> A)
	{
		if(A.empty())
			return NULL;
		ListNode *Head = new ListNode(A[0]),*p = Head;
		for(vector<int>::iterator iter = A.begin()+1;iter!=A.end();iter++)
		{
			(*p).next = new ListNode(*iter);
			p = (*p).next;
		}
		return Head;
	}
	//打印链表内容
	void Print(ListNode* Head)
	{
		ListNode *p = Head;
		while(p)
		{
			cout<<(*p).val<<" ";
			p = (*p).next;
		}
		cout<<endl;
	}
};
int main()
{
	int a[5] = {1620,1134,861,563,1};
	vector<int> arr(a,a+5);
	CreateListNode C;
	ListNode *Head = C.create(arr);
	DivideList D;
	Head = D.listDivide(Head,1134);
	C.Print(Head);
	return 0;
}
