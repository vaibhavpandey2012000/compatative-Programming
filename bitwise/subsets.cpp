#include<bits/stdc++.h>
using namespace std;
void printstr(string s,int n)
{
	int i=0;
	while(n>0)
	{
		if((n&1)==1)
		{
			cout<<s[i];	
		}
		n=(n>>1);
		i++;
	}
	cout<<endl;
}
void subset(string s,int n)
{
	int mask=(1<<n);
	for(int i=0;i<mask;i++)
	{
		printstr(s,i);
	}
}
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	subset(s,n);
}