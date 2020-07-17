#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,sum=0;
		cin>>n;
		vector<int> v(n,0);
		for(int i=0;i<n;i++)
			cin>>v[i] , sum+=v[i];
		if(sum%n!=0)
		{
			cout<<"-1"<<endl;
			continue;
		}
		int lode=sum/n;
	//	cout<<lode<<endl;
		int diff=0;
		int mx=0;
		for(int i=0;i<n-1;i++)
		{
			diff+=abs(v[i]-lode);
			mx=max(mx,diff);
		}
		cout<<diff<<endl;
	}
}