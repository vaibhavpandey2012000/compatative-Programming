#include<bits/stdc++.h>
using namespace std;
int binary(int n)
{
	int ans=0,p=1;
	while(n)
	{
		int dig=n&1;
		ans=p*dig+ans;
		p=p*10;
		n=n>>1;
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	cout<<binary(n)<<endl;
}