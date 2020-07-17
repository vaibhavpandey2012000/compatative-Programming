#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector<ll> A[n],B[n];
		ll s1=0,s2=0,s3=0;
		map<ll,ll>mp;
		for(int i=0;i<n;i++)
		{
			cin>>A[i];
			s1+=A[i];
			s3+=A[i];
			mp[A[i]]++;
		}
		for(int i=0;i<n;i++)
		{
			cin>>B[i];
			s2+=B[i];
			s3+=B[i];
			mp[B[i]]++;
		}
		int flg=1;
		for(auto e:mp)
		{
			if(e.second%2!=0)
			flg=0,break;
		}
		if(flg==0)
		{
			cout<<"-1"<<endl;
		}
		else{
			ll ans=min(s3/2-s1,s3-s2);
			cout<<ans<<endl;
		}
	}
}
