#include <bits/stdc++.h>
#define ll long 
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++)
    {
    	int n,f=0;
    	cin>>n;
    	string ss,tt;
    	cin>>ss>>tt;
    	map<char,vector<int>> mp1,mp2,a11;
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
	ll fid=0;
	for(int i=24;i>=0;i--)
	{
		if(mp2['a'+i].size()!=0 )
		{
			if(mp1['a'+i].size()!=0){
				for(auto j:mp2['a'+i])
				a11['a'+i].push_back(j);
				a11['a'+i].push_back(mp1['a'+i][0]);
				fid++;
			}
			
		}
		else if(mp2['a'+i].size()!=0 )
		{
			if(mp1['a'+i].size()==0)
			{
				f=1;
				break;
			}
			
		}
	}
	if(f) cout<<-1<<endl;
	else
	{
		cout<<fid<<endl;
		for(int i=25;i>=0;i--)
		{
			if(a11['a'+i].size()!=0)
			{
				cout<<a11['a'+i].size()<<" ";
				for(auto j:a11['a'+i])
				cout<<j<<" ";
				cout<<"\n";
			}
		}
	}
}
}
