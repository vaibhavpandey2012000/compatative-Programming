#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n1,m1;
	cin>>n1>>m1;
	int n2,m2;
	cin>>n2>>m2;
	if(m1!=n2){
		cout<<"multiplication not possible."<<endl;
		return 0;
	}
	int arr1[n1][m1],arr2[n2][m2];
	for(int i=0;i<n1;i++)
	for(int j=0;j<m1;j++)
	cin>>arr1[i][j];
	
	for(int i=0;i<n1;i++)
	for(int j=0;j<m1;j++)
	cin>>arr2[i][j];
	
	int mul[n1][m2]={0};
	for(int i=0;i<n1;i++)
	for(int j=0;j<m2;j++)
	{
		mul[i][j]=0;
		for(int k=0;k<m1;k++)
		mul[i][j]+=arr1[i][k]*arr2[k][j];
	}
	
	
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<m2;j++)
		cout<<setw(4)<<mul[i][j];
		cout<<endl;
	}
	
	
} 