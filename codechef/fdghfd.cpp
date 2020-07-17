#include<bits/stdc++.h>
using namespace std;

int fxn(int a,int n)
{
	return log2(a);
}

int pow(int a,int b)
{
	if(b==0)
	return 1;
	int ans=pow(a,b/2);
	ans=ans*ans;
	if(b&1) return ans*a;
	else return ans;
	
}
void solve(map<int,list<int> >&mp,int x)
{
	int dd=0;
	while(!mp.empty())
	{
		auto c=mp.lower_bound(x);
		
		if(c==mp.end())
		c--;
		
		int nm=c->first;
		
		if(c!=mp.begin() && x<nm)
		{
			c--;
			
			int ll=0;
			
			for(auto ee:c->second)
			{
				ll=ee;
			}
			
			if(ll*2<=x)
			c++;
		}
		
		nm=c->first;
		++dd;
		
		int sss=pow(x,dd);
		
		while(x<nm)
		{
			++dd;
			x=x*2;
		}
		
		int last=0;
		int time=0;
		
		for(auto ss:c->second)
		{
			last=ss;
			time++;
		}
		dd+=(time-1);
		x=last*2;
		
		int asd= fxn(x,dd);
		mp.erase(c);
	}
	cout<<dd<<endl;
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,x;
		cin>>n>>x;
		vector<int>v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		sort(v.begin(),v.end());

		int head=-1,val;
		map<int,list<int> >mp;
		for(int i=0;i<n;i++)
		{
			if(head==-1||(val<<1)<v[i])
			head=v[i];
			val=v[i];
			mp[head].push_back(v[i]);
		}

		solve(mp,x);
	}
}
