/*
问题：
	经典荷兰国旗问题。只包含0,1,2的整数的数组进行排序。要求排序完的结果是0都在数组的左边，1都在数组的中间，2都在数组的右边。要求使用交换，原地排序，而不是利用计数进行排序。
解题思路：
	其排序过程和快排是比较像的。最后能实现时间复杂度为O(N)，空间复杂度为O（1）。
	a,在遍历整个数组之前，先在左侧设立一个0区{}，初始时长度为0，同时在右侧设立一个2区{}，初始长度也为0.
	b,从左到右遍历整个数组，如果为1的话，则跳过进行下一个数，若为0，则和0区的下一个位置上的数进行交换，交换完0区得长度+1，若为2，则和2区的上一个位置的数进行交换，交换完2区的长度+1，但交换到这个位置的数是没有比较过得数，因此如果为2的话，做完这些操作仍停留在原地，进行比较操作。
	c，当当前的位置和2区的位置重合时，过程停止。

*/
#include<iostream>
#include<vector>
using namespace std;
class ThreeColorSort
{
public:
	vector<int> sortThreeColor(vector<int> &A,int n)
	{
		int f,r,i,temp;
		//f为0区索引，r为2区索引。i从0-n-1,从左往右索引
		for(i = f =0,r = n-1; i<=r;i++)
		{
			//如果元素为0
			if(A[i] == 0)
			{
				//存贮原来0区下一个元素
				temp = A[f];
				//如果当前元素为0，就将其换至0区的下一个元素
				A[f] = A[i];
				//并把原来0区下一个元素挪到这个交换的位置
				A[i] =temp;
				//0区的索引往后挪一位
				f++;
			}
			//如果元素为2
			if(A[i] == 2)
			{
				//存贮2区的前一个元素，即数组的末尾
				temp = A[r];
				//如果当前元素为2，将其换至2区的前一个元素
				A[r]=A[i];
				//将原来2区的前一个元素挪到这个交换的位置
				A[i] = temp;
				//2区的索引往前挪一位
				r--;
				//2的话，换过来的元素还未经过判定，所以i--,再结合for循环里的i++，相当于保持原地不动
				i--;
			}
		}
		return A;
	}
};

int main()
{
	int a[6]={1,2,0,2};
	vector<int> b(a,a+4);
	ThreeColorSort t;
	t.sortThreeColor(b,4);
	for(int i=0;i<4;i++)
		cout<<b[i]<<" ";
	cout<<endl;
	return 0;
}
