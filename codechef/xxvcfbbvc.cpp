#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    vector<ll> a,b;
    map<ll,ll> m1;//ma=m1
    map<ll,ll> m2;//mb=m2
    for(int i=0;i<n;i++)
    {
    	int temp;
    	cin>>temp;
        a.push_back(temp);
        m1.insert({a[i],i});
    }
    for(int i=0;i<n;i++)
    {
        int temp;
    	cin>>temp;
        b.push_back(temp);
        m2.insert({b[i],i});
    }
    map<ll,ll> mp2;
    for(ll i=0;i<n;i++)
    {
        ll j=m2[a[i]];
        if(j>=i)
            mp2[j-i]++;
        else
            mp2[j+n-i]++;
    }
    map<ll,ll> mp1;
    for(ll i=0;i<n;i++)
    {
        ll j=m2[a[i]];
        if(j>i)
            mp1[i+n-j]++;
        else
            mp1[i-j]++;
    }
    ll mx=INT_MIN;
    for(auto i1:mp1)
    {
    	ll pp=i1.second;
    	mx=max(mx,pp);
	}
        
    for(auto i2:mp2){
    	ll pp=i2.second;
    	mx=max(mx,pp);
	}
    cout<<mx<<endl;   
	return 0;
}
