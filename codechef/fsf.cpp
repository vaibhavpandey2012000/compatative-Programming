#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		ll x,y,l,r;
		cin>>x>>y>>l>>r;
		ll num=x|y;
		int val,mx=INT_MIN;
		for(ll i=l;i<=r;i++)
		{
			if(i&num>mx)
			{
				mx=i&num;
				val=i;
			}
		}
		cout<<val<<endl;
	}
}
