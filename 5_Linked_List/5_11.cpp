/*
		问题：
			如何判断两个有环单链表是否相交？相交的话返回第一个相交的节点，不相交的话返回空，如果两个链表的长度分别为N和M，请做到时间复杂度O（N+M），空间复杂度O（1）。
		解题思路：
			1，先根据之前的有环单链表，找到入环节点的题目，找到各自的入环节点。
			2，如果两个入环节点是同一个节点，则肯定两者是相交的。但两者在入环节点就相交了，肯定有更早的相交节点。做法跟找到无环单链表的相交节点类似。唯一不同的是，这里的终止位置为两者相同的入环节点。
			3，如果两者的入环节点不是同一个节点，有两种情况，链表1和链表2都有独立的环，还有一种情况是，链表1和链表2共享一个大环，但入环节点不同。如何判定就是先从链表1的入环节点开始往下，如果一直遍历到整个环结束还没发现入环节点2，则是第一种情况，直接返回空即可，因为两者不相交。否则，是链表1，链表2共享一个大环，两者相交。返回任意一个链表的入环节点即可。

*/
#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
class CheckRingListIntersect
{
public:
	bool chkRingListIntersect(ListNode* head1,ListNode* head2)
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
