/*
		问题：
			如何判断一个单链表是否有环，有环的话返回进入环的第一个节点，无环的话返回为空。 如果链表的长度为N，请做到时间复杂度O（n），额外空间复杂度O（1）。
		解题思路：
			1，如果没有额外空间复杂度限制，这里我们可以用hash表来做，从头节点开始遍历，每遍历一个节点，就在hash表中记录一下，如果一个链表无环，那么走到结尾处也不会出现重复的元素，此时，直接返回空。如果一个链表有环，则根据hash表，一定可以看到重复遍历到一个节点的情况。那么第一个重复遍历的节点，肯定就是入环的节点。直接返回即可。
			2，但在额外空间复杂度为O（1）的限制下，
				a，从头结点开始，用快慢两个指针进行遍历，快指针一次走两步，慢指针一次走一步。
				b,如果一个链表无环，那么快指针则将快速发现尾，并返回空
				c,如果一个链表有环，那么快指针和慢指针迟早会在环内的某个位置相遇，在他们相遇的时刻，让快指针从链表的头部开始，重新遍历，这次一次走1步，同时，慢指针也从相遇的位置开始，继续往下走，一次也走一步，当快慢指针再次相遇时，相遇到的节点即为入环的第一个节点。

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

class ChkRingInList
{
public:
	//返回入环节点的值
	int chkRing(ListNode* head)
	{
		if(!head)
			return -1;
		//定义快指针和慢指针
		ListNode *slow = head,*fast = head;
		//慢指针一次一步，快指针一次两步，如果相遇，则有环，就跳出
		while(((*fast).next&&(*(*fast).next).next))
		{
			slow = (*slow).next;
			fast = (*(*fast).next).next;
			if(slow == fast)
				break;
		}
		//如果快指针已经到头，说明在之前的过程中一直没有相遇，没有break，那么也是无环
		if(!(*fast).next || !(*(*fast).next).next)
			return -1;
		//这里应该是fast=head吧,找入环节点,反正思路是1个从头开始，1个从相遇点开始，继续步长为1往下走，再次相遇的位置就是入环位置。
		slow = head;
		while(slow != fast)
		{	
			slow = (*slow).next;
			fast = (*fast).next;
		}
		//返回再次相遇节点的值
		return (*fast).val;
	}

};
int main()
{
	return 0;
}
