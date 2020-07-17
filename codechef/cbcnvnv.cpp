#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
     int n;
     cin>>n;
     vector<ll>a(n),b(n);
     for(int i=0;i<n;i++)
     {
        cin>>a[i];
     }
      for(int i=0;i<n;i++)
     {
        cin>>b[i];
     }
     ll ans=0;
     ll s1=0,s2=0;
     for(int i=0;i<n;i++)
     {
       s1+=a[i];
       s2+=b[i];
       if(a[i]==b[i] and s1==s2)
       {
           ans=ans+a[i];
       }
     }
     cout<<ans<<"\n";
    }
}
