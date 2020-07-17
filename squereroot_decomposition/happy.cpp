//happy segment hackerearth

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BLOCK 555
struct quary{
	int l,r,i;
};
quary Q[500001];
int arr[50001];
int fre[500001],ans[500001];

int num[500001];

bool comp(quary A,quary B)
{
	if(A.l/BLOCK!=B.l/BLOCK)
	{
		return A.l/BLOCK<=B.l/BLOCK;
	}
	return A.r<B.r;
}

map<int,int> mp;

void add(int ind)
{
	mp[arr[ind]]++;
}

void remove(int ind)
{
	mp[arr[ind]]--;
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	for(int i=1;i<=m;i++)
	cin>>num[i];
	
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>Q[i].l>>Q[i].r;
		Q[i].l--,Q[i].r--;
		Q[i].i=i;
	}
	
	sort(Q,Q+q,comp);
	int ML=0,MR=-1;
	
	for(int i=0;i<q;i++)
	{
		int flg=1;
		int L=Q[i].l;
		int R=Q[i].r;
		int idx=Q[i].i;
		
		//extend the Range
		while(MR<R) MR++ ,add(MR);
		while(ML>L) ML-- ,add(ML);
		
		//Redusing the Range
		while(MR>R) remove(MR) ,MR--;
		while(ML<L) remove(ML) ,ML++;
		
		for(auto e:mp)
		{
			if(num[e.first]!=e.second && e.second!=0)
			{
				flg=0;
				break;
			}
		}
		if(flg)
		ans[idx]=1;
		else
		ans[idx]=0;
	}
	
	for(int i=0;i<q;i++)
	{
		cout<<ans[i]<<endl;
	}
	
	return 0;
	
}