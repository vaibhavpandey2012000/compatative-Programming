//powerful array dev 1 codeforcese

#include<bits/stdc++.h>
using namespace std; 
const int BLOCK=555;
int arr[200001],freq[200001],ans[200001];
struct Q{
	int l,r,i;
};
Q quary[200001];
bool comp(Q A,Q B)
{
	if(A.l/BLOCK!=B.l/BLOCK)
	return A.l/BLOCK<=B.l/BLOCK;
	
	return A.r<B.r;
}
long long power=0;
void add(int id)
{
	int ele=arr[id];
	int pre=freq[ele];
	int currf= ++freq[ele];
	power-=ele*pre*pre;
	power+=ele*currf*currf;
}
void remove(int id)
{
	int ele=arr[id];
	int pre=freq[ele];
	int currf=  --freq[ele];
	power-=pre*pre*ele;
	power+=currf*currf*ele;
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
		cin>>quary[i].l>>quary[i].r;
		quary[i].l--,quary[i].r--;
		quary[i].i=i;
	}
	sort(quary,quary+q,comp);
	
	int GL=0,GR=-1;
	for(int i=0;i<q;i++)
	{
		int L=quary[i].l ,R=quary[i].r;
		
		while(L<GL) GL-- ,add(GL);
		while(R>GR) GR++ ,add(GR);
		
		while(L>GL) remove(GL) ,GL++;
		while(R<GR) remove(GR) ,GR--;
		
		ans[quary[i].i]=power;
	}
	
	for(int i=0;i<q;i++)
	{
		cout<<ans[i]<<endl;
	}
}