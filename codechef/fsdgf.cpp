#include<bits/stdc++.h>
using namespace std;
const int maxN=1000005;
int arr[maxN]={0},cum[maxN];
void seave()
{
	for(int i=2;i<maxN;i++) arr[i]=1;
	for(int i=2;i*i<=maxN;i++)
	{
		if(arr[i]==1)
		for(int j=i*i;j<=maxN;j+=i)
		arr[j]=0;
	}
	int cnt=0;
	for(int i=1;i<=maxN;i++)
	{
		if(arr[i]==1)
		cnt++;
		if(arr[cnt]==1)
		cum[i]=1;
	}
	for(int i=1;i<=maxN;i++)
	arr[i]=arr[i-1]+cum[i];
}
int chack(int l,int r)
{
	cout<<arr[r]-arr[l-1]<<endl;
}
int main()
{
	seave();
	int tc;
	cin>>tc;
	while(tc--)
	{
		int l,r;
		cin>>l>>r;
		
	}
}
