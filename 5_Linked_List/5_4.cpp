/*
		问题：
			给定两个有序链表的头结点head1和head2，打印两个有序链表的公共部分。
		解题思路：
			1，如果两个链表有一个为空，直接返回即可，不可能有公共部分
			2，如果两个都非空，从两个链表的头节点开始遍历，如果list1的当前值小于list2的当前值，则继续遍历list1的下一个值。反之，如果list2的值小于list1的值，则继续遍历list2的下一个值。如果两者相等，就打印当前值，并都继续往下移动，
			3，list1，list2有一个为空，整个过程就停止。
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

class Common
{
public:
	vector<int> findCommonParts(ListNode* headA,ListNode* headB)
	{
		vector<int> res;
		ListNode *p = headA,*q = headB;
		//沿着next遍历，任意一个指针指向null即可停止
		while(p&&q)
		{
			//如果碰到相同值，push进res向量，p，q均往后一步
			if((*p).val == (*q).val)
			{
				res.push_back((*p).val);
				p = (*p).next;
				q = (*q).next;
			}
			//p指向的值小，p往前一步，因为链表是有序的，是从小到大的
			else if((*p).val <(*q).val)
				p = (*p).next;
			else
				q = (*q).next;
		}
		return res;
	}
};

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
	}
};

int main()
{
	int a[7]={1,2,3,4,5,6,7},b[5] ={2,4,6,8,10};
	vector<int> arr(a,a+7),brr(b,b+5);
	CreateListNode C;
	ListNode *HeadA = C.Create(arr);
	ListNode *HeadB = C.Create(brr);
	Common Co;
	vector<int> res = Co.findCommonParts(HeadA,HeadB);
	for(vector<int>::iterator iter=res.begin();iter!=res.end();iter++)
		cout<<*iter<<" ";
	cout<<endl;
	return 0;
}
