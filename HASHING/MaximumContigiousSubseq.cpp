#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	map<int,int>mp;
	int mn=INT_MAX;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		mp[temp]=1;
		mn=min(mn,temp);
	}
	int ans=0,cnt=0;
	mn--;
	for(auto e:mp)
	{
		if(e.first==mn+1)
		cnt++ , mn++;
		else
		ans=max(ans,cnt) ,cnt=1 , mn=e.first;
		
	}
	cout<<ans<<endl;
}