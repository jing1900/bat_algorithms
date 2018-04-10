/*
	问题：
		给定一个字符串str，返回str的最长无重复字符子串的长度。
		举例：str="abdc",返回4
			Str = “abcb”，则最长无重复字符子串为abc,返回3
	解题思路：
		最优解的时间复杂度为O(N),空间复杂度为O（N）
		1，从左往后遍历，求出每个字符，往左，最长无重复子串的长度，并在其中找到最大值返回。
		2，具体实施起来，我们需要两个变量，一个是hash表，map，其中统计了每种字符之前出现的位置，另一个整形变量pre，代表以当前字符的前一个字符结尾的情况下，最长无重复子串的长度。
		3，然后查找当前字符在hash表中上一次出现的位置，标注其下一个位置为A，标注前一个字符往前最长无重复子串长度的位置为位置B，如果B比A近，则为B，如果B比A远，则为A。
		4，根据这个位置来更新当前字符的pre变量，此外，hash表里的位置信息也需要更新，
		5，然后获取pre的最大值，返回即可。
*/
#include<iostream>
#include<string>
#include<map>
using namespace std;
class LongestSubstring
{
public:
	int longestSubstring(string s,int n)
	{
		//存贮每个字符和它出现的位置
		map<char,int> map;
		//上一个字符的最长无重复子串长度
		int pre = 0;
		//存贮每个字符的最长无重复子串长度
		int *dp = new int[n]();
		//计算每个字符
		for(int i = 0; i < n;i++)
		{
			//如果map中有key为s[i]的记录
			if(map.count(s[i]))
			{
				//如果第i个字符上次出现的位置比上一个字符的最长无重复子串位置往右,那么取i减去第i个字符上次出现的位置为最长无重复子串的位置
				if(map[s[i]] >= (i-pre))
					dp[i] = i-map[s[i]];
				else
					//最大无重复子串的长度：上一个字符的最大子串长度+1
					dp[i]= pre+1;
			}
			//map中还没出现key为s[i]的记录
			else
				//更新pre和map
				dp[i] = pre+1;
				pre = dp[i];
				map[s[i]] = i;
				
		}
		//最长子串字符长度，默认为0
		int res = 0;
		for(int i = 1;i<n;i++)
		{
			if(dp[i]>res)
				res = dp[i];
		}
		//删除dp
		delete []dp;
		dp = NULL;
		return res;
	}
};
int main()
{
	string s("aabcd");
	LongestSubstring L;
	cout<<L.longestSubstring(s,5)<<endl;
	return 0;
}
