#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		ll y,x;
		cin>>y>>x;
		ll ans;
		if(y>=x)
		{
			if(y&1)
			ans=(y-1)*(y-1)+1+(x-1);
			else
			ans=y*y-(x-1);
		}
		else
		{
			if(x&1)
			ans=x*x-(y-1);
			else
			ans=((x-1)*(x-1)+1)+(y-1);
		}
		cout<<ans<<endl;
	}
}