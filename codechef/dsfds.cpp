#include<bits/stdc++.h>
using namespace std;
void bubble(int *arr,int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1])
			swap(arr[j],arr[j+1]);
			cout<<i+1<<" "<<j+1<<endl;
		}
		
	}
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	bubble(arr,n);
	for(int p=0;p<n;p++)
	cout<<arr[p]<<" ";
	cout<<endl;
}
