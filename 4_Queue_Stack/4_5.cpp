/*
		问题：
			有一个整形数组arr和一个大小为W的窗口，从数组的最左边滑到最右边。窗口每次往右滑动一个位置。返回一个长度为n-w+1的数组res，res[i]表示每一种窗口状态下的最大值。如有数组 4 3 5 4 3 3 6 7，w=3，则第一个窗口最大值为5。
			
		解题思路：
			普通的解法时间复杂度为O（n*w),也就是每次对每个窗口遍历其中的w个数，选出最大值。
			最优的解法，时间复杂度为O（n），本题的关键在于使用双端队列这样一个结构，设有一个双端队列qMax。双端队列中存贮的是数组中元素的下标。假设当前元素值为arr[i]，放入规则为：
				1，如果qmax为空，则直接放入
				2，如果qmax非空，取出当前qmax队尾存放的下标j。如果arr[j]>arr[i]，直接把下标i放入qmax的队尾（ai比较小，继续放即可）
				3，如果arr[j]<=arr[i],则一直从qmax队尾弹出下标，直到某个下标的对应值大于arr[i],把i放入qmax队尾。（ai比较大，弹出之前较小的，放入大的。
				取出规则：
				1，如果qmax队头的下标等于i-w，（相当于已经过期了（窗口滑动时该元素已经过了窗口），弹出）弹出qmax当前队头下标
		整体时间复杂度为O（n）

*/

#include<iostream>
#include<vector>
#include<string>
#include<deque>
using namespace std;

class SlideWindowMax
{
public:
	//传入：向量，向量长度，窗口大小
	vector<int> slide(vector<int> v,int n, int w)
	{
		if(w == 1)
			return v;
		//定义双端队列,存贮向量v的下标
		deque<int> deq;
		//定义向量，存贮每个窗口的最大值
		vector<int> res;
		int i;
		for(i = 0;i < n;i++)
		{
			//如果双端队列为空，或者其队尾元素对应的值大于当前位置对应的元素值,直接放入当前位置即可
			if(deq.empty()||v[deq.back()]>v[i])
				deq.push_back(i);	
			//
			else
			{
				//否则，如果队列非空且队尾元素对应的值小于当前位置对应的元素值，那么可以直接将队尾元素pop掉，因为没啥用了
				while(!deq.empty()&&v[deq.back()]<=v[i])
					deq.pop_back();
				deq.push_back(i);
			}
			//如果队头元素过了窗口有效期，pop掉
			while((i-deq.front())>=w)
				deq.pop_front();
			if(i<w-1)
				continue;
			//将双端队列的队头元素对应的值push进最大值向量res，因为按照之前的规则，队头元素对应的值是大于后面元素对应的值的。
			res.push_back(v[deq.front()]);
		}
		//返回最大值向量
		return res;

	}
};

int main()
{
	int a[8] = {4,3,5,4,3,3,6,7};
	SlideWindowMax S;
	vector<int> arr(a,a+8),res;
	res = S.slide(arr,8,3);
	for(vector<int>::iterator iter = res.begin();iter!=res.end();iter++)
		cout<<*iter<<" ";
	cout<<endl;
	return 0;
}
