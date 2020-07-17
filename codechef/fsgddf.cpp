#include<bits/stdc++.h>
using namespace std;
bool arr[100][100];
bool subset(vector<int>&v,int s)
{
	for(int i=0;i<v.size();i++)
	arr[i][0]=1;
	for(int j=0;j<=s;j++)
	if(j==v[0]) arr[0][j]=1;
	
	for(int i=0;i<v.size();i++)
	{
		for(int j=1;j<=s;j++)
		{
			if(arr[i-1][j])
			arr[i][j]=true;
			else if(j>=v[i])
			arr[i][j]=arr[i-1][j-v[i]];
		}
	}
	return arr[v.size()-1][s];
}
int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	cin>>v[i];
	int sum=4;
	bool ans=subset(v,sum);
	cout<<ans<<endl;
}
