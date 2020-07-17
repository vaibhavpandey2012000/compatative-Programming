#include<bits/stdc++.h>
using namespace std;
string ss="!@#$%^&*()-+";
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int sa=0,ca=0,na=0,sc=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]-'a'>=0 && s[i]-'a'<26)
		sa=1;
		else if(s[i]-'A'>=0 && s[i]-'A'<26)
		ca=1;
		else if(s[i]-'0'>=0 && s[i]-'0'<=9)
		na=1;
		else{
			for(int j=0;j<ss.length();j++)
			if(ss[j]==s[i]) {
				sc=1;
				break;
			}
		}
	}
	int tt=4-sa-ca-na-sc;
	if(n>5)
	{
		cout<<tt<<endl;
	}
	else{
		if(6-n>tt)
		cout<<6-n<<endl;
		else
		cout<<tt<<endl;
	}
}
