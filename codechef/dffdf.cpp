#include<bits/stdc++.h>
using namespace std;
const int maxN=10005;
int grandy[maxN];
int cmex(unordered_set<int>s)
{
	int mex=0;
	while(s.find(mex)!=s.end())
	mex++;
	return mex;
}
int calclutegrandy(int n)
{
	if(n==0)
	return 0;
	
	if(grandy[n]!=-1)
	return grandy[n];
	
	unordered_set<int>s;
	
	s.insert(calclutegrandy(n/2));
	s.insert(calclutegrandy(n/3));
	s.insert(calclutegrandy(n/6));
	
	grandy[n]=cmex(s);
	
	return grandy[n];
}
int main()
{
	memset(grandy,-1,sizeof(grandy));
	grandy[0]=0;
	int n;
	cin>>n;
	cout<<calclutegrandy(n)<<endl;
	for(int i=0;i<=n;i++)
	cout<<grandy[i]<<" ";
	
}
