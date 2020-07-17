#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxN=100005;
const int MOD=1000000007;
ll arr[maxN];
ll fib_topup(int n)
{
	if(n==0||n==1)
	return n;
	if(arr[n]!=0)
	return arr[n];
	ll f1=fib_topup(n-1)%MOD;
	ll f2=fib_topup(n-2)%MOD;
	arr[n]=(f1+f2)%MOD;
	return arr[n];
}
ll fib_bottom(int n)
{
	ll fib[n+1];
	fib[0]=0;
	fib[1]=1;
	for(int i=2;i<=n;i++)
	fib[i]=(fib[i-1]+fib[i-2])%MOD;
	return fib[n];
}
int main()
{
	int n;
	cin>>n;
	cout<<fib_topup(n)<<endl;
	cout<<fib_bottom(n)<<endl;
}
