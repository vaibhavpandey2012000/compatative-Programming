#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	assert(t>=1 && t<=1000);
	while(t--)
	{
		ll a,b,ans;
		cin>>a>>b;
		assert(b>=1 && b<=1000000000000000000LL && a>=1 && a<b);
		if(b-a+1<3)
			ans=(a&b);
		else if(b&1)
			ans=(b&(b-1));
		else
			ans=((b-1)&(b-2));
		cout<<ans<<endl;
	}
	return 0;
}

