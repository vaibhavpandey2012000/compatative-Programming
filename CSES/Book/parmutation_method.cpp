#include<bits/stdc++.h>
using namespace std;
void parmu(vector<int> v,int n,int i)
{
	if(i==n-1)
	{
		//work on parmutation
		for(int i=0;i<n;i++)
		cout<<v[i]<<",";
		cout<<endl;
		return;
	}
	for(int j=i;j<n;j++)
	{
		swap(v[i],v[j]);
		parmu(v,n,i+1);
		swap(v[i],v[j]);
	}
}
int main()
{
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++)
	cin>>v[i];
	parmu(v,n,0);
}
