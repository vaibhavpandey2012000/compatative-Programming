// n either n/2,n/3,n/6
#include<bits/stdc++.h>
using namespace std;
const int maxN=100005;
int grandy[maxN];

int calculateMex(unordered_set<int> s)
{
	int mex=0;
	while(s.find(mex)!=s.end())
		mex++;
	return mex;
}

int grandyNumber(int n)
{
	if(n==0)
		return grandy[n];
	if(grandy[n]!=0)
		return grandy[n];
	unordered_set<int> Set;
	
	Set.insert(grandyNumber(n/2));
	Set.insert(grandyNumber(n/3));
	Set.insert(grandyNumber(n/6));
	
	grandy[n]=calculateMex(Set);
	return grandy[n];
}

int main()
{
	int n;
	cin>>n;
	int gg=grandyNumber(n);
	for(int i=0;i<=n;i++)
		cout<<grandy[i]<<" ";
	cout<<endl;
	cout<<gg<<endl;
}