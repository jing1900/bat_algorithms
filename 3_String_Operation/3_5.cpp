/*
	问题：
		给定一个字符串str和一个整数i，i代表str中的位置，将str[0,i]移到右侧，str[I+1,n-1]移到左侧，举例：
		str：“ABCDE”，i=2，将str调整为”DEABC“。要求，时间复杂度为O（N），额外空间复杂度为O（1）
	解题思路：
		1，先将str[0,i]上的部分逆序，ABCDE，变成CBADE
		2，将str[i+1,n-1]上的部分逆序，变成CBAED
		3，然后将str整体逆序，DEABC
*/
#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
using namespace std;
class StringShift
{
public:
	//返回交换过顺序后的字符串，传入：字符串，字符串长度，中间分割位置
	string stringShift(string A, int n,int len)
	{
		if(len > n)
			exit(-1);
		reverseWord(A,0,len-1);
		reverseWord(A,len,n-1);
		reverseWord(A,0,n-1);
		return A;
	}
	
	//局部逆序函数
	void reverseWord(string &A,int low,int high)
	{
		if(low >= high)
			return;
		char temp;
		while(low < high)
		{
			temp = A[low];
			A[low] = A[high];
			A[high] =temp;
			low++;
			high--;
		}
	}
};

int main()
{
	string s("ABCDE");
	StringShift ss;
	string res = ss.stringShift(s,5,3);
	cout<<res<<endl;
	return 0;
}
