#include<bits/stdc++.h>
using namespace std;
/*
//enumurate num for position
void dfs(int *arr,int n,vector<vector<int> >&res,vector<int>&path,vector<bool>&used)
{
	if(path.size()==n)
	{
		res.push_back(path);
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(!used[i])
		{
			used[i]=true;
			path.push_back(arr[i]);
			dfs(arr,n,res,path,used);
			path.pop_back();
			used[i]=false;
		}
	}
}
void parmute(int *arr,int n)
{
	vector<vector<int> >res;
	vector<int>path;
	vector<bool>used(n,false);
	dfs(arr,n,res,path,used);//true if num[i] is used
	for(auto e:res)
	{
		for(auto p:e)
		cout<<p<<" ";
		cout<<endl;
	}
	
}*/


//enumrate by position of num
void dfs(int curr_pos,int *arr,int n,vector<vector<int> >&res,vector<int>&path,vector<bool>&used)
{
	if(curr_pos==n)
	{
		res.push_back(path);
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(!used[i])
		{
			used[i]=true;
			path[curr_pos]=arr[i];
			dfs(curr_pos+1,arr,n,res,path,used);
			//no need to restore the path becouse it is overwriten in next itration
			used[i]=false;
		}
	}
}

void parmute(int *arr,int n)
{
	vector<vector<int> >res;
	vector<int>path(n);
	vector<bool>used(n,false);//true if path[i] is used
	dfs(0,arr,n,res,path,used);
	for(auto e:res)
	{
		for(auto p:e)
		cout<<p<<" ";
		cout<<endl;
	}
	
}

int main()
{
	int arr[]={1,2,3};
	parmute(arr,3);
}