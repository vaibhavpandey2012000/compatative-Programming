#include<bits/stdc++.h>
using namespace std;
string s="";
void printp(int n,int ss,int ee)
{
	if(ee==n)
	{
		cout<<s<<endl;
		s="";
		return;
	}
	else
	{
		cout<<ss<<" "<<ee<<endl;
		if(ee<ss)
		{
			s+=")";
			printp(n,ss,ee+1);
		}
		if(ss<n)
		{
			s+="(";
			printp(n,ss+1,ee);
		}
	}
}
int main()
{
	int n;
	cin>>n;
	printp(n,0,0);
}