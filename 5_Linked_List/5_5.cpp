/*
		问题：
			给定一个单链表的头结点head，实现一个调整单链表的函数，使得每K个节点之间逆序，如果最后不够K个节点一组，则不调整最后几个节点。
			比如链表，1-》2-》3-》4-》5-》6-》7-》8-》null,K=3
			调整后为3-》2-》1-》6-》5-》4-》7-》8-》null，
			
		解题思路：
			1，如果链表为空，长度为1，或小于等于2.这些情况都是不用进行处理的。
			2，方法1，时间复杂度O（n），空间复杂度O（k），k为每k个节点。
				a,用栈处理，让节点依次进栈，凑齐k个元素，就依次从栈中弹出，弹出顺序为 3 2 1，刚好逆序。
				b,然后下一组元素做同样的处理，
				c,如果凑不齐，则不进行栈操作
				d,此外，我们还需要记录每个组的最后一个元素指向的指针，（第一组不用，需特殊处理）
				e,最后，因为链表的头节点发生了改变，因此我们最好设计成返回值为节点的函数。
			3，方法2，时间复杂度O（n），空间复杂度O（1）
				a,方法2与方法1大体相似
				b，收集到k个节点就做逆序操作，唯一不同的是不用栈来操作。
				c,需要将每组的调整过得头结点和上一组的尾节点相连

*/
//创建链表，或打印链表内容
#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;
struct ListNode
{
	int val;
	struct ListNode *next = NULL;
	ListNode(int x):val(x),next(NULL){}
};
class KReverseList
{
public:
	//传入链表头节点和逆序的间隔，返回k逆序过的链表
	ListNode* reverse(ListNode* head,int k)
	{
		//如果链表为空，或者间隔k的值小于等于1,直接返回即可
		if(!head || k<2)
			return head;
		//指针p指向一个间隔内第一个元素，指针q用来遍历整个链表。和上个间隔的尾节点。
		ListNode *p = head,*q=head,*LastTail = NULL;
		int i = 1,count = 0;
		while(q)
		{
			//每到一个间隔,对于复杂的问题，建议画图辅助
			if(i == k)
			{
				//如果count为0,即前面没有k逆序间隔,这是第一个k逆序，本间隔的k处节点逆序后成为链表的头，
				if(!count)
					head = q;
				//否则,将上一个k逆序间隔的尾节点指针指向没逆序前的本k间隔的k处节点
				else
					(*LastTail).next = q;
				//temp1记录当前节点的下一个节点，即下一个k间隔的开始
				ListNode *temp1 = (*q).next,*temp2 = NULL;
				//逆序本间隔的值。其中q指向本间隔最后一个元素，p指向本间隔第一个元素
				while(q!=p)
				{
					//记录间隔第一个元素的下个节点
					temp2= (*p).next;
					//交换后，p变成了本间隔最后一个元素，设置LastTai为p
					if((*q).next == temp1)
						LastTail = p;
					
					//将p换至间隔尾
					(*p).next = (*q).next;
					//q换到p的前面
					(*q).next = p;
					//p换为它原来的下一个元素，此时记住间隔的最后一个元素已经设定为p了
					p = temp2;
				}
				//继续下一个间隔的第一个位置开始
				p = q = temp1;
				//i被重置1
				i = 1;
				//可以理解为间隔编号，第几个间隔
				count++;
			}
			//如果没到末尾，继续往下next
			if(q)
				q = (*q).next;
			//间隔内计数
			i++;
		}
		return head;
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
		cout<<endl;
	}
};
int main()
{
	int a[8]={1,2,3,4,5,6,7,8};
	vector<int> arr(a,a+8);
	CreateListNode C;
	ListNode *HeadA=C.Create(arr);
	KReverseList K;
	ListNode *head = K.reverse(HeadA,3);
	C.Print(head);
	return 0;
}
