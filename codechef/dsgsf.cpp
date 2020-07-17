#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
	int tc=1;
	cin>>tc;
	while(tc--)
	{
		int n,k;
		cin>>n>>k;
		set<int> s;
		vector<int> v(n);
		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			v[i]=temp;
			s.insert(temp);
		}
		if(s.size()>k)
		{
			cout<<"-1"<<endl;
			continue;
		}
		vector<int> ans;
		for(int i=0;i<n;i++)
		{
			for(int j:s)
				ans.push_back(j);
			for(int j=s.size();j<k;j++)
				ans.push_back(v[0]);
		}
		cout<<ans.size()<<endl;
		for(int ele:ans)
		{
			cout<<ele<<" ";
		}
		cout<<endl;
	}
}
