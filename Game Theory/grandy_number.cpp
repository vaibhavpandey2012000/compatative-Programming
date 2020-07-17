#include<bits/stdc++.h>
using namespace std;
const int maxN=100005;
int grandy[maxN];
int computemex(unordered_set<int>s)
{
	int mex=0;
	while(s.find(mex)!=s.end())
	mex++;
	return mex;
}
int computegrandy(int n)
{
	if(n==0) return 0;
	if(grandy[n]!= -1)
	{
		return grandy[n];
	}
	unordered_set<int>s;
	for(int i=1;i<=n;i++)
	{
		s.insert(computegrandy(n-i));
	}
	grandy[n]=computemex(s);
	return grandy[n];
}
int main()
{
	memset(grandy,-1,sizeof(grandy));
	int n;
	cin>>n;
	cout<<computegrandy(n)<<endl;
}