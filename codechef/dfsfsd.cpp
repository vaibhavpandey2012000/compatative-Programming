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
		unordered_map<ll,ll>mp;
		bool flg=1;
		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			mp[(temp+i)%n]++;
			if(mp[((temp+i)%n+n)%n]>1)
			flg=0;
		}
		if(flg)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
}
