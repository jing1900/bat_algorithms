/*
		问题：
			给定一个有序数组arr，其中不含重复元素，请找到满足arr[i] ==i条件的最左的位置，如果所有位置上的都不满足，返回-1.
		解题思路：
			1，首先，生成全局变量res，记录最后一次发生上述条件的情况。
			2，如果arr[0]>N-1,那么后面的所有值都是大于N-1的，不可能出现条件那种情况，返回-1
			3，如果arr[n-1]<0,同样返回-1
			4，否则，判断M处的值是否大于M，如果大于M，那么M到N范围内的数都不可能满足条件，只能考虑0-M，反之，如果是小于M，则只能考虑M-N，如果arrm = m。首先记录下此处位置，然后由于记录的是最左的位置，则继续往左二分搜索

*/
#include<iostream>
#include<vector>
using namespace std;
class FindLeftPos
{
public:
	//传入向量arr和其长度，返回满足条件的最左位置
	int findPos(vector<int> arr,int n)
	{
		//数组为空，和后边两种情况，都是不可能满足条件的存在
		if(arr.empty()|| arr[0]> n-1||arr[n-1]<0)
			return -1;
		int res = -1;
		int low =0,high = n-1,mid;
		while(low<=high)
		{
			mid = low + (high - low)/2;
			//如果mid处的元素值小于mid,那么mid左侧的不可能满足条件，因此，low = mid+1
			if(arr[mid]<mid)
				low = mid+1;
			//如果mid处的元素大于mid。则其右侧的不可能，故high = mid-1
			else if(arr[mid]>mid)
				high = mid -1;
			//否则的话，mid处就满足条件，再往左，看是否有更左的满足条件的位置
			else
			{
				res = mid;
				high = mid-1;
			}
		}
		return res;
	}
};

int main()
{
	int a[5] = {-1,0,2,3};
	vector<int> arr(a,a+4);
	FindLeftPos F;
	cout<<F.findPos(arr,4)<<endl;
	return 0;
}
