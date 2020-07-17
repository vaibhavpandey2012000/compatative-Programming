#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	for(int pp=0;pp<tc;pp++)
	{
		int arr[4][4]={{0,0,1,1},{1,0,0,1},{0,0,1,0},{1,0,0,0}};
		int arr1[4][4]={{0,0,1,0},{1,0,0,1},{0,0,0,1},{1,0,1,0}};
		int n,p;
		cin>>n>>p;
		int a=0,b=0,aa=n,bb=n;
		for(int i=0;i<n;i++)
		{
			int temp;
			cout<<1<<" "<<a<<" "<<b<<" "<<aa<<" "<<bb<<endl;
			cin>>temp;
			if(i%2==0)
			a++,b++;
			else
			aa--,bb--;
		}
		if(pp==0)
		{
			cout<<"2a"<<endl;
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<4;j++)
				{
					cout<<arr[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		else if(pp==1)
		{
			cout<<"2b"<<endl;
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<4;j++)
				{
					cout<<arr1[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		else
		{
			cout<<"2c"<<endl;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					cout<<rand()%2<<" ";
				}
				cout<<endl;
			}
		}
		int rtk;
		cin>>rtk;
	}
}
