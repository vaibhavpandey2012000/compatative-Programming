#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll power_optimization(int a,int n)
{
	ll ans=1;
	while(n>0)
	{
		if(n&1)
		{
			ans=ans*a;	
		}
		a=a*a;
		n=(n>>1);
	}
	return ans;
}
int main()
{
	int a,n;
	cin>>a>>n;
	cout<<power_optimization(a,n)<<endl;
}