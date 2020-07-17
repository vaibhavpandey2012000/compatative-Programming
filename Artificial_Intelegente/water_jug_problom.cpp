#include<bits/stdc++.h>
using namespace std;
long a,b,c;
long gcd(long a,long b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        cin>>a>>b>>c;
        if(c<max(a,b)&&c%gcd(a,b)==0)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
}