#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int n;
	cin>>n;
	ll arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	ll mx=INT_MIN,sum=0;
	for(int i=0;i<n;i++)
	{
		sum=max(sum+arr[i],arr[i]);
		mx=max(mx,sum);
	//	cout<<sum<<" "<<mx<<endl;
	}
	cout<<mx<<endl;
}