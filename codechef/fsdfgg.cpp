#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{int tc;
	cin>>tc;
	while(tc--){	
		int n,m;
		cin>>n>>m;
		int arr[n][m];
		vector<int> v(60,0),v1(60,0);
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		cin>>arr[i][j];
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]==0)
			v[i+j]++;
			else
			v1[i+j]++;
		}
		int tt=(m+n-2)/2;
		int tot=0;
		for(int i=0;i<=tt;i++)
		{
			if(i==tt && (n+m)%2==0)
			continue;
			else
			{
				int n1=v[i]+v[n+m-2-i];
				int n2=v1[i]+v1[n+m-2-i];
				tot+=min(n1,n2);
			}
		}
		cout<<tot<<endl;	
	}	
}
