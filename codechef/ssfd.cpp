#include <bits/stdc++.h>

using namespace std;

long gcd(long a,long b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){

    int tc;

    cin>>tc;

    while(tc--)
    {
        long a,b,x,y;

        cin>>a>>b>>x>>y;

        if(gcd(a,b)==gcd(x,y))
        cout<<"YES"<<endl;

        else

        cout<<"NO"<<endl;
    }
}
