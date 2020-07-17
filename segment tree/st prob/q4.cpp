#include<bits/stdc++.h>
using namespace std;
const int maxN=100005;
struct node{
	int mat[2][2];
};
node arr[maxN];
node tree[4*maxN];
void build(int s,int e,int ind,int r)
{
	if(s==e)
	{
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				tree[ind].mat[i][j]=arr[s].mat[i][j]%r;
		return;
	}
	int m=(s+e)/2;
	build(s,m,2*ind,r);
	build(m+1,e,2*ind+1,r);
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			tree[ind].mat[i][j]=0;
			for(int k=0;k<2;k++)
			{
				tree[ind].mat[i][j]+=tree[2*ind].mat[i][k]*tree[2*ind+1].mat[k][j];
			}
			tree[ind].mat[i][j]%=r;
		}
	}
	return; 
}
node quary(int qs,int qe,int ss,int se,int ind,int r)
{
	node t1;
	t1.mat[0][0]=1;
	t1.mat[0][1]=0;
	t1.mat[1][0]=0;
	t1.mat[1][1]=1;
	
	if(se<qs || ss>qe)
	return t1;
	if(qs<=ss && qe>=se)
	return tree[ind];
	int m=(ss+se)/2;
	node ll=quary(qs,qe,ss,m,2*ind,r);
	node rr=quary(qs,qe,m+1,se,2*ind+1,r);
	node temp;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			temp.mat[i][j]=0;
			for(int k=0;k<2;k++)
			temp.mat[i][j]=(temp.mat[i][j]+ll.mat[i][k]*rr.mat[k][j]);
			temp.mat[i][j]%=r;
		}
	}
	return temp;
}
int main()
{
	int r,n,q;
	cin>>r>>n>>q;
	for(int i=0;i<n;i++)
	{
		for(int r=0;r<2;r++)
		for(int c=0;c<2;c++)
		cin>>arr[i].mat[r][c];
	}
	build(0,n-1,1,r);
//	cout<<"-------"<<endl;
//	for(int i=1;i<=7;i++)
//	{
//		for(int r=0;r<2;r++)
//		{
//			for(int c=0;c<2;c++)
//			cout<<tree[i].mat[r][c]<<" ";
//			cout<<endl;
//		}
//		cout<<endl;
//	}
//	cout<<"---------";
	while(q--)
	{
		int ll,rr;
		cin>>ll>>rr;
		--ll;
		--rr;
		node temp=quary(ll,rr,0,n-1,1,r);
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			cout<<temp.mat[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
	}
}