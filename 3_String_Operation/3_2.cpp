/*
问题：
	给定两个字符串str1和str2，判断两者是否为变形词（出现的字符种类一样，且每种字符出现的次数也一样）。请实现函数判断两个字符串是否互为变形词。
解题思路：
	使用hash表做词频统计即可。Str1建立hash表1，str2建立hash表2，比对两个hash表的记录即可。实现的时候，可用固定长度的数组来替代hash表，其时间复杂度为O(N),空间复杂度为O（N）。如字符ASCII范围为255的话，则生成256大小的数组，如果是65535的话，则生成65536大小的数组。
	可以更加省空间，同时速度也更快。

*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class ChkTransForm
{
public:
	bool chkTransForm(string A,int lena,string B,int lenb)
	{
		if(lena != lenb)
			return false;
		int hashTable1[256]={0},hashTable2[256]={0},i;
		//将字符串中的每一位，其ascii值为索引，统计次数
		for(i = 0;i< lena;i++)
		{
			hashTable1[A[i]]++;
			hashTable2[B[i]]++;
		}
		i = 0;
		//按ascii码顺序对两个数组进行相似性判定
		while((i<256)&&hashTable1[i] == hashTable2[i])
			i++;
		if(i>=256)
			return true;
		else
			return false;
	}
};

int main()
{
	string a("abcd"),b("rbca");
	ChkTransForm c;
	bool bl = c.chkTransForm(a,4,b,4);
	cout<<bl<<endl;
	return 0;
}
