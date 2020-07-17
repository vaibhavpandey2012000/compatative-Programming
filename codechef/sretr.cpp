#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		string s;
		cin>>s;
		int cnt=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='x'&&s[i+1]=='y'|| s[i]=='y'&&s[i+1]=='x')
			{
				cnt++;
				i+=1;
			}
		}
		cout<<cnt<<endl;
	}
}
