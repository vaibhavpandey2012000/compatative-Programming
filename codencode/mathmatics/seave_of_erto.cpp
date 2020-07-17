#include<bits/stdc++.h>
using namespace std;
const int maxN=100000;
bool prime[100001];
void seave()
{
	prime[0]=prime[1]=true;
	for(int i=2;i*i<=maxN;i++)
	{
		if(prime[i]==false)
		{
			for(int j=i*i;j<=maxN;j+=i)
			prime[j]=true;
		}
	}
	for(int i=0;i<=maxN;i++)
	{
		if(!prime[i])
		cout<<i<<" ";
	}
}
int main()
{
	seave();
}