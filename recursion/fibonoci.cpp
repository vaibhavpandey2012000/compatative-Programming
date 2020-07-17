#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fib(int n)
{
	if(n==0 || n==1)
		return n;
	ll ans=fib(n-1)+fib(n-2);
	return ans;
}
int main()
{
	int n;
	cin>>n;
	cout<<fib(n)<<endl;
}