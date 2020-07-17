#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	if(n%(a+b)<a)
	cout<<"first wins"<<endl;
	else
	cout<<"second wins"<<endl;
}