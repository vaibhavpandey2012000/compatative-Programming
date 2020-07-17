#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN=100000;
vector<ll> v;
void seave(){
	v.push_back(1);
	v.push_back(1);
	ll a=1,b=1;
	while(1)
	{
		ll c=a+b;
		if(c>10000000000) break;
		v.push_back(c);
		a=b;
		b=c;	
	}
	cout<<v.size()<<endl;
	cout<<v[v.size()-1]<<endl;
}
void solve(){
	ll n;
	cin>>n;
	int ind=lower_bound(v.begin(),v.end(),n)-v.begin();
	if(v[ind]==n)
	cout<<"IsFibo"<<endl;
	else
	cout<<"IsNotFibo"<<endl;
}
int main()
{
	seave();
	int tc;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
}
