/*
		问题：
			判断一个链表是否为回文结构，如12312，是，1231，false
		
		解题思路：
			时间复杂度都为O（N），但空间复杂度依次为O（N），O（N）/2 ,   O(1)
			1，方法1：
				a，申请一个栈结构，在遍历链表的过程中，将节点依次压入栈中，此时，栈中从顶到底的元素顺序就是链表元素的逆序。
				b,再次遍历链表，同时同步弹出栈中元素，每次都比对两者元素，如果都相同，则返回true，有一个不相同，返回false。
			2，方法2：
				a,同样申请一个栈结构，但用快慢两个指针同时遍历，快指针一次走两步，慢指针一次走一步，将慢指针每次遍历的内容压入栈，当快指针走完的时候，慢指针来到链表中间的位置，结束这个过程，此时，栈内有着链表的前半部分元素（中间位置的节点不放入）。
				b，接下来，man指针继续往后遍历，栈也同步弹出元素，进行比对，如果每一步都相等，则返回true，否则，返回false
			3，方法3：
				a，先找到链表中间的位置，然后对其右半部分做逆序，接下来从链表的两头开始，依次对比值是否一样，
				b，如果对比到中间位置，仍一样，则返回true。
				c，方法3返回之前，需要将链表调整回来。

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

class PalindromeInList
{
public:
	//方法3
	bool isPalindrome(ListNode* head)
	{
		if(!head||!(*head).next)
			return true;
		//定义快慢指针
		ListNode *slow = head,*fast = head;
		//是否为奇数，默认不是
		int odd = 0;
		//指针移动，slow每次移1位，Fast每次移2位
		while(fast->next&&fast->next->next)
		{
			fast = (*(*fast).next).next;
			slow = (*slow).next;
		}
		//如果为奇数，则fast遍历到最后刚好是尾节点的。
		if(!fast->next)
			odd = 1;
		//用于链表下半部分的指针
		ListNode *pre = slow,*now = (*pre).next,*temp=NULL;
		//得到上半部分，此时slow刚好遍历到链表中间。
		(*slow).next = NULL;
		//遍历链表后半部分，对其做逆序
		while(now)
		{
			temp = (*now).next;
			(*now).next = pre;
			pre = now;
			now = temp;
		}
		//是否是回文结构
		bool res = true;
		//分别从头和尾遍历，此时pre指向的是逆序后的链表的头部,slow是尾部,判断左右两部分链表是否完全一致
		ListNode *fwd = head,*tail = pre;
		while(tail!=slow)
		{
			if((*fwd).val != (*tail).val)
			{
				res = false;
				break;
			}
			fwd=(*fwd).next;
			tail = (*tail).next;
		}
		//返回之前，将链表调整回来，此时pre指向逆序后的链表头部，
		now = pre;
		pre = (*pre).next;
		(*now).next = NULL;
		//将逆序过的链表逆序回来
		while(pre)
		{
			temp = (*pre).next;
			(*pre).next = now;
			now = pre;
			pre = temp;
		}
		return res;
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
	int a[5]={1,2,3,2,1};
	vector<int> arr(a,a+5);
	CreateListNode C;
	ListNode *HeadA=C.Create(arr);
	PalindromeInList P;
	bool res = P.isPalindrome(HeadA);
	cout<<res<<endl;
	C.Print(HeadA);
	return 0;
}
