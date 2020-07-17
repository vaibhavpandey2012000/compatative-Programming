#include<bits/stdc++.h>
using namespace std;
map<char,int>mp;
void fun()
{
	mp['+']=1;
	mp['-']=1;
	mp['*']=1;
	mp['/']=1;
	mp['^']=1;
	mp['(']=0;
	
}
int main()
{
	fun();
	stack<char>st;
	string s,post="";
	st.push('a');
	st.push('b');
	cout<<st.top()<<endl;
}
