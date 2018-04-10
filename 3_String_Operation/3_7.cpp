/*
	问题：
		给定一个字符串str，将其中所有空格字符替换成“%20”，假设str有足够空间
		
	解题思路：
		比如有 str=“a b c”
		1，遍历str，发现空格数量为2，所以str在替换后，长度为3+2*3
		2，从左往后遍历数组，从数组索引8的位置开始放元素，遇到非空格就直接放，如果有空格就依次放0,2，%

*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class SpaceReplace
{
public:
	string spaceReplace(string s,int len)
	{
		int spaceNum = 0,i,j;
		//原数组空格数
		for(i = 0; i<len;i++)
		{
			if(s[i] == ' ')
				spaceNum++;
		}
		//新数组长度
		int newLen = len+2*spaceNum;
		//cout<<newLen<<endl;
		//倒序定义数组
		string res(newLen,0);
		//对原来的数组倒序访问，放入新数组
		for(i = len-1,j= newLen-1;j>=0;)
		{
			if(s[i] == ' ')
			{
				res[j--] = '0';
				res[j--] = '2';
				res[j--] = '%';
				i--;
			}
			else
				res[j--] = s[i--];
		}
		return res;
	}
};
int main()
{
	string s("a b c");
	SpaceReplace S;
	string res = S.spaceReplace(s,5);
	cout<<res<<endl;
	return 0;
}
