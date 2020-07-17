#include<bits/stdc++.h>
using namespace std;
const int maxN=100005;
#define ll long long
ll arr[maxN];
ll topup_fib(int n)
{
	if(n=0||n==1)
	return n;
	if(arr[n]!=-1)
	return arr[n];
	int f1=topup_fib(n-1);
	int f2=topup_fib(n-2);
	arr[n]=(f1+f2);
	return arr[n];
}
int main()
{
	int n;
	cin>>n;
	memset(arr,-1,sizeof(arr));
	cout<<topup_fib(n)<<endl;
}
