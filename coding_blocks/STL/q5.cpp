#include<bits/stdc++.h>
using namespace std;
int has[100000];
bool camp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,k;
	cin>>n>>k;
	vector<int>v(n),v2(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		v2[i]=v[i];
		has[v2[i]]=i;
	}
	sort(v2.begin(),v2.end(),camp);
	for(int i=0;i<n & k!=0;i++)
	{
		if(v2[i]==v[i])	continue;
		else
		{
			k--;
			int pos1=has[v2[i]];
			int pos2=i;
			swap(v[i],v[pos1]);
			swap(has[v[i]],has[v[pos1]]);
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}	
}