#include<iostream>
#include<cstdlib>
#include<math.h>
using namespace std;
#define N 10


//冒泡排序，时间:O(N^2),空间:O(1)，稳定
class BubbleSort
{
public:
	//传入指向数组的指针和数组长度
	void bubbleSort(int *A, int n)
	{
		int i = n,temp,j,flag;
		//从最开始的0-N-1，到0-N-2,直到0
		while(i)
		{
			//这里之所以是j<i-1,是因为后面有A[j+1]
			for(j = 0,flag=0;j<i-1;j++)
				//如果前面的数比后面的大，则换过去，一直换到最后
				if(A[j]>A[j+1])
				{
					temp = A[j];
					A[j] = A[j+1];
					A[j+1] = temp;
					flag = 1;
				}
			//flag为空，意味着整个数组已经不需要再排序了，直接break掉while即可。
			if(!flag)
				break;
			i--;
		}
	}
};

//选择排序，时间:O(N^2),空间:O(1),不稳定
class SelectionSort
{
public:
	//返回排序好的数组指针，传入指向待排序数组的指针和数组长度
	int * selectionSort(int *A, int n)
	{
		//选择排序的过程是首先从（0，N-1）中选出最小的，放在数组的最左边，然后从（1，N-1）中选出最小的，然后放在数组的左边第二个位置，依次下去
		int i = 0,j,min,temp;
		while(i < n-1)
		{
			//初始化最小值位置暂定为i，第0个元素
			min = i;	
			//从第1个元素到最后一个元素，依次与第i（0）个元素比较,直到找到最小值所在的位置
			for( j = i+1; j < n; j++)
				if (A[j]<A[min])
					min = j;
			//交换最小值和第i（0）个元素
			if(min != i)
			{
				temp = A[i];
				A[i] = A[min];
				A[min] = temp;
			}
			//继续从（1，N-1）的过程
			i++;
		}
		//返回排好序的数组
		return A;
	}
};

//插入排序，时间:O(N^2),空间:O(1)，稳定
class InsertSort
{
public:
	int* insertSort(int *A,int n)
	{
		int i = 1,j,temp;
		//首先先对位置0和1上的元素进行比较，如果后者更小，则将其放到位置0上，然后对位置2上的数和它前一个位置上的数进行比较，如果后者更小，再将其与位置0上的值进行比较，如果还小，则将其放在位置0上。接下来，对位置k上的数，也需要依次与之前的k-1个值进行比较，直到之前的元素小于等于该值，然后将其插在此处。
		while(i < n)
		{
			//现在要做的是，将A[i]处的元素与其之前的进行比较，如果小于之前的元素，则插入到合适的位置。
			temp = A[i];
			j = i -1;
			while(j>=0&&A[j]>temp)
			{
				//若元素大于A[i]处的元素，则将该处的元素右移
				A[j+1] = A[j];
				j--;	
			}
			A[j+1]= temp;
			i++;
		}
		return A;
	}
};

//归并排序，时间:O(N*log N),空间:O(N)，稳定
class MergeSort
{
public:
	//归并排序
	int* mergeSort(int *A, int n)
	{
		//将A进行归并排序成新A
		Msort(A,A,0,n-1);
		return A;
	}
	//子排序,将A[s,...,t]归并排序为B[s,...,t]
	void Msort(int *A, int *B,int s,int t)
	{
		//数组长度为1
		if (s == t)
			B[s] = A[s];
		else
		{
			//数组中间位置
			int m = (s+t)/2;
			//空的数组
			int C[100] = {0};
			//递归：对A中的前半部分元素和空C进行排序，生成C
			Msort(A,C,s,m);
			//递归：排序A中的后半部分和排序后前半部分生成的C，生成总的排序好A中所有元素的C
			Msort(A,C,m+1,t);
			//合并C和空B，生成B
			Merge(C,B,s,m,t);
		}
	}

	//子归并,将有序的A[i,...,m]和A[m+1，...,n]归并为有序的B[i,...,n]
	void Merge(int *A, int *B,int i, int m, int n)
	{
		int j,k;
		for(j = m+1,k = i;i <=m &&j <= n;k++)
		{	
			//判断相邻两个数组的第一个元素哪个小，小的放入B的起始位置，然后这个放入的数组索引右移一位
			if(A[i]<A[j])
				B[k] = A[i++];
			else
				B[k] = A[j++];
		}
		//处理剩余的最后一个元素，如果是前一个相邻数组的，用这个索引放入B，如果是另一个相邻数组的，则用另一个索引放入B
		if(i <=m)
			while(i <=m)
				B[k++]= A[i++];
		if(j <= n)
			while(j <=n)
				B[k++]= A[j++];
	}
};

//快速排序，时间复杂度O（N * log N),空间复杂度：O（log N）- O(N),不稳定
class QuickSort
{
public:
	int* quickSort(int *A,int n)
	{
		QSort(A,0,n-1);
		return A;
	}

	//对数组A[low,...,high]进行排序
	void QSort(int *A, int low, int high)
	{
		if(low < high)
		{
			//支点位置
			int n;
			//这一步之后，已将小于支点的放在了支点的左边，大于支点的放在了支点的右边
			n = Partition(A,low,high);
			//对支点左边的进行递归排序
			QSort(A,low,n-1);
			//对支点右边的部分进行递归排序
			QSort(A,n+1,high);
		}
	}
	//这里low，high是需要交换的数组的上下界。
	//交换数组A[low,...,high]的记录，支点记录到位，并返回其所在位置，此时在它之前（后）的记录均不大（小）于它
	int Partition(int *A,int low, int high)
	{
		//这里将A[low]处的值，作为随机选中的支点。
		int key = A[low];
		while(low < high)
		{	
			//从右往左
			//如果下标大于上标，且下标的值大于支点的话，则下标位置的数不用变，下标往前挪一位。
			while(low < high && A[high]>=key)
				high--;
			//否则是小于支点值，故将此处的值换至上标处。
			A[low]= A[high];

			//从左往右
			//如果此时换到low处的值比key要小，ok，继续往前，上标往前挪一位
			while(low < high && A[low]<=key)
				low++;
			//否则low处的值大于支点的值的话，将此处的值换至下标处。
			A[high]=A[low];
			
		}
		//最后，low和high重合。需要交换的过程结束，最终将支点的值放至上标处。
		A[low] = key;
		//返回支点位置
		return low;
	}
	
};

//堆排序，时间复杂度O（N * log N),空间复杂度：O（1),不稳定
class HeapSort
{
public:
	int* heapSort(int *A,int n)
	{
		int i, temp;
		//从A中间位置，往左，构建大顶堆,循环结束时，其调整的是heapAdjust(A,0,n-1);
		for(i = n/2 -1;i>=0;--i)
			heapAdjust(A,i,n-1);
		//从A末尾位置开始
		for(i = n-1;i>0;i--)
		{
			//堆顶，最大值
			temp = A[0];
			//将A末尾的值放至堆顶
			A[0] = A[i];
			//将堆顶的值放至A的末尾
			A[i] = temp;
			//对重新设置过堆顶的堆进行大顶堆调整
			heapAdjust(A,0,i-1);
		}
		return A;
	}
	
	//调整至大顶堆。已知A[s,...,m]中记录的关键字除A[s]之外均满足堆的定义，本函数调整A[s]的关键字，使A[s,...,m]成为一个大顶堆.堆中索引是从0开始的。
	void heapAdjust(int *A,int s, int m)
	{	
		//定义索引值和堆顶元素。
		int j, rc = A[s];
		for(j = 2*s+1;j<=m;j=2*j +1)
		{
			//这里判断左节点是否小于右节点，若是，则j++，直接判断右节点和根节点哪个大
			if(j < m && A[j]<A[j+1])
				j++;
			//判断根节点元素和右节点哪个大,如果堆顶元素大，则不用调整，直接break
			if(rc > A[j])
				break;
			//否则，右节点处值最大，换至堆顶
			A[s]= A[j];
			//将索引的位置换至j
			s = j;
		}
		//将原来索引处的位置换至原来的j处，即新的s索引处
		A[s]=rc;
	}
};

//希尔排序，时间复杂度O（N * log N),空间复杂度：O（1),不稳定
class ShellSort
{
public:
	int* shellSort(int *A, int n)
	{
		int gap,i,j,temp;
		if(n ==1)
			return A;
		//步长，从n/2开始，每次缩减一半
		for(gap = n/2;gap>0;gap /= 2)
		{
			//开始处理的位置，在步长大小之后开始
			i = gap;
			//从步长大小之后开始，每次进1，直到n。
			while(i < n)
			{
				//步长大小开始后的第一个值
				temp = A[i];
				//j为当前i往前跨gap大小的位置的索引
				j = i-gap;
				//如果距离大于0且j索引处的值，比i索引处的值大，则交换，将A[j]处的值放至j+步长gap之后的位置，也就是i的位置
				while(j >= 0&&A[j]>temp)
				{
					A[j+gap]=A[j];
					//继续往左
					j = j -gap;
				}
				//将原来A[i]处的值，放至之前j的位置，不过while里面多减了一个gap，所以这里加上
				A[j+gap]=temp;
				i++;
			}
		}
		return A;
	}
};


//计数排序，时间复杂度O（N ),空间复杂度：O（M),稳定，只能处理小范围的int类型数据
class CountingSort
{
public:
	int* countingSort(int* A,int n)
	{
		//求数组A中的最大最小值
		int i,j,min,max;
		for (i =1,min = max=A[0];i<n;i++)
		{
			if(A[i]<=min)
				min = A[i];
			if(A[i]>max)
				max = A[i];
		}
		//定义桶空间，有为max-min+1个桶
		int *counts = (int *)calloc(max-min+1,sizeof(int));
		if(!counts)
			exit(-1);
		//对于A中的每个元素，将其放入对应的桶中，根据元素值减去最小值，来确定其该位于哪号桶。
		for(i = 0;i < n;i++)
			counts[A[i]-min]++;
		for(i = 0,j = 0;i<max-min+1;i++)
			//如果i号桶有数据
			while(counts[i])
			{
				//将其中数据：i+m，按顺序放入A中，从A[0]的位置开始放起
				A[j] = i + min;
				counts[i]--;
				j++;
			}
		free(counts);
		counts = NULL;
		return A;
	}
};
//基数排序，时间复杂度O（N ),空间复杂度：O（M),稳定
class RadixSort
{
public:
	//radix为关键词最高位数有几位。比如138,3位。
	int* radixSort(int* A,int n,int radix)
	{
		//定义桶,从0-9.N在代码的开头定义过了，是10.
		//其中temp[10][N],表示有10个桶，每个桶中可放N个数据。
		//order[x]表示其代表的x号桶内先已存入的数据个数。
		int temp[10][N]={0},order[10]={0};
		//pow(x,y):计算x的y次方。
		int m=(int)pow((double)10,radix-1);
		//int m = (int)pow((double)10,radix-1)
		int base=1;
		//1位及以上
		while(base <=m)
		{
			int i,k;
			for(i = 0;i <n;i++)
			{	
				//依次对A中的每个数，除10得余数，然后根据个位放入桶
				int lsd = (A[i]/base)%10;
				//前面是几号桶，后面是该桶内的次序数组，初始化为0,此时，order[8]=0
				temp[lsd][order[lsd]]=A[i];
				//该桶的次序数组索引加一，现在order[8] = 1
				order[lsd]++;
			}
			//按桶的次序，取出数，放入A，从A[0]开始。
			for(i = 0,k = 0; i <10;i++)
			{
				//如果i号桶内有数据
				if(order[i])
				{
					int j;
					for(j = 0;j <order[i];j++,k++)
						A[k] = temp[i][j];
				}
				//取完，将该号桶的次序数组清零。
				order[i]=0;
			}
			//base每次×10，那么下次就该是按十位来放了。直到base>m,即超高了最高位数对应的m
			base*=10;
		}
		return A;
	}
};

int main()
{	
	//冒泡排序测试
	int arr[] = {2,4,7,9,8,6};
	BubbleSort b;
	b.bubbleSort(arr,6);
	cout<<"冒泡排序测试"<<":";
	for (int i = 0; i < 6; i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	//选择排序测试
	SelectionSort s;
	s.selectionSort(arr,6);
	cout<<"选择排序测试"<<":";
	for (int i = 0; i < 6; i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	//插入排序测试
	InsertSort i;
	i.insertSort(arr,6);
	cout<<"插入排序测试"<<":";
	for (int i = 0; i < 6; i++)
                cout<<arr[i]<<" ";
        cout<<endl;

	//归并排序测试
	int arr1[]={54,35,48,36,27,12,44,44,8,14,26,17,28};
	MergeSort m;
	m.mergeSort(arr1,13);
	cout<<"归并排序测试"<<":";
	for (int i = 0; i < 13; i++)
                cout<<arr1[i]<<" ";
        cout<<endl;

	//快速排序测试
	QuickSort q;
	q.quickSort(arr1,13);
	cout<<"快速排序测试"<<":";
	for (int i = 0; i < 13; i++)
                cout<<arr1[i]<<" ";
        cout<<endl;

	//堆排序测试
	HeapSort h;
	h.heapSort(arr1,13);
	cout<<"堆排序测试"<<":";
	for (int i = 0; i < 13; i++)
                cout<<arr1[i]<<" ";
        cout<<endl;

	//希尔排序测试
	ShellSort sh;
	sh.shellSort(arr1,13);
	cout<<"希尔排序测试"<<":";
	for (int i = 0; i < 13; i++)
                cout<<arr1[i]<<" ";
        cout<<endl;

	//计数排序测试
	CountingSort c;
	c.countingSort(arr1,13);
	cout<<"计数排序测试"<<":";
	for (int i = 0; i < 13; i++)
                cout<<arr1[i]<<" ";
        cout<<endl;

	//基数排序测试
	RadixSort r;
	r.radixSort(arr1,13,2);
	cout<<"基数排序测试"<<":";
	for (int i = 0; i < 13; i++)
                cout<<arr1[i]<<" ";
        cout<<endl;
 
	return 0;
}

