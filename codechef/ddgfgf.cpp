#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> Robin_karp(string s,string t)
{
	const int p=31;
	const int m=1e9+7;
	int S=s.size(),T=t.size();
	vector<ll> p_pow(max(S,T));
	p_pow[0]=1;
	for(int i=1;i<p_pow.size();i++)
	{
		p_pow[i]=(p_pow[i-1]*p)%m;
	}
	vector<ll> h(T+1,0);
	for(int i=0;i<T;i++)
	{
		h[i+1]=(h[i]+(t[i]-'a'+1)*p_pow[i])%m;
	}
	int h_s=0;
	for(int i=0;i<S;i++)
	h_s=(h_s+(s[i]-'a'+1)*p_pow[i])%m;
	vector<int>ans;
	for(int i=0;i+S-1<T;i++)
	{
		ll cur_h=(h[i+S]+m-h[i])%m;
		if(cur_h==(h_s*p_pow[i])%m)
		ans.push_back(i);
	}
	return ans;
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--){
		string s,t;
		cin>>s>>t;
		vector<int> ans=Robin_karp(t,s);
		if(ans.size()==0)
		{
			cout<<"Not Found"<<endl;
			continue;
		}
		cout<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++)
		cout<<ans[i]+1<<" ";
		cout<<endl;
	}
}
