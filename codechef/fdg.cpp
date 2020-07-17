#include<bits/stdc++.h>
using namespace std;
bool isprime(int n)
{
	for(int i=2;i*i<=n;i++)
	if(n%i==0)
	return false;
	return true;f
}
int main()
{
	int n;
	cin>>n;
	bool ans=isprime(n);
	cout<<ans<<endl;
}
