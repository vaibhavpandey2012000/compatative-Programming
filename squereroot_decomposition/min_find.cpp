#include<bits/stdc++.h>
using namespace std;
int arr[100];
int SQT[15];
int sq;
int getmin(int l,int r)
{
	int LB=l/sq;
	int RB=r/sq;
	int mn=INT_MAX;
	cout<<LB<<"  "<<RB<<endl;
	if(LB==RB)
	{
		for(int i=l;i<=r;i++)
		mn=min(mn,arr[i]);
		return mn;
	}
	for(int i=l;i<sq*(LB+1);i++)
	{
		mn=min(mn,arr[i]);
	}
	for(int i=LB+1;i<RB;i++)
	{
		mn=min(mn,SQT[i]);
	}
	for(int i=RB*sq;i<=r;i++)
	{
		mn=min(mn,arr[i]);
	}
	return mn;
}
int main()
{
	int n;
	cin>>n;
	sq=sqrt(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int cnt=0;
	for(int i=0;i<n;i+=sq)
	{
		int mn=INT_MAX;
		for(int j=i;j<i+sq && j<n;j++)
		{
			mn=min(mn,arr[j]);
		}
		SQT[cnt++]=mn;
	}
		cout<<sq<<endl;
	int q;
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		l--,r--;
		cout<<getmin( l, r)<<endl;
	}
}