/*
问题：
	判断数组中是否有重复值，必须保证额外空间复杂度为O（1）：
解题思路：
	这里如果没有空间复杂度为O（1）的限制，其实是应该用hash表的。在遍历数组的过程中，统计每个数出现的次数。但hash的时间，空间复杂度均为O（N）。
	这里如果要求空间复杂度为O（1）的话，我们就需要先用O（1）空间复杂度的排序算法排序，然后相同的值会贴在一起。然后我们遍历一遍数组，就可以发现数组中是否有重复值。
	因此，这里我们选择空间复杂度为O（1）的堆排序，如果利用递归的方式实现堆得话，时间复杂度就为O（log N）
	所以，这里我们应该改出一个非递归版本的堆排序
*/
#include<iostream>
#include<vector>
using namespace std;
class DuplicateChecker
{
public:
	//判断数组中是否存在重复值
	bool checkDuplicate(vector<int> &a,int n)
	{
		//堆排序
		heapSort(a,n);
		int i;
		//遍历排好序的数组，然后判断是否存在重复值
		for(i = 0; i < n-1;i++)
		{
			if(a[i] == a[i+1])
				return true;
		}
		return false;
	}
	//堆排序
	void heapSort(vector<int> &A,int n)
	{
		int i, temp;
		//调整至大顶堆
		for(i = n/2-1;i>=0;--i)
			heapAdjust(A,i,n-1);
		for(i = n-1;i>0;i--)
		{
			//得到大顶堆的堆顶元素，最大值
			temp = A[0];
			//将数组尾部元素放入堆顶
			A[0] = A[i];
			//将temp，即最大值，放入数组尾部
			A[i] = temp;
			//再调整至大顶堆
			heapAdjust(A,0,i-1);
		}
	}
	//已知A[s,...,m]中记录的关键字除A[s]之外均满足堆的定义，本函数调整A[s]的关键字，使A[s,...,m]成为一个大顶堆
	void heapAdjust(vector<int> &A,int s,int m)
	{
		//rc记录堆顶元素
		int j,rc =A[s];
		for(j = 2*s+1;j <=m;j=2*j+1)
		{
			//如果j<m且左节点的值小于右节点的值，则不考虑，索引加1
			if(j<m && A[j]<A[j+1])
				j++;
			//如果根节点的值大于右节点的值，则无需调整，break
			if(rc >A[j])
				break;
			//否则的话，将最大值放至堆顶
			A[s]= A[j];
			//将根节点换至原来j的位置
			s = j;
		}
		A[s] =rc;
	}
}; 

int main()
{
	int b[]={1,2,3,4,5,5,6};
	vector<int> arr(b,b+7);
	DuplicateChecker d;
	bool c=d.checkDuplicate(arr,7);
	cout<<c<<endl;
	return 0;
}
