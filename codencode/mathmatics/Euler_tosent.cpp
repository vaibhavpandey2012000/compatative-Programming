#include<bits/stdc++.h>
using namespace std;
int Euler_tosent(int n)
{
	int ans=n;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			ans/=(i);
			ans*=(i-1);
			while(n%i==0)
			{
				n/=i;
			}
		}
	}
	if(n>2)
	{
		ans/=(n);
		ans*=(n-1);
	}
	return ans;
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		int ans=Euler_tosent(n);
		cout<<ans<<endl;
	}
}