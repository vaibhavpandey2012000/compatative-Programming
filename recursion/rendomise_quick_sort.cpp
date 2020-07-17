#include<bits/stdc++.h>
#define ll long long
using namespace std;
void random_shuffle(int *arr,int s,int e)
{
	srand(time(NULL));
	int j,i;
	for( i=e;i>0;i--)
	{
		j=rand()%(i+1);
		swap(arr[i],arr[j]);
	}
}
int partition(int *arr,int s,int e)
{
	int ele=arr[e];
	int i=s-1,j=s;
	for( j=s;j<e;j++)
	{
		if(arr[j]<=ele)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[e],arr[i+1]);
	return i+1;
}
void quick_sort(int *arr,int s,int e)
{
	if(s>=e)
	return;
	int piv=partition(arr,s,e);
	quick_sort(arr,s,piv-1);
	quick_sort(arr,piv+1,e);
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
	random_shuffle(arr,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	quick_sort(arr,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}