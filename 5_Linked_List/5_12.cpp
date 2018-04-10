/*
		问题：
			给定两个单链表的头结点head1，和head2，如何判断两个链表是否相交？相交的话返回第一个相交节点，不相交的话返回空。
		解题思路：
			1，先判断两个链表是否有环，有的话，返回入环节点，
			2，如果入环节点1个为空，1个不为空，则肯定不相交，
			3，如果两者都无环，则直接套用无环是否相交的方法。
			4，如果两者都有环，则套用有环是否相交的办法。

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

class CheckIntersectInRing
{
public:
	//判断两个单链表是否相交
	bool chkInter(ListNode* head1,ListNode* head2)
	{
		ListNode *entry1 = chkLoop(head1),*entry2 = chkLoop(head2);
		//都有环，调用有环是否相交的方法
		if(entry1!= NULL&&entry2!=NULL)
			return chkRingListInter(head1,head2);
		if(entry1 == NULL&&entry2 == NULL)
			return chkNoRingListInter(head1,head2);
		return false;
	}

	//无环单链表判相交
	bool chkNoRingListInter(ListNode* headA,ListNode* headB)
	{
		//如果链表A，B有任何一方为空
		if(!headA || !headB)
			return false;
		//链表A和B的长度计数
		int NumofA = 0,NumofB=0,count=0;
		ListNode *p = headA;
		while(p)
		{
			NumofA++;
			p = (*p).next;
		}
		p = headB;
		while(p)
		{
			NumofB++;
			p = (*p).next;
		}
		//长的链表L，短的链表S
		ListNode *L = NULL,*S = NULL;
		if(NumofA > NumofB)
			L = headA,S=headB;
		else
			L= headB,S= headA;
		//长短链表的长度差值
		count = (NumofA > NumofB)?(NumofA-NumofB):(NumofB-NumofA);
		//先让长链表走count长度
		while(count--)
			L = (*L).next;
		while(L&&S)
		{
			//如果两个链表某处节点值相等
			if(L == S)
				return true;
			L = (*L).next;
			S = (*S).next;
		}
		return false;
	}

	//有环单链表判相交
	bool chkRingListInter(ListNode* head1,ListNode* head2)
	{
		//获取链表1,2的入环节点
		ListNode *entry1 = chkLoop(head1),*entry2 = chkLoop(head2);
		//如果一个有环，一个无环，一定不相交
		if(entry1 == NULL || entry2 == NULL)
			return false;
		//如果入环节点是同一个节点，则肯定相交
		if(entry1 == entry2)
		{
			//获取第一个相交节点
			int Numof1 = 0,Numof2 = 0,count=0;
			//获取链表1到环之前的长度
			ListNode *p = head1;
			while(p!=entry1)
			{
				Numof1++;
				p = (*p).next;
			}
			//获取链表2到环之前的长度
			p = head2;
			while(p != entry1)
			{
				Numof2++;
				p = (*p).next;
			}
			
			//定义长链表，短链表
			ListNode *L = NULL,*S = NULL;
			if(Numof1>Numof2)
				L = head1,S = head2;
			else
				L = head2,S = head1;
			//获取长短链表的长度差值
			count = (Numof1>Numof2)?(Numof1-Numof2):(Numof2-Numof1);
			//先让长链表走一段
			while(count--)
				L = (*L).next;
			while(L!=entry1&&S!=entry2)
			{
				//相交
				if(L == S)
					break;
				L = (*L).next;
				S = (*S).next;	
			}
			//返回相交节点
			//return L;
			return true;
		}
		//否则，两者的入环节点不同，需分情况讨论，看是独立环，还是公共环。
		else
		{
			//定义指针p指向链表1入环节点的下一个节点
			ListNode *p = (*entry1).next;
			//遍历环内节点
			while(p!=entry1)
			{
				//如果在环内找到了链表2的入环节点
				if(p == entry2)
					return true;
				p = (*p).next;
			}
			//否则就是独立环，不相交，返回false
			return false;
		}
	}
	
	//返回有环但链表入环节点
	ListNode* chkLoop(ListNode* head)
	{
		if(!head)
			return NULL;
		ListNode *slow = head,*fast = head;
		//快指针一次走两步，慢指针一次走一步，相遇时break
		while(((*fast).next&&(*(*fast).next).next))
		{
			slow = (*slow).next;
			fast = (*(*fast).next).next;
			if(slow == fast)
				break;
		}
		//如果fast走到结尾，说明之前没有因相遇而break，因此，无环
		if(!(*fast).next||!(*(*fast).next).next)
			return NULL;
		//第二次，slow从头出发，fast从原来的位置出发，再次相遇的位置，就是入环的位置，两者这次步长均为1
		slow = head;
		while(slow!=fast)
		{
			slow = (*slow).next;
			fast = (*fast).next;
		}
		//返回相遇时的指针
		return fast;
	}

};

int main()
{
	return 0;
}
