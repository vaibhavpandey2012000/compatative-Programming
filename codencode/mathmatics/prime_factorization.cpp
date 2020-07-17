
// o(log n)

#include<bits/stdc++.h>
using namespace std;
void prime_factor(int n)
{
	map<int,int>mp;
	for(int i=2;i*i<=n;i++)
	{
		while(n%i==0)
		mp[i]++ ,n=n/i;
	}
	if(n>2)
	mp[n]++;
	for(auto e:mp)
	{
		cout<<e.first<<" "<<e.second<<endl;
	}
}
int main()
{
	int n;
	cin>>n;
	prime_factor(n);
}