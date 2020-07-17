#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll power(int a,int b)
{
	if(b==0)
		return 1;
	ll ans=power(a,b/2);
	ans=ans*ans;
	if(b&1)return a*ans;
	return ans;
}
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<power(a,b)<<endl;
}