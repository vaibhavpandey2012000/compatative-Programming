//find the unique number in range [l,r] for q quaries...


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BLOCK 555
struct quary{
	int l,r,i;
};
quary Q[200001];
int arr[30001];
int fre[200001],ans[200001];

int cnt=0;

bool comp(quary A,quary B)
{
	if(A.l/BLOCK!=B.l/BLOCK)
	{
		return A.l/BLOCK<=B.l/BLOCK;
	}
	return A.r<B.r;
}

void add(int ind)
{
	fre[arr[ind]]++;
	if(fre[arr[ind]]==1)
	cnt++;
}

void remove(int ind)
{
	fre[arr[ind]]--;
	if(fre[arr[ind]]==0)
	cnt--;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
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
		int L=Q[i].l;
		int R=Q[i].r;
		int idx=Q[i].i;
		
		//extend the Range
		while(MR<R) MR++ ,add(MR);
		while(ML>L) ML-- ,add(ML);
		
		//Redusing the Range
		while(MR>R) remove(MR) ,MR--;
		while(ML<L) remove(ML) ,ML++;
		
		ans[idx]=cnt;
	}
	
	for(int i=0;i<q;i++)
	{
		cout<<ans[i]<<endl;
	}
	
	return 0;
	
}