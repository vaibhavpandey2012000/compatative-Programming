#include<bits/stdc++.h>
using namespace std;
int arr[100005]={0,};
int sum[100005]={0,};
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		arr[temp]++;
	}
	for(int i=2;i<100000;i++)
	{
		for(int j=i;j<=100000;j+=i)
		{
			sum[i]+=arr[j];
		}
	}
	sum[1]=n;
	int q;
	cin>>q;
	while(q--)
	{
		int p;
		cin>>p;
		cout<<sum[p]<<endl;
	}
}