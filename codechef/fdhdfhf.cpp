#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,x;
		cin>>n>>x;
		vector<int>v(n);
		for(int i=0;i<n;i++) cin>>v[i];
		sort(v.begin(),v.end());
		
		//work on chaning
		int head=-1,val;
		map<int,vector<int> >mp;
		for(int i=0;i<n;i++)
		{
			if(head==-1||2*val<v[i])
			{
				head=v[i];
				val=v[i];
				mp[head].push_back(v[i]);
			}
			else{
				mp[head].push_back(v[i]);
				val=v[i];
			}
		}
/*
		//only for chacking
		for(auto e:mp)
		{
			cout<<e.first<<"-->";
			for(auto vv:e.second)
			{
				cout<<vv<<",";
			}
			cout<<endl;
		}
*/
		int day=1;
		for(auto e:mp)
		{
			if(e.first>x){
				while(e.first>x)
				{
					x=2*x;
					day++;
				}	
			}
			else{
				int dd=e.second.size();
				day+=dd;
				x=2*e.second[dd-1];
			}
		}
		cout<<day<<endl;
		
	}
}
