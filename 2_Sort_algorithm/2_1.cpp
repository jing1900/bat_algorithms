/*E1：已知一个几乎有序的数组，几乎有序是指，如果把数组排好顺序的话，每个元素移动的距离不超过k，并且k相对于数组长度来说很小。请问选择什么方法对其排序比较好？
解题思路：这道题的最终答案是改进后的堆排序。排序之后每个元素的移动范围不超过k，因此整个数组的最小值，一定是在a[0]-a[k-1]这个区间的。
		1，因此我们将a[0]-a[k-1]这个区间的元素，建立一个小顶堆，然后堆顶元素就是这前k个值得最小值，弹出这个堆顶，放在数组的最左边。
		2，接着，将a[k]这个元素，放入小根堆的堆顶，然后对这个小根堆进行调整， 然后整个数组第二小的元素就到了堆顶，然后弹出将其放在数组的第1个位置上。
		3，接下来重复上述过程，每次调整都是在大小为k的堆里，所以成本为logk，然后我们要拍好n个元素，因此整个的时间复杂度为O（N*log k）
*/
#include<iostream>
#include<vector>
using namespace std;
class SmallScaleSort
{
public:
	//传引用,这里k是每个元素最大移动的距离，这里我们设定为2
	vector<int> sortElement(vector<int> &A,int n, int k)
	{
		//创建一个容器B，其元素个数为n，且值均为0
		vector<int> B(n,0);
		int i,j;
		//将a[0]-a[k-1]这个区间的元素，建立一个小顶堆
		for (i = k/2-1;i >=0;--i)
			heapAdjust(A,i,k-1);
		//将小顶堆的元素放置数组B的初始位置
		B[0]=A[0];
		//将a[k]及往后的数据，依次放入小顶堆的堆顶，然后对这个小顶堆进行调整，然后生成新的小顶堆，获取其中第二小的元素
		for(i = 1,j = k;j<n;j++)
		{
			A[0] = A[j];
			heapAdjust(A,0,k-1);
			B[i++]= A[0];
		}
		//对A的前k个元素进行堆排序，得到的堆排结果是由大到小的。
		heapSort(A,k);
		//因此，在这里，将A[0]处的内容，重新存储成A[n-1]位置上。
		for(i = 0,j = n-1;i < k;j--,i++)
			A[j] = A[i];
		//0-k之外的部分，直接copy B里的
		for(i =0;i <n-k;i++)
			A[i]= B[i];
		return A;
	}
	
	//堆排序
	void heapSort(vector<int> &A,int n)
	{
		int i,temp;
		//将（0，n-1)区间里的元素，建立一个小顶堆
		for(i = n/2-1;i>=0;--i)
			heapAdjust(A,i,n-1);
		//A中元素从后往前，
		for(i = n-1;i >0;i--)
		{
			//存贮小顶堆的堆顶
			temp = A[0];
			//将A中元素从后往前依次放入堆顶
			A[0] = A[i];
			//?
			A[i] = temp;
			//放入新的堆顶后，重新调整小顶堆	
			heapAdjust(A,0,i-1);
		}
	}
	
	//已知A[s,...,m]中记录的关键字除A[s]之外均满足堆的定义，本函数调整A[s]的关键字，使A[s,...,m]成为一个小顶堆
	void heapAdjust(vector<int> &A,int s,int m)
	{
		//记录堆顶元素
		int j,rc = A[s];
		for(j = 2*s+1;j <=m;j = 2*j+1)
		{
			//如果堆顶的左节点比右节点大，则不用考虑左节点，j加一，指向右节点
			if(j < m && A[j]>A[j+1])
				j++;
			//如果堆顶元素小于A[j]的话，则不用执行，直接break
			if(rc < A[j])
				break;
			//否则，A[j]是最小的，将其放至堆顶
			A[s] = A[j];
			//将s的位置更新为原来j的位置
			s = j;
		}
		//将原来的堆顶元素，放至新的s处。
		A[s] = rc;
	}
};

int main()
{
	int b[]={2,1,4,3,6,5,8,7,10,9};
	//定义容器arr的值为b的第0个元素，到b的第九个元素，共10个
	vector<int> arr(b,b+10);
	SmallScaleSort s;
	s.sortElement(arr,10,2);
	for(int i = 0;i < 10;i++)
		cout<<arr[i]<< " ";
	cout<<endl;
	return 0;
}
