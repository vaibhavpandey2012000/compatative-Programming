#include<bits/stdc++.h>
using namespace std;
void parmute(string s,int i)
{
	if(s[i]=='\0')
	{
		cout<<s<<endl;
		return;
	}
	for(int j=i;j<s.length();j++)
	{
		swap(s[i],s[j]);
		parmute(s,i+1);
		//swap(s[i],s[j]);
	}
}
int main()
{
	string s;
	cin >> s;
	parmute(s,0);
}