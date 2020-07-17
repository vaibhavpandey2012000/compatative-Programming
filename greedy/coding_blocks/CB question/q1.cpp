#include<bits/stdc++.h>
using namespace std;
struct job{
	int s,e;
};
bool comp(job a,job b)
{
	return a.e<b.e;
}
vector<job> v;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		sort(v.begin(),v.end(),comp);
		int cnt=1;
		int ed=v[0].e;
		for(auto ele:v)
		{
			if(ele.s>=ed)
			{
				cnt++;
				ed=ele.e;
			}
		}
		cout<<cnt<<endl;
		v.clear();
		
	}
}