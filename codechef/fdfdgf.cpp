#include<bits/stdc++.h>
using namespace std;
int arr[50][50]={0};
bool issafe(int x,int y,int n,int m)
{
	for(int i=0;i<n;i++)
	{
		if(i==x) continue;
		if(arr[i][y]==1) return false;
	}
	for(int j=0;j<m;j++)
	{
		if(j==y)continue;
		if(arr[x][j]==1) return false;
	}
	return true;
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		cin>>arr[i][j];
		int p=0;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(arr[i][j]!=1&&issafe(i,j,n,m))
				{
					arr[i][j]=1;
				//	cout<<i+1<<" "<<j+1<<endl;
					p++;
				}
			}
		}
		//cout<<p<<endl;
		if(p%2==1) cout<<"Ashish"<<endl;
		else cout<<"Vivek"<<endl;
	}
}
