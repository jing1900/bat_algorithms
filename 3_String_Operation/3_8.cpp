/*
	问题：
		给定一个字符串str，判断是不是整体有效的括号字符串
		举例，str=“（）”，true，
			str =“（（）（））”，true
			Str = （（）），true
			Str = （（），false
			Str = （）（，false
			Str=（）a（），返回false
	解题思路：
		最优解时间复杂度，O(n), 空间复杂度O(1)
		1，定义一个整形遍历num，代表（出现次数和）出现次数的差值
		2，遍历过程中遇到（，则num++，
		3，遍历过程中遇到），则num--。
		4，遍历过程中如果num<0,则返回false
		5，如果一直没有出现情况4，则一直遍历下去
		6，遍历完成后，如果num==0，则返回true，否则返回false

*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class ParenthesesJudge
{
public:
	bool chkP(string s,int len)
	{
		int n = 0,i;
		for(i = 0;i<len;i++)
		{
			if(s[i] == '(')
				n++;
			if(s[i] == ')')
				n--;
			if(n<0)
				return false;
//			cout<<n<<endl;
		}
		if(n == 0)
			return true;
		else
			return false;
	}
};
int main()
{
	string s("a()()");
	ParenthesesJudge p;
	bool b= p.chkP(s,5);
	cout<<b<<endl;
	return 0;
}
