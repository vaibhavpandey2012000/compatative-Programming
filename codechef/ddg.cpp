#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    cin>>n;
    vector<ll> a(n), b(n);
    set<ll,ll> m1;
    set<ll,ll> m2;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        m1[a[i]]=i;
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        m2[b[i]]=i;
    }
    set<int,int> mp;//mp1
    for(ll i=0;i<n;i++)
    {
        ll j=m2[a[i]];//ma,mb
        if(j>i)
            mp[i+n-j]++;
        else
            mp[i-j]++;
    }
    set<int,int> mp0;
    for(int i=0;i<n;i++)
    {
        int j=m2[a[i]];
        if(j>=i)
            mp0[j-i]++;
        else
            mp0[j+n-i]++;
    }
    int mx=0;
    for(auto it:mp)
        mx=max(mx,it.S);
    for(auto it:mp0)
        mx=max(mx,it.S);
    cout<<mx<<endl;  
	  return 0;
}
