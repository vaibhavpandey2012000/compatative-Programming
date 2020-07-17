#include<bits/stdc++.h>
using namespace std;
vector<int> prime_factor(int n)
{
	vector<int> v;
	for(int i=2;i<n/2;i++)
	{
		while(n%i==0)
		{
			v.push_back(i);
			n=n/i;
		}
	}
	if(n!=1)
	v.push_back(n);
	return v;
}
int main()
{
	int n;
	cin>>n;
	vector<int> v=prime_factor(n);
	long s1=0,s2=0;	
	for(int e:v)
	{
		while(e>0)
		{
			s1+=(e%10);
			e=e/10;
		}
	}
	while(n)
	{
		s2+=(n%10);
		n=n/10;
	}
	if(s1==s2)
	cout<<"1"<<endl;
	else
	cout<<"0"<<endl;
}