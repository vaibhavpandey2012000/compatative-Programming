#include<bits/stdc++.h>
using namespace std;
const int maxN=1000;
int arr[maxN],tree[4*maxN+4];
void build(int s,int e,int ind)
{
	if(s==e)
	{
		tree[ind]=arr[s];
		return;
	}
	int m=(s+e)/2;
	build(s,m,2*ind);
	build(m+1,e,2*ind+1);
	tree[ind]=min(tree[2*ind],tree[2*ind+1]);
	return;
}
int quary(int qs,int qe,int ss,int se,int ind)
{
	if(se<qs || ss>qe)
	return INT_MAX;
	if(qs<=ss && qe>=se)
	return tree[ind];
	int m=(ss+se)/2;
	int left=quary(qs,qe,ss,m,2*ind);
	int right=quary(qs,qe,m+1,se,2*ind+1);
	return min(left,right);
}

void update(int s,int e,int i,int inc,int ind)
{
	if(i<s || i>e)
	return;
	if(s==e)
	{
		tree[ind]+=inc;
		return;	
	}
	int m=(s+e)/2;
	update(s,m,i,inc,2*ind);
	update(m+1,e,i,inc,2*ind+1);
	tree[ind]=min(tree[2*ind],tree[2*ind+1]);
}
void updaterange(int s,int e,int qs,int qe,int inc,int ind)
{
	if(e<qs || s>qe)
	return;
	if(s==e)
	{
		tree[ind]+=inc;
		return;
	}
	int m=(s+e)/2;
	updaterange(s,m,qs,qe,inc,2*ind);
	updaterange(m+1,e,qs,qe,inc,2*ind+1);
	tree[ind]=min(tree[2*ind],tree[2*ind+1]);
	return;
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
//	cout<<tree[i]<<" ";
	int l,r;
//	cin>>l>>r;
	updaterange(0,n-1,2,3,10,1);
	int q=6;
	while(q--)
	{
		cin>>l>>r;
		int qq=quary(l,r,0,n-1,1);
		cout<<qq<<endl;
	}
}