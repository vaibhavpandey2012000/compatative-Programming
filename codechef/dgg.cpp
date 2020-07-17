#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
	int q=1;
	cin>>q;
	double ans=-1;
	vector<pair<long,long> >v;
	while(q--)
	{
		long x,y;
		cin>>x>>y;
		for(int i=0;i<v.size();i++)
		{
			double dis=sqrt((v[i].first-x)*(v[i].first-x)+(v[i].second-y)*(v[i].second-y));
			if(dis>ans)
			ans=dis;
		}
		v.push_back({x,y});
	}
	cout<<setprecision(50)<<ans<<endl;
}
