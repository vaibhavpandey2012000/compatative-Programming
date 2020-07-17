#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxN=100005;
ll arr[maxN];
struct Tree{
	ll pre,suf,ts,mx;
};
Tree tree[4*maxN];
void build(int s,int e,int ind)
{
	if(s==e)
	{
		tree[ind].pre=arr[s];
		tree[ind].suf=arr[s];
		tree[ind].ts=arr[s];
		tree[ind].mx=arr[s];
		return;
	}
	int m=(s+e)/2;
	build(s,m,2*ind);
	build(m+1,e,2*ind+1);
	tree[ind].pre=max(tree[2*ind].ts+tree[2*ind+1].pre,tree[2*ind].pre);
	tree[ind].suf=max(tree[2*ind+1].ts+tree[2*ind].suf,tree[2*ind+1].suf);
	tree[ind].ts=(tree[2*ind].ts+tree[2*ind+1].ts);
	tree[ind].mx=max(max(tree[2*ind].mx,tree[2*ind+1].mx),(tree[2*ind].suf+tree[2*ind+1].pre));
	return;
}
Tree quary(int qs,int qe,int ss,int se,int ind)
{
	Tree temp;
	temp.pre=INT_MIN,temp.suf=INT_MIN,temp.mx=INT_MIN,temp.ts=INT_MIN;
	if(se<qs || ss>qe)
	return temp;
	if(ss>=qs && se<=qe)
	return tree[ind];
	
	int m=(ss+se)/2;
	Tree lll=quary(qs,qe,ss,m,2*ind);
	Tree rrr=quary(qs,qe,m+1,se,2*ind+1);
	Tree qwe;
	qwe.pre=max(lll.ts+rrr.pre,lll.pre);
	qwe.suf=max(lll.suf+rrr.ts,rrr.suf);
	qwe.ts=(lll.ts+rrr.ts);
	qwe.mx=max(max(lll.mx,rrr.mx),(lll.suf+rrr.pre));
	return qwe;
	
	
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
	int q;
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		--l;
		--r;
		cout<<quary(l,r,0,n-1,1).mx<<endl;
	}
	
}