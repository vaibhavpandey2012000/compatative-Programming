#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int &i:arr)
	cin>>i;
	for(int i=0,j=n-1;i<j;i++,j--)
	swap(arr[i],arr[j]);
	for(int &i:arr)
	cout<<i<<" ";
}