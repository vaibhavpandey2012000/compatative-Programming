#include <bits/stdc++.h>
#define ll long 
using namespace std;

ll gcd(ll a, ll b) 
{ 
    if(b==0) return a;
    return gcd(b, a % b); 
} 

void leftRotate(ll arr[], ll d, ll n) 
{ 
    d = d % n; 
    ll g_c_d = gcd(d, n); 
    for (int i = 0; i < g_c_d; i++) { 
        ll temp = arr[i]; 
        ll j = i; 
        while (1) { 
            ll k = j + d; 
            if (k >= n) 
                k = k - n; 
            if (k == i) 
                break; 
            arr[j] = arr[k]; 
            j = k; 
        } 
        arr[j] = temp; 
    } 
} 
void rightRotateByOne(ll A[], ll n)
{
	ll last = A[n - 1];
	for (ll i = n - 2; i >= 0; i--)
		A[i + 1] = A[i];

	A[0] = last;
}

void rightRotate(ll A[], ll k, ll n)
{
	for (ll i = 0; i < k; i++)
		rightRotateByOne(A, n);
}

int main()
{
	ll n;
	cin>>n;
	ll A[n];
	for(ll i=0;i<n;i++)
	cin>>A[i];
	ll k;
	cin>>k;
	if(k>0){
		rightRotate(A,k,n);
	}
	else{
		leftRotate(A,-k-1,n);
	}

	for (ll i = 0; i < n; i++)
		cout<<A[i]<<" ";

	return 0;
}
