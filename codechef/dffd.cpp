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
	return 0;
	if(grandy[n]!=-1)
	return grandy[n];
	
	unordered_set<int>s;
	for(int i=0;i<n;i++)
	{
		s.insert(grandyNumber(i));
	}
	return grandy[n]=calculateMex(s);
}
int main()
{
	int n;
	cin>>n;
	memset(grandy,-1,sizeof(grandy));
	grandy[0]=0;
	for(int i=0;i<=10;i++)
	cout<<grandy[i]<<" ";
	cout<<endl;
	int gg=grandyNumber(n);
	cout<<gg<<endl;
}
