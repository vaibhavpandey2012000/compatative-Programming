#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll multiply(int a,int b)
{
	if(a<b)
		swap(a,b);
	ll ans=0;
	if(b==0)
	{
		return 0;
	}
	if(b<0)
	{
		ans=multiply(a,b+1);
		ans+=(-a);
	}
	if(b>0)
	{
		ans=multiply(a,b-1);
		ans+=(a);
	}
	return ans;
}
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<multiply(a,b)<<endl;
}