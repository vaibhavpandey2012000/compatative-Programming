#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll power(int a,int b)
{
	if(b==0)
	return 1;
	ll ans=power(a,b/2);
	ans=(ans*ans)%MOD;
	if(b&1) return (ans*a) %MOD;
	return ans;
	
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int a,b;
		cin>>a>>b;
		ll ans=power(a,b);
		cout<<ans<<endl;
	}
}