#include<bits/stdc++.h>
using namespace std;
int BF(int *arr,int n){
	// o(n^2)
	int cnt=0;
	for(int i=0;i<n-1;i++){
		int sum=arr[i];
		for(int j=i+1;j<n;j++)
		{
			sum+=arr[j];
			if(sum==0){
			//	cout<<i<<" "<<j<<endl;
				cnt++;
			}
		
		}	
	}
	return cnt;
}
int HS(int *arr,int n)
{
	int pre[n];
	pre[0]=arr[0];
	map<int,int> mp;
	mp[0]++;
	for(int i=1;i<n;i++){
		pre[i]=pre[i-1]+arr[i];
		mp[pre[i]]++;
	}
	int sum=0;
	for(auto i:mp)
	{
		int num=i.second;
		sum+=num*(num-1)/2;
	}
	return sum;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int cnt=HS(arr,n);
	
	cout<<cnt<<endl;
		
}

