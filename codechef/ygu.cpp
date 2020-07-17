#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
int arr[100001],pre[100005],suf[100005];
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	int t,n,q,l,r;
	cin>>t;
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		rep(i,n) cin>>arr[i];
		rep(i,n) pre[i]=gcd(pre[i-1],arr[i]);
		for(int i=n;i>0;i--) suf[i]=gcd(arr[i],suf[i+1]);
		while(q--)
		{
			int l,r;
			cin>>l>>r;
			cout<<gcd(pre[l-1],suf[r+1])<<endl;
		}
	}
}
