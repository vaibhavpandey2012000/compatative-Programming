#include<bits/stdc++.h>
#define ll long long
#define MX 100005
using namespace std;

int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		ll n;
		cin>>n;
		ll arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		ll gsum=arr[0],lsum=arr[0];
		for(int i=1;i<n;i++)
		{
			lsum=max(lsum+arr[i],arr[i]);
			gsum=max(gsum,lsum);
		}
		cout<<gsum<<endl;
	}
}