#include<bits/stdc++.h>
#define ll long long
using namespace std;
void TOH(int n,string src,string help,string dest)
{
	if(n==0)
	return;
	TOH(n-1,src,dest,help);
	cout<<"move "<<n<<"th disk from "<<src<<" to "<<dest<<endl;
	TOH(n-1,help,src,dest);
}
int main()
{
	int n;
	cin>>n;
	TOH(n,"A","B","C");
}