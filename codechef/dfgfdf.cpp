#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<ll> a(n), b(n);
    map<ll,ll> ma;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        ma.insert({a[i],i});
       // ma[a[i]]=i;
    }
    map<ll,ll> mb;
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
         mb.insert({b[i],i});
       // mb[b[i]]=i;
    }
    map<ll,ll> mp1;
    map<ll,ll> mp2;
    for(int i=0;i<n;i++)
    {
        ll j=mb[a[i]];
        if(j>=i)
            mp2[j-i]++;
        else
            mp2[j+n-i]++;
    }
    for(int i=0;i<n;i++)
    {
        ll j=mb[a[i]];
        if(j>i)
            mp1[i+n-j]++;
        else
            mp1[i-j]++;
    }
    ll mx=INT_MIN;
    for(auto i1:mp1){
    	ll pp=i1.second;
    	 mx=max(mx,pp);
	}
    for(auto i2:mp2)
    {
    	ll pp=i2.second;
    	mx=max(mx,pp);
	}
        
    cout<<mx<<endl;  
	return 0;
}

