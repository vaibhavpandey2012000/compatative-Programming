#include<bits/stdc++.h>
using namespace std;
void helper(int *arr,vector<int>v,int i,int n)
{
	if(i==n)
	{
		for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
		cout<<endl;
		return ;
	}
	helper(arr,v,i+1,n);
	v.push_back(arr[i]);
	helper(arr,v,i+1,n);
}
void subset(int *arr,int n)
{
	vector<int> v;
	helper(arr,v,0,n);
}
int main()
{
	int arr[]={1,2,3};
	int n=3;
	subset(arr,n);
}
