#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n];
	long ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=1;i<n;i++)
	{
		if(arr[i]<arr[i-1]){
			ans+=abs(arr[i]-arr[i-1]);
			arr[i]=arr[i-1];
		}
	}
	cout<<ans<<endl;
}