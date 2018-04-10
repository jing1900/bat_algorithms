#include<iostream>
#include<string>
using namespace std;
class Rotation
{
public:
	bool chkRotation(string A,int lena, string B,int lenb)
	{
		string sum = A + A;
		string::size_type pos = sum.find(B);
		if(pos != string::npos)
			return true;
		else
			return false;
	}
};

int main()
{
	string a = "abcd";
	int lena = 4;
	string b = "cdab";
	int lenb = 4;
	Rotation r;
	bool bl = r.chkRotation(a,lena,b,lenb);
	cout<<bl<<endl;
}
