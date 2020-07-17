#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
ll fun(ll num,ll par) {
	return num *((par*(par+1))/2);
}
bool parathaintime(ll *arr,ll m,ll n,ll k)
{
	ll min,i=0,j=1;
	while(k)
	{
		if(fun(arr[i],j)<m){
			k--;
			j++;
		}
		else{
			i++;
			if(i==n)
			return false;
			j=1;
		}
	}
	return true;
}

ll bineryserch(ll *arr,ll n,ll p)
{
	ll s=fun(arr[0],1),e=fun(arr[n-1],p),ans=-1;
	while(s<=e)
	{
		ll m=(s+e)/2;
		if(parathaintime(arr,m,n,p)==true)
		{
			ans=m;
			e=m-1;
		}
		else
		{
			s=m+1;
		}
	}
	return ans;
}
int main()
{
	ll p;
	cin>>p;
	ll n;
	cin>>n;
	ll arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	ll ans=bineryserch(arr,n,p);
	cout<<ans-1<<endl;
}