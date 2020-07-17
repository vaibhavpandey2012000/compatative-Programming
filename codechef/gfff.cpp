#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector<int> v(n),a(n);
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		for(int i=0;i<n-1;i++)
		{
			if(v[i]==v[i+1]-1)
			{
				v[i]=-1;
				v[i+1]=-1;
			}
		}
		int e=0,o=0;
		for(int i=0;i<n;i++)
		{
			if(v[i]==-1)
			continue;
			
			if(v[i]%2)
			o++;
			else
			e++;
		}
		if(o%2==0 && e%2==0)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
		
		
	}
}
