#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	if(n%(a+b)==0)
	cout<<"second wins"<<endl;
	else
	cout<<"first wins"<<endl;
}