#include<bits/stdc++.h>
using namespace std;
struct Act{
	int s,e;
};
bool comp(Act a,Act b)
{
	return a.e<=b.e;
}
int activity(Act *act,int n)
{
	int ans=1;
	int ed=act[0].e;
	cout<<act[0].s<<"--"<<act[0].e<<endl;
	for(int i=1;i<n;i++)
	{
		if(ed<=act[i].s)
		{
			ans++;
			ed=act[i].e;
			cout<<act[i].s<<"--"<<act[i].e<<endl;
		}
	}
	return ans;
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
	
		cin>>n;
	
		Act act[n];
	
		for(int i=0;i<n;i++)
		{
			cin>>act[i].s>>act[i].e;
		}
	
		sort(act,act+n,comp);
		
		int ans=activity(act,n);
	
		cout<<endl<<ans<<endl;
	}
}