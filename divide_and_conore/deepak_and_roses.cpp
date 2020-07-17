#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll binery_search(ll *arr,ll s,ll e,ll prise)
{
	while(s<=e)
	{
		ll mid=(s+e)/2;
		if(arr[mid]==prise)
		return mid;
		if(arr[mid]<prise)
		{
			s=mid+1;
		}
		else
		{
			e=mid-1;
		}
	}
	return -1;
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		ll n;
		cin>>n;
		ll arr[n];
		for(ll i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		ll prise;
		cin>>prise;
		sort(arr,arr+n);
		ll mx=1e9;
		ll l1,l2;
		for(ll i=0;i<n;i++)
		{
			ll res=binery_search(arr,i+1,n-1,prise-arr[i]);
			if(res!=-1 && (abs(arr[i]-arr[res])<mx))
			{
				l1=arr[i];
				l2=arr[res];
				mx=abs(arr[i]-arr[res]);
			}
		}
		if(l1>l2)
		swap(l1,l2);
		cout<<"Deepak should buy roses whose prices are "<<l1<<" and "<<l2<<"."<<endl;
        cout<<endl;
	}	
}