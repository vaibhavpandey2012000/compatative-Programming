#include<bits/stdc++.h>
using namespace std;
int countsetbit(int n)
{
	int ans=0;
	while(n>0)
	{
		if(n&1)
			ans++;
		n=(n>>1);
	}
	return ans;
}
int fstcount(int n)
{
	int ans=0;
	while(n)
	{
		n=n&(n-1);
		ans++;
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	cout<<countsetbit(n)<<endl;
	cout<<fstcount(n)<<endl;
	cout<<__builtin_popcount(n)<<endl;
}