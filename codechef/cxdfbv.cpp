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
	for(int i=1;i<=n;i++)
	{
		grandy[n-i]=grandyNumber(n-i);
		Set.insert(grandy[n-i]);
	}
	return calculateMex(Set);
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<10;i++)
	cout<<grandy[i]<<" ";
	cout<<endl;
	int gg=grandyNumber(n);
	cout<<gg<<endl;
}
