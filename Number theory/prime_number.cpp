#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool prime1(ll n)
{
	for(int i=2;i<n;i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}
bool prime2(ll n)
{
	for(int i=2;i<=n/2;i++)
	{
		if(n%i==0)
			return 0;
	}
	return 1;
}
bool prime3(ll n)
{
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}
int main()
{
	ll n;
	cin>>n;
	bool chack=prime3(n);
	if(chack)
	{
		cout<<"prime"<<endl;
	}
	else
	{
		cout<<"Not prime"<<endl;
	} 
}