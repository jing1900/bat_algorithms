/*
问题：
        给定一个字符串类型的数组strs，请找到一个拼接顺序，使得将所有字符串拼接起来组成的大字符串是所有可能性中字典顺序最小的，并返回这个大字符串。如strs = ["abc","de"]，可以拼成“abcde”，也可以拼成“deabc”，但前者字典序更小，所以返回“abcde”
解题思路：
        1,如果数组长度为N的话，那么这道题的最优解为O（N*logN），其实质是一种排序的实现。排序的结果就是我们拼接的顺序。
        2,一般的思路是：根据每个字符串的字典顺序排序：
                如：["abc","de"] -》["abc","de"]
                但这种思路是错误的，
                如：["ba","b"] -》["b","ba"],这样拼接出来是bba，但对本题来说，最小的字典序是bba。所以这个思路是错误的。
        3,正确的思路是：如果str1+str2 < str2+str1,则str1在前面，否则，str2在前面
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class MinDict
{
public:
	//找到最小字典序的数组排列。传入：strs为字符串数组，n为数组长度
	string findSmallest(vector<string> strs,int n)
	{
		//对字符串数组进行排序,排序的标准是：如果str1+str2 < str2+str1,则str1在前面，否则，str2在前面
		QuickSort(strs,0,n-1);
		string res;
		for(int i = 0; i < n;i++)
			res += strs[i];
		return res;
	}
	
	//对字符串数组里的元素按字典序排列
	void QuickSort(vector<string> &strs,int low,int high)
	{
		if(low < high)
		{
			//该操作后，res处的值处于它该处的位置，
			int res = Partition(strs,low,high);
			//迭代处理数组左边和右边
			QuickSort(strs,low,res-1);
			QuickSort(strs,res+1,high);
		}
	}
	
	//
	int Partition(vector<string> &strs,int low,int high)
	{
		//记录数组的初始元素
		string key = strs[low];
		while(low <high)
		{
			//当前的low和high，符合左边比较小，右边比较大的原则，所以不动，让high索引往前挪一位
			while(low<high && LT(key,strs[high]))
				high--;
			//否则的话，将high处的内容换过来
			strs[low] = strs[high];
			//将现在low处的值与原始的low值进行比较，如果比较小的话，则满足原则，low继续往右移动
			while(low <high&& LT(strs[low],key))
				low++;
			//将原来key处的值放在现在high的位置，然后继续处理
			strs[high] = key;
				
		}
		//将原始low处的元素放在它应该待的位置，新的low处。
		strs[low] = key;
		//此时low处的元素已被放在了合适的位置
		return low;
	}

	//判断s1+s2是大于还是小于s2+s1
	bool LT(string s1,string s2)
	{
		string temp1 = s1+s2,temp2 = s2+s1;
		if(temp1<= temp2)
			return true;
		else
			return false;
	}
};

int main()
{
	string a("abc"),b("de"),c("cab");
	vector<string> arr;
	arr.push_back(b);
	arr.push_back(a);
	arr.push_back(c);
	MinDict m;
	string res = m.findSmallest(arr,3);
	cout<<res<<endl;
	return 0;
}
