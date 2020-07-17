#include<bits/stdc++.h>
using namespace std;
bool prefix(string & s1,string & s2)
{
	if(s1.length()<s2.length())
		return false;
	int l1=s2.length();
	for(int i=0;i<l1;i++)
	{
		if(s1[i]!=s2[i])
			return false;
	}
	return true;
}
int main()
{
	string s1,pre;
	getline(cin,s1);
	getline(cin,pre);
	bool ans=prefix(s1,pre);
	if(ans)
	{
		cout<<"true"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
}