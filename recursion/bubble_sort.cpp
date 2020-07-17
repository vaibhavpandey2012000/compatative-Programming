#include<bits/stdc++.h>
#define ll long long
using namespace std;
void bubble_sort(int *a,int n)
{
	if(n==1)
	return;
	for(int i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1])
		{
			swap(a[i],a[i+1]);
		}
	}
	bubble_sort(a,n-1);
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	bubble_sort(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}