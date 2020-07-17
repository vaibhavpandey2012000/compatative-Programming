#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<ll> apr(n),app(m);
	for(int i=0;i<n;i++)
	cin>>app[i];
	for(int i=0;i<m;i++)
	cin>>apr[i];
	int papr=0,papp=0,ans=0;
	while(papr<m && papp<n)
	{
		if(apr[papr]<=app[papp]+k && apr[papr]>=app[papp]-k)
		{
			ans++;
			papr++;
			papp++;
		}
		else if(apr[papr]<app[papp]-k)
		{
			papr++;
		}
		else
		papp++;
	}
	cout<<ans<<endl;
}
