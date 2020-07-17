#include<bits/stdc++.h>
#define ll long long
const int maxN=100005;

using namespace std;
int main()
{
	string s;
	getline(cin,s);
	if(s[0]='a')
	{
		string ss=s.substr(4,s.length()-4);
		cout<<ss<<endl;
	}
	else if(s[0]=='f'){
		string ss=s.substr(6,s.length()-5);
		cout<<ss<<endl;
	}
	
}
