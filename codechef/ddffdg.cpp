#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,e=2,o=1;
		cin>>n;
		int arr[n][n];
		
//		for(int i=0;i<n;i++)
//			for(int j=0;j<n;j++)
//				arr[i][j]=0;
		
		for(int i=0;i<n;i++)
		{
			if(i%2==0)
			{
				for(int d=0;d<n-i;d++)
				{
					arr[i+d][d]=o;
					o+=2;
				}
			}
			else
			{
				for(int d=0;d<n-i;d++)
				{
					arr[i+d][d]=e;
					e+=2;
				}
			}
		}
		
		for(int i=1;i<n;i++)
		{
			if(i%2==0)
			{
				for(int d=0;d<n-i;d++)
				{
					arr[d][i+d]=o;
					o+=2;
				}
			}
			else
			{
				for(int d=0;d<n-i;d++)
				{
					arr[d][i+d]=e;
					e+=2;
				}
			}
		}
		
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			cout<<arr[i][j]<<" ";
			cout<<endl;
		}
	}
}
