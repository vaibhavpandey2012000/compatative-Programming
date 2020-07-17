#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000005
using namespace std;
bool prime[MAX];
void primeseave( ll n) 
{  
    memset(prime, true, sizeof(prime)); 
  
    for (ll p=2; p*p<=MAX; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (ll i=p*p; i<=MAX; i += p) 
                prime[i] = false; 
        } 
    } 
    ll cnt=0;
    for (ll p=2; p<=MAX; p++) {
	
       if (prime[p]) 
          cnt++;
		if(cnt==n)
		{
			cout<<p<<endl;
			return;
		 } 
	 }
}
signed main()
{
	ll n;
	cin>>n;
	primeseave(n);
}