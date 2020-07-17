#include<bits/stdc++.h>
using namespace std;
int grandy[100];
int calclutemex(unordered_set<int>s)
{
	int mex=0;
	while(s.find(mex)!=s.end())
	mex++;
	return mex;
}
int calcluategrandy(int n)
{
	if(n==0)
	return 0;
	
	unordered_set<int> s;
	
	for(int i=0;i<n;i++)
		if(grandy[n]==-1){
			int pp=calcluategrandy(i);
			s.insert(pp);
			grandy[i]=pp;
		}
		else{
			s.insert(grandy[i]);	
		}
	return (calclutemex(s));	
}
int main()
{
	memset(grandy,-1,sizeof(grandy));
	int n;
	cin>>n;
	int ans=calcluategrandy(n);
	cout<<ans<<endl;
}
