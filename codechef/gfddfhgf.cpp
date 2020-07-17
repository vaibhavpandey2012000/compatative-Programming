#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		long n,k;
		cin>>n>>k;
		if(k>n)
		{
			cout<<"NO"<<endl;
			continue;
		}
		else if(n%k==0)
		{
			cout<<"YES"<<endl;
			for(int i=0;i<n/k;i++)
			{
				cout<<n/k<<" ";
			}
			cout<<endl;
		}
		else{
			vector<long>v;
			long rem=n%k;
			long d=n/k;
			for(int i=0;i<d;i++)
			v.push_back(d);
			if(d%2==1 && rem%2==1)
			{
				v[0]+=rem;
			}
			else if(d%2==1 && rem%2==0)
			{
				cout<<"NO"<<endl;
				continue;
			}
			else if(d%2==0 && rem%2==1)
			{
				cout<<"NO"<<endl;
				continue;
			}
			else if(d%2==0 && rem%2==0)
			{
				v[0]+=rem;
			}
			cout<<"YES"<<endl;
			for(int i=0;i<v.size();i++)
			cout<<v[i]<<" ";
			cout<<endl;
		}
	}
}
