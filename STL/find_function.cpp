#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr[]={2,3,6,9,11,15};
	int n=6;
	int ff;
	cin>>ff;
	auto e=find(arr,arr+n,ff)-arr;
	if(e==n)
		cout<<"not found"<<endl;
	else
		cout<<"element at:"<<e<<endl;
}