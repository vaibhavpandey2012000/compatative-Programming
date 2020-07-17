#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

void solve()
{
	array<int,3>arr[MX];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i][0]>>arr[i][1];
		arr[i][2]=i;
	} 
	char c[2]={'C','J'},ans[MX];
	int l[2];
	sort(arr,arr+n);
	
	l[0]=l[1]=INT_MAX;
	for(int i=n-1;i>0;i--)
	{
		int flg=0;
		int p1=0,p2=1;
		if(l[p1]>l[p2])
		{
			swap(p1,p2);
		}
		if(arr[i][1]<=l[p1])
		{
			flg=1;
			ans[arr[i][2]]=c[p1];
		}
		if(!flg && arr[i][1]<= l[p2])
		{
			flg=1;
			ans[arr[i][2]]=c[p2];
		}
		if(flg==0)
		{
			cout<<"IMPOSSIBLE\n";
			return;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i];
	}
	cout<<endl;
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
}