#include<bits/stdc++.h>
using namespace std;
int power(int a,int n,int m)
{
	int ans=1;
	while(n)
	{
		if(n&1) ans=(a%m * ans%m)%m,n--;
		else
		a=(a%m*a%m)%m,n=(n>>1);		
	}
	return ans;
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int a,b,m;
		cin>>a>>b>>m;
		int s=power(b,m-2,m);
		cout<<"multiplacative inverse of"<<b<<"is:"<<s<<endl;
		int ans=((a%m)*(s%m))%m;
		cout<<ans<<endl;
	}
}