#include<bits/stdc++.h>
using namespace std;
int GCD(int a,int b)
{
	if(b==0) return a;
	return GCD(b,a%b);
}
int multiplacative_inv(int a,int n,int m)
{
	int ans=1;
	while(n)
	{
		if(n%2==1)
		ans=(ans*a)%m ,n--;
		else
		a=(a*a)%m ,n=n/2;
	}
	return ans;
}
int main()
{
	int tc,a,b,m;
	cin>>tc;
	while(tc--)
	{
		cin>>a>>m;
		if(GCD(a,m)==1)
		cout<<multiplacative_inv(a,m-2,m)<<endl;
		else
		cout<<"Not Possible"<<endl;
	}
}
