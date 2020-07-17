#include<bits/stdc++.h>
using namespace std;
vector<int> calc_subset(int *arr,int i,int n)
{
	vector<int>v;
	int p=0;
	while(i)
	{
		if(i&1)
		v.push_back(arr[p]);
		i=(i>>1);
		p++;
	}
	return v;
}
void subset(int *arr,int n)
{
	for(int i=0;i<(1<<n);i++)
	{
		vector<int> v=calc_subset(arr,i,n);
		for(int i=0;i<v.size();i++)
		cout<<v[i]<<",";
		cout<<endl;
	}
}
int main()
{
	int arr[]={1,2,3};
	int n=3;
	subset(arr,n);
}