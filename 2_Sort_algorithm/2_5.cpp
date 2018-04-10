/*
问题:
	在行列都排好序的矩阵中找数，如果有的话，返回True，否则返回False。
	0 1 2 5
	2 3 4 7
	4 4 4 8
	5 7 7 9
解题思路：
	假定二位数组大小为M*N的话，这个过程的时间复杂度可以做到O（M+N），空间复杂度可以做到O（1），比如我们现在找3在不在这个矩阵中。
	1，从矩阵的右上角开始找，大于要找的数的话，由于行列都是有序的，这一列下面的数也一定大于这个数，因此向左移动。
	2，如果向左移动到的2小于我们要找的3的话，其左边的也一定小于3，因此从2往下移动。
	3，然后4又大于我们要找的3，只能往左移动。Find it。
	根据每一位置上的数的比较，来判断是向左还是向下，如果这个过程中找到了，我们就直接返回True.如果直到越界了还没找到，则返回false

*/
#include<vector>
#include<iostream>
#include<string.h>
using namespace std;
class NumFinder
{
public:
	//n和m分别为行和列的值，x为待寻找的数
	bool findX(int mat[3][3],int n, int m, int x)
	{
		//定义行列索引，从右上角开始
		int hang = 0,lie = m-1;
		while(hang < n && lie >= 0)
		{
			//找到，return true
			if(mat[hang][lie] == x)
				return true;
			//如果当前值大于x，则往左，列减1
			if(mat[hang][lie]>x)
				lie--;
				//如果当前值小于x，则往下，行加1
			if(mat[hang][lie] <x)
				hang++;
		}
		return false;
	}
};
int main()
{
	//定义一个3*3的二维数组
	int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	//二维向量初始化
	//vector<vector<int> > b(a,a+3);
	//将a的内容copy到b，按行来，每行的[0,2]
//	for(int i=0;i<3;i++)
	//	memcpy(a[i],a[i]+2,b[i]);
//		copy(a[i][0],a[i][2],b[i]);
//	memcpy(&b[0],*a,9*sizeof(int));
	//打印b
	//for(int i=0;i<3;i++)
	//{
	//	for(int j=0;j<3;j++)
	//		cout<<b[i][j];
	//	cout<<endl;
	//}
	NumFinder n;
	bool d=n.findX(a,3,3,9);
	cout<<d<<endl;
	return 0;
}
