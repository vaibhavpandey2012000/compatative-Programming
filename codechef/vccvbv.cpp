#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,p;
		cin>>n>>p;
		string s;
		cin>>s;
		map<char,int>mp;
		for(int i=0;i<n;i++)
		{
			mp[s[i]]++;
		}
		int mn=10000,cnt=0;
		for(auto e:mp)
		{
			cnt++;
			mn=min(mn,e.second);
		}
		int ans;
		for (int i=1;i<=n;i++) 
        if (p%i==0) 
        {
        	 long p=i*mn;
        	 if(p<=n)
        	 ans=p;
		}
           
		cout<<ans<<endl; 
		
	}
}
