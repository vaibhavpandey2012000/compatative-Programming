#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int ans=min((n-1)+m*(m-1),(m-1)+n*(n-1));
	cout<<ans;
}
