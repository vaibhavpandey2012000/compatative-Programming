#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll tc;
    cin>>tc;
    for(int ii=0;ii<tc;ii++)
    {
    	ll n,f=0;
    	cin>>n;
    	string ss,tt;
    	cin>>ss>>tt;
    	map<char,vector<ll>> mp1,mp2,a;
    	for(int i=0;i<n;i++)
    	{
    	if(ss[i]<tt[i])
   		 {
    		f=1;
   			break;
		 }
		else if(ss[i]>tt[i])
		{
		mp1[ss[i]].push_back(i);
		mp2[tt[i]].push_back(i);
		}
		else {
			mp1[ss[i]].push_back(i);
		}
	}
	ll co=0;
	for(int i=24;i>=0;i--)
	{
		if(mp2['a'+i].size()!=0 && mp1['a'+i].size()!=0)
		{
			for(auto j:mp2['a'+i])
			a['a'+i].push_back(j);
			a['a'+i].push_back(mp1['a'+i][0]);
			co++;
		}
		else if(mp2['a'+i].size()!=0 && mp1['a'+i].size()==0)
		{
			f=1;
			break;
		}
	}
	if(f) cout<<-1<<endl;
	else
	{
		cout<<co<<endl;
		for(int i=25;i>=0;i--)
		{
		if(a['a'+i].size()!=0)
		{
			cout<<a['a'+i].size()<<" ";
			for(auto j:a['a'+i])
				cout<<j<<" ";
				cout<<endl;
		}
	}
	}
}
}

