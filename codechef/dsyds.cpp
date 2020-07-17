#include<bits/stdc++.h>
using namespace std;
int subarryK(int *arr,int n,int k)
{
	int len=0;
	int pre=0;
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
	{
		pre+=arr[i];
		if(mp.find(k-pre) != mp.end())
		{
			len=max(len,i-mp[k-pre]);
		}
		else{
			mp[pre]=i;
		}
	}
	return len;
}
int main()
{
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int &i:arr)
	cin>>i;
	int ans= subarryK(arr,n,k);
	cout<<ans<<endl;
}
