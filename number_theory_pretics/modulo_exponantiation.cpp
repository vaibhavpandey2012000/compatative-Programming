#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll modulo_exp(int a,int b,int c)
{
	if(b==0)
	{
		return 1;
	}
	ll ans=modulo_exp(a,b/2,c);
	ans=((ans%c)*(ans%c))%c;
	if(b&1) ans=((ans%c)*(a%c))%c;
	return (ans+c)%c;
}
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	ll ans=modulo_exp(a,b,c);
	cout<<ans;
}