#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fact(int n)
{
	if(n==1)
		return 1;
	ll ans=n*fact(n-1);
	return ans;
}
int main()
{
	int n;
	cin>>n;
	cout<<(ll)fact(n)<<endl;
}
