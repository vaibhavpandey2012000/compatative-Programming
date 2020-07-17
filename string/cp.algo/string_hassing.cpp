#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll compute_hash(string const &s)
{
	const int p=31;
	const int mod=1e9+7;
	ll hash_val=0;
	ll pow_p=1;
	for(auto c:s)
	{
		hash_val+=(hash_val+(c-'a'+1)*pow_p)%mod;
		pow_p=(pow_p*p)%mod;
	}
	return hash_val;
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<compute_hash(s1)<<" "<<compute_hash(s2)<<endl;
}