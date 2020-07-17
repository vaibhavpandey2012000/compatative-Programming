#include<bits/stdc++.h>
using namespace std;
const int maxN=100005;
int arr[maxN],BIT[maxN];
void update(int i,int val ,int n)
{
	while(i<=n)
	{
		BIT[i]=min(BIT[i],val);
		i+=(i&(-i));
	}
}
int quary(int i)
{
	int ans=INT_MAX;
	while(i>0)
	{
		ans=min(ans,BIT[i]);
		i-=(i&(-i));
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		BIT[i]=INT_MAX;
	for(int i=1;i<=n;i++)
		cin>>arr[i] ,update(i,arr[i],n);

	int q;
	cin>>q;
	while(q--)
	{
		int ii;
		cin>>ii;
		cout<<quary(ii)<<endl;
	}
}