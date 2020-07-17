#include<bits/stdc++.h>
using namespace std;

//enumrate by position of num
void dfs(int curr_pos,int strt_pos,int *arr,int n,vector<vector<int> >&res,vector<int>&path,vector<bool>&used)
{
	if(curr_pos==n)
	{
		res.push_back(path);
		return;
	}
	for(int i=strt_pos;i<n;i++)
	{
		if(!used[i])
		{
			used[i]=true;
			path[i]=arr[curr_pos];
			if(curr_pos+1<n && arr[curr_pos+1]==arr[curr_pos])
			dfs(curr_pos+1,i+1,arr,n,res,path,used);
			else
			dfs(curr_pos+1,0,arr,n,res,path,used);
			//no need to restore the path becouse it is overwriten in next itration
			used[i]=false;
		}
	}
}

void parmute(int *arr,int n)
{
	sort(arr,arr+n);
	vector<vector<int> >res;
	vector<int>path(n);
	vector<bool>used(n,false);//true if path[i] is used
	dfs(0,0,arr,n,res,path,used);
	for(auto e:res)
	{
		for(auto p:e)
		cout<<p<<" ";
		cout<<endl;
	}
	
}

int main()
{
	int arr[]={1,1,1,3};
	parmute(arr,4);
}
