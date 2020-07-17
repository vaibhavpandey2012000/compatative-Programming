#include<bits/stdc++.h>
using namespace std;
const int maxN=1000;
int arr[maxN];
struct Tree{
	int val,lazy;
};
Tree tree[4*maxN+4];
void build(int s,int e,int ind)
{
	if(s==e)
	{
		tree[ind].val=arr[s];
		return;
	}
	int m=(s+e)/2;
	build(s,m,2*ind);
	build(m+1,e,2*ind+1);
	tree[ind].val=min(tree[2*ind].val,tree[2*ind+1].val);
	return;
}
void lazyupdate(int qs,int qe,int inc,int s,int e,int ind)
{
	if(tree[ind].lazy!=0)
	{
		tree[ind].val+=tree[ind].lazy;
		if(s!=e)
		{
			tree[2*ind].lazy+=tree[ind].lazy;
			tree[2*ind+1].lazy+=tree[ind].lazy;
		}
		tree[ind].lazy=0;
	}
	
	if(e<qs || s>qe)
	return;
	if(s>=qs && e<=qe)
	{
		tree[ind].val+=inc;
		if(s!=e)
		{
			tree[2*ind].lazy+=inc;
			tree[2*ind+1].lazy+=inc;
		}
		return;
	}
	int m=(s+e)/2;
	lazyupdate(qs,qe,inc,s,m,2*ind);
	lazyupdate(qs,qe,inc,m+1,e,2*ind+1);
	tree[ind].val=min(tree[2*ind].val,tree[2*ind+1].val);
	return;
}
int lazyquary(int qs,int qe,int s,int e,int ind)
{
	if(tree[ind].lazy!=0)
	{
		tree[ind].val+=tree[ind].lazy;
		if(s!=e)
		{
			tree[2*ind].lazy+=tree[ind].lazy;
			tree[2*ind+1].lazy+=tree[ind].lazy;
		}
		tree[ind].lazy=0;
	}
	if(e<qs || s>qe)
	{
		return INT_MAX;
	}
	if(s>=qs && e<=qe){
        
        return tree[ind].val;
    }
	int m=(s+e)/2;
	int ll=lazyquary(qs,qe,s,m,2*ind);
	int rr=lazyquary(qs,qe,m+1,e,2*ind+1);
	return min(ll,rr);
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	build(0,n-1,1);
//	for(int i=1;i<=13;i++)
//	{
//		cout<<tree[i].val<<" ";
//	}
	lazyupdate(3,3,10,0,n-1,1);
	int q=6;
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		cout<<lazyquary(a,b,0,n-1,1)<<endl;
	}
}