#include<bits/stdc++.h>
#define ll long long
using namespace std;
int GCD(int a,int b)
{
	if(b==0) return a;
	return GCD(b,a%b);
}
int main()
{
	int n,d;
	cin>>n>>d;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	for(int i=0;i<GCD(n,d);i++)
	{
		int temp=arr[i];
		int j=i,k;
		while(1)
		{
			 k=j+d;
			if(k>=n)
			k=k-n;
			if(k==i)
			break;
			arr[j]=arr[k];
			j=k;
		}
		arr[j]=temp;
	}
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
}
