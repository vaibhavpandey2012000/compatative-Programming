#include <bits/stdc++.h>
#define fst first
#define sec second
#define mp make_pair
using namespace std;
typedef long long ll;
 
int n;
vector<ll> freq[1000001];
 
int main() {
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		freq[a].push_back(i);
	}
	ll sumprob=0;
	for(int i=1;i<=1000000;i++){
		ll temp=0;
		for(ll ind:freq[i]){
			sumprob+=(ind-temp-1)*(ind-temp-1);
			temp=ind;
		}
		sumprob+=(n-temp)*(n-temp);
	}
	cout<<fixed<<setprecision(6)<<1e6-1.0*sumprob/n/n;
	return 0;
}