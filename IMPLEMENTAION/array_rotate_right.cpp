#include<bits/stdc++.h>
using namespace std;



void fxn(int *arr,int s,int e,int k)
{
	int n=e+1;
	reverse(arr+s,arr+n-k);
	reverse(arr+n-k,arr+n);
	reverse(arr+s,arr+n);
}

int main()
{
	int n,k,q;
	cin>>n>>k>>q;
	k=k%n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	fxn(arr,0,n-1,k);
	
	while(q--)
	{
		int ind;
		cin>>ind;
		cout<<arr[ind]<<endl;
	}
}