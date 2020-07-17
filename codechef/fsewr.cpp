#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		ll a1,b1,c1;
		cin>>a1>>b1>>c1;
		ll a2,b2,c2;
		cin>>a2>>b2>>c2;
		set<ll>s;
		if(a1!=a2)
		s.insert(a1-a2);
		if(b1!=b2)
		s.insert(b1-b2);
		if(c1!=c2)
		s.insert(c1-c2);
		cout<<s.size()<<endl;
	}
}
