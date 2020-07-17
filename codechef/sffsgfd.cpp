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
		ll mxx;
		if(l==r) mxx=l;
		else if((r-l)==1) mxx=(r&l);
		else{
			if(((r-1)&r)>((r-2)&(r-1)))
			mxx=((r-1)&r);
			else
			mxx=((r-2)&(r-1));
		}
		cout<<mxx<<endl;
	}
}
