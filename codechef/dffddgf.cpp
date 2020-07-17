#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		ll n;
		cin>>n;
		ll ans=0;
		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			ans+=temp/3;
		}
		cout<<ans<<endl;
	}

}
