#include<bits/stdc++.h>
using namespace std;
long gcd(long a,long b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		long m,n;
		cin>>m>>n;
		long p=gcd(m,n);
		//cout<<p<<endl;
		cout<<(m/p*n/p)<<endl;
	}
}
