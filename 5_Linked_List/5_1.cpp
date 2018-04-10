/*
		问题：
			给定一个整数num，如何在节点值有序的环形链表中插入一个节点值为num的节点，并保证这个环形单链表仍然有序。
		解题思路：
			这里我们给出时间复杂度O（n），空间复杂度O（1）的操作，假定，节点值为num的新节点记为node。
			1，如果环形单链表为空，node，自己形成环形链表，即next指针指向自己。然后返回node即可
			2，如果链表非空，令变量p指向头结点，current指向下一个节点，然后让p和current同步移动下去。如果遇到p的节点值《=num，c的节点值》=num，则将node插入到这里。
			3，插入node，然后返回head即可。
			4，如果p和c转一圈都没发现合适的位置，那么，将node插入头结点的前面。这是因为，要么node的值比链表中所有节点的值都大，要么是都小。
			但这种情况下，如果插入的元素比链表中的都大时，直接返回头结点，但如果都小的话，返回新的节点
		
*/
/*
int a = 10;
int *p = &a;
cout<<*p<<endl;
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
class InsertOrderedRing
{
public:
	//传入，向量A，向量next和要插入的节点值,返回，链表的头节点
	ListNode* insert(vector<int> A, vector<int> nxt, int val)
	{
		//如果待插入的向量A为空，那么头结点设置为要插入的节点，返回即可
		if(A.empty())
		{
			ListNode *Head = new ListNode(val);
			return Head;
		}
		//设置头节点和指向头结点的指针
		ListNode *Head = new ListNode(A[0]),*p = Head;
		//nxt向量里存贮的是A向量元素的位置，通过这种方法，将A向量构造成一个环链表
		for(vector<int>::iterator iter = nxt.begin();iter!=nxt.end();iter++)
		{
			if(*iter==0)
			{
				(*p).next = Head;
				break;
			}
			(*p).next = new ListNode(A[*iter]);
			p = (*p).next;
		}
		//pre指针和now指针，用来遍历整个有序环形链表。
		ListNode *pre = Head,*now = (*Head).next;
		while(now != Head)
		{
			if((*pre).val<=val&&(*now).val>=val)
			{
				ListNode *p = new ListNode(val);
				(*p).next = now;
				(*pre).next = p;
				break;
			}
			//否则的话继续往后轮，直到now = head处，满了一圈，停止
			else
			{
				pre = now;
				now = (*now).next;
			}
		}
		//如果转了一圈后，还没有break，说明这个要插入的值，要么大于环内所有值，要么小于环内所有值，将其插入到head的前面
		if(now == Head)
		{
			ListNode *p = new ListNode(val);
			(*p).next = now;
			(*pre).next = p;
			//如果插入的值比原来的头节点值还小的话，则将新插入的点作为头结点
			if(val < (*Head).val)
				Head = p;
		}
		//用指针pre和指针p转一圈，直至p遍历至head，而pre遍历到head的前一个节点
		pre = Head,p = (*Head).next;
		while(p!=Head)
		{
			pre = p;
			p = (*p).next;
		}
		//设置尾节点
		(*pre).next = NULL;
		return Head;
	}
};
int main()
{
	int a[7]= {3,3,7,7,8,12,13},nxt[7] = {1,2,3,4,5,6,0};
	vector<int> arr(a,a+7),next(nxt,nxt+7);
	InsertOrderedRing I;
	ListNode* Head = I.insert(arr,next,11);
	ListNode *p = (*Head).next;
	//打印链表头节点
	cout<<(*Head).val<<" ";
	//依次打印链表中剩余的节点，到尾节点结束
	while(p != NULL)
	{
		cout<<(*p).val<< " ";
		p = (*p).next;
	}
	cout<<endl;
	return 0;
}

