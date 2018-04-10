/*
问题：
	把两个有序数组合并进第一个数组，然后第一个数组的空间，正好可以容纳两个数组的元素。假设有序数组A：2,4,6，和三个额外空间。B：1,3,5
解题思路：
	a，首先，将第一个数组的最大元素即最后一个元素6和第二个数组的最后一个元素比较。然后6比较大，就将6拷贝到第一个数组的最后一个位置。
	b,接下来，是4和5进行比较，发现5比较大，就把5拷贝到数组的倒数第二个位置。
	c,再接着，将第二个数组的3和第一个数组的4进行比较，4比较大，就拷贝到第一个数组的倒数第三个空白位置
	d,然后比较第二个数组的3和第一个数组的2，然后3比较大，就放在第一个数组的倒数第四个空白位置
	e,再然后，将第二个数组的1和第一个数组的2进行比较，2比较大，就放在第一个数组的倒数第五个位置
	f,再接着第二个数组的1，放在数组的初始位置
	（从后往前覆盖数组A）
*/
#include<iostream>
#include<vector>
using namespace std;
class MergeOrderedArray
{
public:
	//传入数组A,B,及各自的长度
	int* mergeAB(int* A,int* B,int n,int m)
	{
		int i ,j ,newLength = m+n;
		for(i = n-1,j = m-1;i>=0&&j>=0;newLength--)
		{
			//如果A中的最后一个元素大，则在A的新长度末尾放入A，同时A的索引往左移一位
			if(B[j]<=A[i])
				A[newLength-1] = A[i--];
			//否则的话，就是B中的元素较大，则在A的新长度末尾放入B，同时B的索引往左移动一位
			else
				A[newLength-1] = B[j--];
		}
		//处理B最后剩下的一位
		while(j>=0)
		{	
			A[newLength-1] = B[j--];
			newLength--;
		}
		return A;
	}
};

int main()
{
	int a[10]={1,3,7,8};
	int b[]={0,2,5,9};
	MergeOrderedArray m;
	m.mergeAB(a,b,4,4);
	for(int i=0;i<8;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;	
}

