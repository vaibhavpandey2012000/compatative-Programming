#include<bits/stdc++.h>
using namespace std;
int main()
{
	stack<char>st;
	string s;
	cin>>s;
	int flg=1;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='(' || s[i]=='{' ||s[i]=='[')
		st.push(s[i]);
		else if(s[i]==')' || s[i]=='}' ||s[i]==']')
		{
			char ch=st.top();
			st.pop();
			if(s[i]==')' && ch=='('||s[i]=='}' && ch=='{'||s[i]==']' && ch=='[')
			{
				continue;				
			}
			else{
				flg=0;
				cout<<"left right not matched"<<endl;
				break;
			}
		}
	}
//	cout<<st.size()<<endl;
	if(flg==1 && st.size()==0)
	{
		cout<<"balanced"<<endl;
	}
	else{
		cout<<"unbalanced"<<endl;
	}
}