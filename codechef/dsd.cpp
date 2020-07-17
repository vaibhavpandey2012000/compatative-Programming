#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,p;
	cin>>n>>p;
	for(int k=1;k<=1000;k++)
	{
		if(n-k*p>=k && k>=__builtin_popcount(n-k*p))
		{
			cout<<k<<endl; return 0;
		}
	}
	cout<<-1<<endl;
}
