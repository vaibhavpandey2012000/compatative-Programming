#include<bits/stdc++.h>
#define ll long long
using namespace std;

void printseq(string s,int n)
{
	for(int i=s.length()-1;i>=0;i--)
	{
		if(n&1) cout<<s[i];
		n=(n>>1);
	}
	cout<<endl;
}
void subsequence(string s,int l)
{
	for(int i=0;i<(1<<l);++i)
	{
		printseq(s,i);
	}
}


int main()
{
	string s;
	cin>>s;
	int l=s.length();
	subsequence(s,l);
}