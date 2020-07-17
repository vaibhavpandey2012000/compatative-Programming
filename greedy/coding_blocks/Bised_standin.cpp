#include<bits/stdc++.h>
using namespace std;
int renk[100];
int main()
{
	int tc;
	cin>>tc;
	int rank[1000]={0};
	while(tc--)
	{
		memset(rank,0,sizeof(rank));
		string s;
		int renk;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>s>>renk , rank[renk]++;
		
		int pos=1,ans=0;
		for(int i=1;i<=n;i++)
		{
			while(rank[i])
			{
				ans+=abs(pos-i);
				rank[i]--;
				pos++;
			}
		}
		cout<<ans<<endl;
	}
}