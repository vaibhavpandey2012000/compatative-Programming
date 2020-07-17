#include<bits/stdc++.h>
using namespace std;
bool comp(string s1,string s2)
{
	if(s1<s2)
		return true;
	else
		{
			int l1=s1.length();
			int l2=s2.length();
			int p=min(l1,l2);
			string ss;
			if(p==l1)
			{
				ss=s2.substr(0,l1);
				if(s1==ss)
				{
					return s1.length()>s2.length();
				}
				else 
				{
					return s1<s2;
				}
			}
			else {
				ss=s1.substr(0,l2);
				if(s2==ss)
				{
					return s1.length()>s2.length();
				}
				else 
				{
					return s1<s2;
				}
			}
		}
}
int main()
{
	int n;
	cin>>n;
	vector<string>s(n);
	for(int i=0;i<n;i++)
	cin>>s[i];
	sort(s.begin(),s.end(),comp);
	for(int i=0;i<n;i++)
	cout<<s[i]<<endl;
}