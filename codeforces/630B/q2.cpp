#include<bits/stdc++.h>
using namespace std;
int prime[]={2,3,5,7,11,13,17,19,23,29,31};
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int b[n]={0};
		int k=1;
		for(int i=0;i<11;i++)
		{
			int flag=0;
			for(int j=0;j<n;j++)
			{
				if(a[j]%prime[i]==0 && b[j]==0)
				{
					b[j]=k;
					flag=1;
				}
			}
			if(flag) k++;
		}
		cout<<k-1<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<b[i]<<" ";
		}
		cout<<endl;
	}
}