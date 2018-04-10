/*
问题：
	给定一个字符串，请在单词见做逆序调整。如，“pig loves dog",逆序成”dog loves pig“
解题思路：
	1，首先，我们要实现一个将字符串局部所有字符逆序的函数f，如abcdef，先第一个和最后一个交换，然后交换第二个和倒数第二个，交换到中间停止。
	2，接着，利用f将字符串中所有字符逆序，变成“god sevol gip”。
	3，最后，找到逆序后的字符串中每个单词的区域，利用f将每个单词的区域逆序，变成“dog loves pig”

*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class SentenceReverse
{
public:
	//传入字符串和字符串长度
	string reverseSentence(string A,int n)
	{
		//逆序整个字符串
		reverseWord(A,0,n-1);
		int i = 0,j = 0;
		//逆序每个单词
		while(i < n)
		{
			//空格的话，索引往右挪
			while(i<n &&A[i] == ' ')
				i++;
			if(i>=n)
				return A;
			//j为每个单词的起始位置
			j = i;
			while(i <n &&A[i]!=' ')
				i++;
			//如果到最后的话，翻转完直接返回
			if(i >= n)
			{
				reverseWord(A,j,n-1);
				return A;
			}
			//翻转每个单词。上面while判定的时候，i多加了一次。
			reverseWord(A,j,i-1);
		}
		return A;
	}
	
	//逆序函数
	void reverseWord(string &A,int low,int high)
	{
		if(low>=high)
			return;
		char temp;
		while(low <high)
		{
			//交换最左最右位置的值
			temp = A[low];
			A[low]=A[high];
			A[high] = temp;
			//两者往中间移，直到low>high,即过了中点。
			low++;
			high--;
			
		}
		
	}
};

int main()
{
	string arr("dog loves pig");
	SentenceReverse s;
	string arr1 = s.reverseSentence(arr,13);
	cout<<arr1<<endl;
	return 0;
}
