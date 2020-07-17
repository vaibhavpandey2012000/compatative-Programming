#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<long long>v;
void solve( int  n)
{
	ll num=0,pp=1;
	while(n)
	{
		int rem=n%2;
		if(rem)
		num+=9*pp;
		n=(n>>1);
		pp=pp*10;
	}
	v.push_back(num);
}
void seave()
{
	int i=1;
	while(i<10000)
	{
		solve(i);
		i++;
	}
}
int main()
{
	seave();
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		for(int i=0;i<v.size();i++)
		{
			if(v[i]%n==0){
				cout<<v[i]<<endl;
				break;
			}
			
		}
	}
}
