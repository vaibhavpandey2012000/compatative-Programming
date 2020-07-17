#include<bits/stdc++.h>
using namespace std;
int quary(int *arr,int *blocks,int n,int rn,int l,int r)
{
	int ans=0;
	while(l<r && l!=0 && l%rn!=0)
	{
		ans+=arr[l];
		l++;
	}
	while(l+rn<=r)
	{
		int ind=l/rn;
		ans+=blocks[ind];
		l+=rn;
	}
	while(l<=r)
	{
		ans+=arr[l];
		l++;
	}
	return ans;
}
void update(int *arr,int *blocks,int i,int val,int rn)
{
	int ind=i/rn;
	blocks[ind]+=(val-arr[i]);
	arr[i]=val;
}
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	int n=10;
	int rn=sqrt(n);
	//build blocks
	int *blocks=new int[rn+1]{0};
	int ind=-1;
	for(int i=0;i<n;i++)
	{
		if(i%rn==0)
		{
			ind++;
		}
		blocks[ind]+=arr[i];
	}
	//quary part 
	int l,r;
	cin>>l>>r;
	int ans=quary(arr,blocks,n,rn,l,r);
	cout<<ans<<endl;
	//update
	int i,val;
	cin>>i>>val;
	update(arr,blocks,i,val,rn);	
}