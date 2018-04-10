/*

		问题：
			如何判断两个无环单链表是否相交，相交的话返回第一个相交的节点，不相交的话返回空，如果两个链表长度分别为N和M，请做到时间复杂度O(N+M），额外空间复杂度为O（1）。
		解题思路：
			1，如果没有空间复杂度限制，我们可以用hash表，先遍历第一个链表，将第一个链表的节点都加入hash表中，然后开始遍历第二个链表，一旦发现第二个链表中的节点，在hash表中有记录，则表明该节点在第一个链表中也存在，是第一个相交的节点，如果遍历完了也没有发现如上的情况，则表明两个链表不相交。
			2，遍历两个链表，得到两个链表的长度，比如第一个链表的长度,100，第二个链表的长度是50，那么让长度大的链表先走（len1-len2）步，然后再让两个链表一起往下走，如果两者相交的话，那么在他们同步走的时候一定会遍历到相同的节点，如果走到最后都不相交，则两个链表不相交。（不过我觉得这个思想有点问题，万一相交的部分在第一个链表已经走过的部分呢？）
		
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
class Check2ListIntersect
{
public:
	bool chkIntersect(ListNode* headA,ListNode* headB)
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
};

int main()
{
	return 0;
}
