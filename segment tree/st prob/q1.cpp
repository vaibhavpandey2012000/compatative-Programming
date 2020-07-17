#include<bits/stdc++.h>
#define ll long 
using namespace std;
const int maxN=100005;
ll arr[maxN];
ll tree[4*maxN];

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

ll quary(int qs,int qe,int ss,int se,int ind)
{
	if(se<qs || ss>qe)
	return INT_MAX;
	if(qs<=ss && qe>=se)
	return tree[ind];
	int m=(ss+se)/2;
	ll lll=quary(qs,qe,ss,m,2*ind);
	ll rr=quary(qs,qe,m+1,se,2*ind+1);
	return min(lll,rr);
}

void update(int i,int inc,int ss,int se,int ind)
{
	if(i<ss || i>se)
	return;
	if(ss==se)
	{
		tree[ind]=inc;
		return;
	}
	int m=(ss+se)/2;
	update(i,inc,ss,m,2*ind);
	update(i,inc,m+1,se,2*ind+1);
	tree[ind]=min(tree[2*ind],tree[2*ind+1]);
}
int main()
{
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	build(0,n-1,1);
	while(q--)
	{
		int t,a,b;
		cin>>t>>a>>b;
		if(t==1)
		{
			--a,--b;
			cout<<quary(a,b,0,n-1,1)<<endl;
		}
		else
		{
			--a;
			update(a,b,0,n-1,1);
		}
	}
}
