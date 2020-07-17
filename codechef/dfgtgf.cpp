// CPP program to move every character 
// K times ahead in a given string 
#include <bits/stdc++.h> 
using namespace std; 
map<char,char>mp;
int main(){ 
	string s;
	cin>>s;
	char pp='a';
	for(int i=0;i<26;i++)
	{
		char aa=char('a'+i);
		char bb=char('t'+i);
		if('t'+i>122)
		{
			bb=pp;
			pp++;
		}
		mp[aa]=bb;
		
	}
	string sss="";
	for(auto e:mp)
	{
		cout<<e.first<<" "<<e.second<<endl;
	//	sss+=mp[e];
	}
	cout<<sss<<endl;
}

