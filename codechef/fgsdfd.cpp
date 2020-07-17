#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
ll me(int a,int b)
{
	if(b==0)
	return 1;
	ll ans=me(a,b/2);
	ans=((ans%MOD)*(ans%MOD))%MOD;
	if(b&1)
	ans=(ans*a)%MOD;
	return ans;
}
int main()
{
	int n;
	cin>>n;
	ll ans=0;
	int ee=0,oo=0,eo=0;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		if(a%2==0 && b%2==0)
		ee++;
		else if(a%2==1 && b%2==1)
		oo++;
		else
		eo++;
	}
	if(eo==0 && oo%2==0)
	ans=0;
	else if(eo==0 && oo%2==1)
	ans=me(2,n);
	else if(ee && eo==0 && oo==0)
	ans=0;
	else
	ans=me(2,n-1);
	cout<<ans<<endl;
}
