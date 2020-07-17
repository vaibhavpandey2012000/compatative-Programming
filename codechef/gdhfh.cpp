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
		int a[n],b[n],s1=0,s2=0,ans=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			s1+=a[i];
			a[i]=s1;
		}
		
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
			s1+=b[i];
			b[i]=s1;
		}
		for(int i=0;i<n;i++)
		{
			if(a[i]==b[i] && a[i-1]!=b[i-1])
			ans++;
			if(a[i]==b[i] && a[i-1]==b[i-1])
			{
				ans+=(a[i]-a[i-1]);
			}
		}
		cout<<ans<<endl;
	}
}
