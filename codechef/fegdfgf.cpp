#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll power1(int a,int b)
{
	if(b==0)
	return 1;
	ll ans=power1(a,b/2);
	ans=ans*ans;
	if(b&1) return ans*a;
	return ans;
}
ll power(int a,int b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a,b--;
		else 
		a=a*a ,b=(b>>1);
	}
	return ans;
}
int main()
{
	int a,b;
	cin>>a>>b;
	ll ans=power(a,b);
	cout<<ans<<endl;
}
