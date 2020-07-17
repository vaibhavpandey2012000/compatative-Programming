#include<bits/stdc++.h>
using namespace std;
int timer=0;
int subarray1(int *arr,int n)//O(n^3)
{
	int mx=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int pp=0;
			for(int k=i;k<=j;k++)
			pp+=arr[k],timer++,cout<<timer<<" ";
			
			mx=max(pp,mx);
		}
	}
	return mx;
}
int subarray2(int *arr,int n)//o(n^2)
{
	int mx=0;
	for(int i=0;i<n;i++)
	{
		int sm=0;
		for(int j=i;j<n;j++)
		{
			timer++;
			cout<<timer<<" ";
			sm+=arr[j];
			mx=max(mx,sm);
		}
	}
	return mx;
}
int subarray(int *arr,int n)
{
	int sum=0,best=0;
	for(int i=0;i<n;i++)
	{
		sum=max(sum+arr[i],arr[i]);
		best=max(best,sum);
		timer++;
		cout<<timer<<" ";
	}
	return best;
}
using namespace std;
int main()
{
	int arr[]={-1,2,4,-3,5,2,-5,2},n=8;
	int ans=subarray(arr,n);
	cout<<endl<<ans<<endl;
}
