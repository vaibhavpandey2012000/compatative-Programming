#include<bits/stdc++.h>
using namespace std;
const int maxN=100005;
long arr[maxN];
vector<long> tree[4*maxN];

vector<long> marge(vector<long>a,vector<long>b)
{
	vector<long>temp;
	int i=0,j=0;
	while(i<a.size() && j<b.size())
	{
		if(a[i]>b[j]) 
		{
			temp.push_back(b[j]);
			j++;
		}
		else
		{
			temp.push_back(a[i]);
			i++;
		}
		//cout<<"pp"<<endl;
	}
	while(i<a.size())
	{
		temp.push_back(a[i]);
		i++;
	}
	while(j<b.size())
	{
		temp.push_back(b[j]);
		j++;
	}
	return temp;
}
void build(int s,int e,int ind)
{
	if(s==e)
	{
		tree[ind].push_back(arr[s]);
		return;
	}
	int mid=(s+e)/2;
	build(s,mid,2*ind);
	build(mid+1,e,2*ind+1);
	tree[ind]=marge(tree[2*ind],tree[2*ind+1]);
	return;
}
int quary(int qs,int qe,int k,int ss,int se,int ind)
{
	if(se<qs || ss>qe)
	return 0;
	if(ss>=qs && se<=qe)
	{
		auto it=lower_bound(tree[ind].begin(),tree[ind].end(),k);
		int p=it-tree[ind].begin();
		return tree[ind].size()-p;
	}
	int m=(ss+se)/2;
	int ll=quary(qs,qe,k,ss,m,2*ind);
	int rr=quary(qs,qe,k,m+1,se,2*ind+1);
	return (ll+rr);
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
//	for(int i=1;i<10;i++)   //eg. 4 ->4 3 2 1
//	{
//		for(int e:tree[i])
//		cout<<e<<",";
//		cout<<endl;
//	}
	int q;
	cin>>q;
	while(q--)
	{
		int l,r,k;
		cin>>l>>r>>k;
		cout<<quary(l,r,k,0,n-1,1)<<endl;
	}
}