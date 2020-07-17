#include<bits/stdc++.h>
using namespace std;
map<char,int>mp;
void fun()
{
	mp['(']=0;
	mp['+']=1;
	mp['-']=1;
	mp['*']=2;
	mp['/']=2;
	mp['^']=3;
	
}
int main()
{
	fun();
	string s,post="a",k="aaaadd";
	cin>>s;
	stack<char>ch;
	for(int i=0;i<s.length();i++)
	{
		cout<<s[i]<<" ";
		if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')
		post+=s[i];
		else if(s[i]=='(')
		{
			ch.push(s[i]);
		}
		else if(s[i]==')')
		{
			while(1)
			{
				char pp=ch.top();
				if(pp=='(')
				{
					break;
				}
				post+=pp;
			}
		}
		else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^'){
		//	cout<<s[i]<<endl;
			
			if( !ch.empty() && mp[s[i]]<=mp[ch.top()])
			{
				post+=ch.top();
				ch.pop();
			}
		//	cout<<s[i]<<endl;
			ch.push(s[i]);
		}
	}
	cout<<k<<endl;
//	while(!ch.empty())
//	{
//		post+=ch.top();
//		ch.pop();
//	}
	cout<<post<<endl;
}
