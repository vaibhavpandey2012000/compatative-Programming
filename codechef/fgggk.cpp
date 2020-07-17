#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k;
		cin>>n>>k;
		int sm=0;
		vector<int>v(n);
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			sm+=v[i];
		}
		if(sm>0)
		{
			sm=sm*k;
			for(int i=0;i<n;i++)
			{
				if(v[i]<=0)
				sm+=(-v[i]);
				else
				break;
			}
			for(int i=n-1;i>=0;i--)
			{
				if(v[i]<=0)
				sm+=(-v[i]);
				else
				break;
			}
			cout<<sm<<endl;
		}
		
	}
}
